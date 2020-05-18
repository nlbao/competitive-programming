#include <stdio.h>
#include <stdlib.h>


int main()  {

    int N,d,i,j,k,e,u,w,maxi,pos,countpath,pow2,s,s2,L,c,x,queries,add,mini,I,count,node;
    int *pairs,*numedges,**edges,*found,*depth,*numchild,*parent,*pathid,*lengthpath,*positioninpath;
    int ***seq,*color,*heavy,*first,*last,**ord,*firstblack;
    int startlist,endlist,endlist2,pending,deep,*A,op=0,POS=0,len,digit[8];
    
    char input[8192];
    char output[8192];
    fread(input,sizeof(char),sizeof(input),stdin);
    
    // scanf("%d%d",&N,&queries);
          N=0;
          while((d=input[POS])!=' ')  {
                N=10*N+(d-'0'),POS++;
                if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          }
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          queries=0;
          while((d=input[POS])!='\n')  {
                queries=10*queries+(d-'0'),POS++;
                if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          }
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;

    pairs=(int*)(malloc)(2*(N+1)*sizeof(int));
    numedges=(int*)(malloc)((N+1)*sizeof(int));
    edges=(int**)(malloc)((N+1)*sizeof(int*));
    found=(int*)(malloc)((N+1)*sizeof(int));
    depth=(int*)(malloc)((N+1)*sizeof(int));
    numchild=(int*)(malloc)((N+1)*sizeof(int));
    parent=(int*)(malloc)((N+1)*sizeof(int));
    pathid=(int*)(malloc)((N+1)*sizeof(int));
    lengthpath=(int*)(malloc)((N+1)*sizeof(int));
    positioninpath=(int*)(malloc)((N+1)*sizeof(int));
    color=(int*)(malloc)((N+1)*sizeof(int));
    heavy=(int*)(malloc)((N+1)*sizeof(int));
    first=(int*)(malloc)((N+1)*sizeof(int));
    last=(int*)(malloc)((N+1)*sizeof(int));
    firstblack=(int*)(malloc)((N+1)*sizeof(int));
    A=(int*)(malloc)((N+1)*sizeof(int));
    
    for(i=1;i<=N;i++)  numedges[i]=0;
    for(i=0;i<N-1;i++)  {
        // scanf("%d%d",&u,&w);
          u=0;
          while((d=input[POS])!=' ')  {
                u=10*u+(d-'0'),POS++;
                if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          }
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          w=0;
          while((d=input[POS])!='\n')  {
                w=10*w+(d-'0'),POS++;
                if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          }
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;

        numedges[u]++;
        numedges[w]++;
        pairs[2*i]=u;
        pairs[2*i+1]=w;
    }
    for(i=1;i<=N;i++)  edges[i]=(int*)(malloc)(numedges[i]*sizeof(int));
    
    for(i=1;i<=N;i++)  numedges[i]=0;
    for(i=0;i<N-1;i++)  {
        u=pairs[2*i];
        w=pairs[2*i+1];
        edges[u][numedges[u]]=w;
        numedges[u]++;
        edges[w][numedges[w]]=u;
        numedges[w]++;
    }
    depth[1]=0;
    parent[1]=0;
    deep=0;
    startlist=0;
    endlist=0;
    pending=1;
    A[0]=1;
    for(i=1;i<=N;i++)  found[i]=0;
    found[1]=1;
    while(pending>0)  {
          deep++;
          endlist2=endlist;
          for(i=startlist;i<=endlist;i++)  {
              u=A[i];
              e=numedges[u];
              for(j=0;j<e;j++)  {
                  w=edges[u][j];
                  if(found[w]==0)  {
                     found[w]=1;
                     depth[w]=deep;
                     parent[w]=u;
                     endlist2++;
                     A[endlist2]=w;
                  }
              }
          }
          startlist=endlist+1;
          endlist=endlist2;
          pending=endlist-startlist+1;
    }
    
    for(i=1;i<=N;i++)  numchild[i]=0;
    for(i=N-1;i>0;i--)  {
        w=A[i];
        u=parent[w];
        numchild[u]+=1+numchild[w];
    }
    
    //for(i=1;i<=N;i++)  printf("depth[%d]=%d\n",i,depth[i]);
    //for(i=1;i<=N;i++)  printf("numchild[%d]=%d\n",i,numchild[i]);
    
    for(i=0;i<=N;i++)  pathid[i]=-1;
    countpath=0;
    for(i=0;i<N-1;i++)  {
        u=A[i];
        d=depth[u];
        e=numedges[u];
        maxi=-1;
        for(j=0;j<e;j++)  {
            w=edges[u][j];
            if(depth[w]>d)  {
               if(numchild[w]>maxi)  maxi=numchild[w],pos=w;
            }
        }
        if(maxi!=-1)  {
           if(pathid[u]!=-1)  {
              pathid[pos]=pathid[u];
              lengthpath[pathid[u]]++;
              positioninpath[pos]=lengthpath[pathid[u]];
              last[pathid[u]]=pos;
           }
           else {
              pathid[pos]=countpath;
              pathid[u]=countpath;
              first[countpath]=u;
              last[countpath]=pos;
              positioninpath[u]=0;
              positioninpath[pos]=1;
              lengthpath[countpath]=1;
              countpath++;
           }
        }
    }
    //for(i=0;i<=N;i++)  printf("depth[%d]=%d\n",i,depth[i]);
    //for(i=0;i<=N;i++)  printf("pathid[%d]=%d\n",i,pathid[i]);
    //for(i=0;i<=N;i++)  printf("pospath[%d]=%d\n",i,positioninpath[i]);
    //for(i=0;i<=N;i++)  printf("parent[%d]=%d\n",i,parent[i]);
    //for(i=0;i<countpath;i++)  printf("lengthpath[%d]=%d\n",i,lengthpath[i]);
    
    ord=(int**)(malloc)(countpath*sizeof(int*));
    for(i=0;i<countpath;i++)  {
        ord[i]=(int*)(malloc)((lengthpath[i]+1)*sizeof(int));
    }
    for(i=0;i<countpath;i++)  {
        u=last[i];
        L=lengthpath[i];
        for(j=L;j>=0;j--)  {
            ord[i][j]=u;
            u=parent[u];
        }
    }
    //for(i=0;i<countpath;i++)
    //    for(j=0;j<=lengthpath[i];j++)  printf("ord[%d][%d]=%d\n",i,j,ord[i][j]);
    
    seq=(int***)(malloc)(countpath*sizeof(int**));
    
    for(i=0;i<countpath;i++)  {
        pow2=1;
        L=lengthpath[i];
        e=0;
        while(2*pow2-1<=L)  pow2*=2,e++;
        seq[i]=(int**)(malloc)((e+1)*sizeof(int*));
        pow2=1;
        for(j=0;j<=e;j++)  {
            c=(L+1)/pow2;
            seq[i][j]=(int*)(malloc)(c*sizeof(int));
            for(k=0;k<c;k++)  seq[i][j][k]=0;
            pow2*=2;
        }
    }
    
    for(i=0;i<=N;i++)  color[i]=0;
    for(i=0;i<countpath;i++)  heavy[i]=0;
    for(i=0;i<countpath;i++)  firstblack[i]=N+1;
    while(queries--)  {
          // scanf("%d%d",&c,&x);
          c=input[POS]-'0',POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          x=0;
          while((d=input[POS])!='\n')  {
                x=10*x+(d-'0'),POS++;
                if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          }
          POS++;
          if(POS==8192)  fread(input,sizeof(char),sizeof(input),stdin),POS=0;
          
          if(c==0)  {
             add=1-2*color[x];
             color[x]+=add;
             if(pathid[x]!=-1)  {
                i=pathid[x];
                heavy[i]+=add;
                pos=positioninpath[x];
                L=lengthpath[i];
                pow2=1;
                e=0;
                while(1)  {
                      seq[i][e][pos>>e]+=add;
                      e++;
                      pow2<<=1;
                      if(pow2>L+1)  break;
                }
                if(heavy[i]>0)  {
                   s=-1;
                   e--;
                   pow2>>=1;
                   for(j=e;j>=0;j--)  {
                       s2=s+pow2;
                       if((s2<=L)&&(seq[i][j][s2>>j]==0))  s=s2;
                       pow2>>=1;
                   }
                   firstblack[i]=s+1;
                }
                else firstblack[i]=N+1;
             }
          }
          else {
             mini=N+1;
             node=x;
             count=0;
             while(node!=0)  {
                   if(pathid[node]==-1)  {
                      if(color[node]==1)  mini=node;
                      node=parent[node];
                   }
                   else {
                      pairs[2*count]=pathid[node];
                      pairs[2*count+1]=positioninpath[node];
                      count++;
                      node=parent[first[pathid[node]]];
                   }
             }
             // printf("mini=%d,count=%d\n",mini,count);
             for(I=0;I<count;I++)  {
                 i=pairs[2*I];
                 pos=pairs[2*I+1];
                 if((heavy[i]>0)&&(firstblack[i]<=pos))  {
                     u=ord[i][firstblack[i]];
                     if((mini==N+1)||(depth[mini]>depth[u]))  mini=u;
                 }
             }
             if(mini==N+1)  output[op]='-',output[op+1]='1',output[op+2]='\n',op+=3; // printf("-1\n");
             else  {
             // printf("%d\n",mini);
             u=mini,len=0;
             while(u)  digit[len]=u%10+'0',u/=10,len++;
             len--,op+=len;
             for(u=0;u<=len;u++)  output[op-u]=digit[u];
             output[op+1]='\n',op+=2;
             if(op>8000)  fwrite(output,sizeof(char),op,stdout),op=0;   
             }          
    }}
    fwrite(output,sizeof(char),op,stdout);
    return 0;
}