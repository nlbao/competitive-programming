#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define MAX
#define EL cout<<endl
#define TI freopen("test.inp","rt",stdin)

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)

int INP,AM;
#define BUFSIZE (1<<10)
char BUF[BUFSIZE+1], *inp=BUF;
#define GETCHAR(INP) {				\
	if(!*inp) {					\
		fread(BUF,1,BUFSIZE,stdin);	\
		inp=BUF;				\
	}						\
	INP=*inp++;					\
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) {					\
    GETCHAR(INP); while(!DIG(INP)) GETCHAR(INP);\
	j=INP-'0'; GETCHAR(INP);				\
	while(DIG(INP)){j=(j<<3)+(j<<1)+(INP-'0');GETCHAR(INP);}	\
}

const int MAXN = 100010;


struct ADJ {int v,n;} ke[200100];
int h[100100], N, Q,cnt;
struct info {int idx,pos;} vertex[100100];
vector<int> path[MAXN];
int dd[MAXN],treesize[MAXN],num[MAXN],mau[MAXN],connect[MAXN],VAL;

struct tournament {
    vector< int > t;

    void resize(int n) { t.resize( 4*n, 0 ); }

    int query(int id, int l, int r, int u, int v)
    {
        if(u>r || l>v || u>v) return 0;
        if(l==u && r==v) return t[id];
        int m=(l+r)>>1;
        int p = query( id<<1, l, m, u, min(m,v));
        if (p) return p; else        return  query( (id<<1)+1, m+1, r, max(m+1,u), v);
    }

    void update( int id,int l,int r,int p)
    {
        if (l==r) {t[id]=VAL;return;}

        int m=(l+r)>>1;
        if (p<=m) update(id<<1,l,m,p); else update((id<<1)+1,m+1,r,p);
        if (t[id<<1]) t[id]=t[id<<1]; else t[id]=t[(id<<1)+1];
    }
};

tournament T[MAXN];

void dfs( int u)
{
    int v;
    dd[u]=1,treesize[u]=1;
    for(int i = h[u];i;i=ke[i].n)
       if (!dd[v=ke[i].v])           dfs(v), treesize[u] += treesize[v];
}

//heavy_light( 1, 0, -1, 0 );
void heavy_light( int u, int dad, int p ) {

    if( p == 0 ) cnt++,path[cnt].clear(),num[cnt]=0;
    path[cnt].push_back(u);        vertex[u]=(info){cnt,++num[cnt]}; //vi tri cua no trong path cnt

    int mx = 0; //nhan cay con co nhieu nut nhat

    for( int i = h[u];i; i=ke[i].n )
        if( ke[i].v != dad && treesize[ke[i].v] > treesize[mx])        mx = ke[i].v;

    if( mx )         heavy_light( mx, u, 1 );

    for( int i = h[u];i; i=ke[i].n )
        if( ke[i].v!= dad && ke[i].v != mx )
            connect[ke[i].v]=u,heavy_light( ke[i].v, u, 0 );
}
int u,v,M,vv,p,k,t,q[MAXN];

void xuly()
{
    GN(N);GN(Q);
    FORD(i,N-1,1)
    {
        GN(u);GN(v);
        ke[++M]=(ADJ){v,h[u]};h[u]=M;
        ke[++M]=(ADJ){u,h[v]};h[v]=M;
    }

    dfs(1);    FOR(i,1,N) mau[i]=0;
    cnt = 0;    heavy_light( 1, 0, 0 );
//    FOR(i,1,cnt)    {        cout<<i<<":";for(int j=0;j<path[i].size();j++) cout<<path[i][j]<<" ";EL;    }
    FOR(i,1,cnt)    FORD(j,num[i]-1,1) connect[path[i][j]]=connect[path[i][0]];
//    FOR(i,1,N) cout<<connect[i]<<" ";  EL;
    FOR(i,1,cnt)        T[i].resize(num[i]);
    FOR(i,1,Q)
    {
        GN(u);GN(v);
        if (u==0)
        {
                  k=vertex[v].idx,mau[v]=1-mau[v];
                  if (mau[v]) VAL=vertex[v].pos; else VAL=0;
                  T[k].update(1,1,num[k],vertex[v].pos);
        }
        else
        {
             vv=v,v=t=0;
             while (vv) q[++t]=vv,vv=connect[vv];
             FORD(j,t,1)
             {

                 k=vertex[q[j]].idx,p=vertex[q[j]].pos;
                 v=T[k].query(1,1,num[k],1,p);
                 if (v) {printf("%d\n",path[k][v-1]);break;}
             }
             if (!v) printf("-1\n");
        }
    }


}

int main() {

    xuly();

    return 0;
}