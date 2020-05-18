#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

vector<int> e[maxn];
int n,d[maxn];
vector<ll> val;
ll sum;

void dfs(int u, int p){
    d[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u);
        val.pb(1ll*(n-d[v])*d[v]);
        d[u]+=d[v];
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        val.clear(); sum=0;
        for(int i=0; i<n-1; ++i){
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            sum+=l;
            e[u].pb(v);
            e[v].pb(u);
        }


        dfs(1,-1);
        sort(val.begin(),val.end());

        ll res=0;
        if(sz(val)>0) res+=(sum-n+1)*val[0];
        for(int i=0; i<sz(val); ++i) res+=val[i];

        cout<<res<<endl;
    }

}