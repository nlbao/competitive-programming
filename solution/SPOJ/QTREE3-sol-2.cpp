//Heavy-Light Decomposition
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define ROOT 1
#define ran 100010
#define isdigit(x) (x>='0' && x<='9')
int n,q,start[ran],next[ran*2],vert[ran*2];
bool f[ran];

int size[ran],fat[ran],dep[ran],son[ran],ord[ran];
int path_num;
int num[ran],pos[ran];//the id of the Heavy Path each node belongs to & the postion of the node in the Heavy Path
int len[ran];//the length of each Heavy Path
int first[ran];//the id of the first node in each Heavy Path
int sbst[ran],key[ran];

void bfs()
{
    int op,cl,i,x,y,p;
    op=0,cl=1;
    ord[0]=ROOT;
    dep[ROOT]=0;
    while(op<cl)
    {
        x=ord[op++];
        for(p=start[x]; p!=0; p=next[p])
        {
            y=vert[p];
            if(y!=fat[x])
            {
                ord[cl++]=y;
                fat[y]=x;
                dep[y]=dep[x]+1;
            }
        }
    }
    //calculate the size of each subtree
    for(i=n-1; i>=0; i--)
    {
        x=ord[i];
        size[x]=1;
        son[x]=-1;
        for(p=start[x]; p!=0; p=next[p])
        {
            y=vert[p];
            if(y!=fat[x])
            {
                size[x]+=size[y];
                if(son[x]==-1 || size[y]>size[son[x]])
                son[x]=y;
            }
        }
    }
    //build Static Binary Search Tree
    path_num=0;
    num[ROOT]=++path_num,pos[ROOT]=++len[path_num],first[path_num]=ROOT;
    for(i=0; i<n; i++)
    {
        x=ord[i];
        for(p=start[x]; p!=0; p=next[p])
        {
            y=vert[p];
            if(y==fat[x])continue;
            if(y==son[x])
            num[y]=num[x],pos[y]=++len[num[x]];
            else
            len[++path_num]=1,num[y]=path_num,pos[y]=1,first[path_num]=y;
        }
    }
    len[0]=-1;
    for(i=1; i<=path_num; i++)
    len[i]+=len[i-1];
}

int MIN(int x,int y)
{
    if(x==0)return y;
    if(y==0)return x;
    return dep[x]<dep[y]?x:y;
}
void ins(int addition,int position,int start,int end,int x)
{
    int mid=(start+end)/2;
    if(position<mid)
    ins(addition,position,start,mid-1,x);
    else
    if(position>mid)
    ins(addition,position,mid+1,end,x);
    else
    key[addition+mid]=x;
    sbst[addition+mid]=MIN(sbst[addition+mid],x);
}
void insert(int x)
{
    int u=len[num[x]-1],l=len[num[x]]-len[num[x]-1],v=pos[x];
    ins(u,v,1,l,x);
}
int calc(int addition,int start,int end)
{
    if(start>end)return 0;
    return sbst[addition+(start+end)/2];
}
void del(int addition,int position,int start,int end)
{
    int mid=(start+end)/2;
    if(position<mid)
    del(addition,position,start,mid-1);
    else
    if(position>mid)
    del(addition,position,mid+1,end);
    else
    key[addition+mid]=0;
    sbst[addition+mid]=MIN(MIN(calc(addition,start,mid-1),calc(addition,mid+1,end)),key[addition+mid]);
}
void erase(int x)
{
    int u=len[num[x]-1],l=len[num[x]]-len[num[x]-1],v=pos[x];
    del(u,v,1,l);
}
int Q(int addition,int position,int start,int end,int x)
{
    int ret=sbst[addition+(start+end)/2];
    if(ret==0 || dep[ret]>dep[x])
    return 0;
    return ret;
}
int query(int x)
{
    int ret=0,u,v,l;
    while(x)
    {
        u=len[num[x]-1],l=len[num[x]]-len[num[x]-1],v=pos[x];
        ret=MIN(ret,Q(u,v,1,l,x));
        x=fat[first[num[x]]];
    }
    if(ret==0)ret=-1;
    return ret;
}

char ans[23000000];
char anst[99];
int buf_len,anst_len;
void PRINT(int x)
{
    if(x==-1)
    {
        ans[buf_len++]='-';
        ans[buf_len++]='1';
        ans[buf_len++]='\n';
        return;
    }
    for(anst_len=0; x; anst_len++,x/=10)
    anst[anst_len]=x%10;
    while(anst_len--)
    ans[buf_len++]=anst[anst_len]+'0';
    ans[buf_len++]='\n';
}

int main()
{
    int i,j,x,y,t;
    char s[99];
//    scanf("%d%d",&n,&q);
    fgets(s,90,stdin);n=q=t=0; for(; isdigit(s[t]); t++)n=n*10+s[t]-'0';
    for(;!isdigit(s[t]); t++); for(; isdigit(s[t]); t++)q=q*10+s[t]-'0';
    for(i=1,j=1; i<n; i++)
    {
//        scanf("%d%d",&x,&y);
        fgets(s,90,stdin);x=y=t=0; for(; isdigit(s[t]); t++)x=x*10+s[t]-'0';
        for(;!isdigit(s[t]); t++); for(; isdigit(s[t]); t++)y=y*10+s[t]-'0';
        vert[j]=y,next[j]=start[x],start[x]=j,j++;
        vert[j]=x,next[j]=start[y],start[y]=j,j++;
    }
    bfs();
    buf_len=0;
    while(q--)
    {
//        scanf("%d%d",&x,&y);
        fgets(s,90,stdin);x=y=t=0; for(; isdigit(s[t]); t++)x=x*10+s[t]-'0';
        for(;!isdigit(s[t]); t++); for(; isdigit(s[t]); t++)y=y*10+s[t]-'0';
        if(x==0)
        {
            if(!f[y])
            insert(y);
            else
            erase(y);
            f[y]=!f[y];
        }
        else
        PRINT(query(y));
    }
    ans[buf_len-1]=0;
    puts(ans);
    return 0;
}