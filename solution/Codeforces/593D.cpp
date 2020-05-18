// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


struct Query {
	int type, a, b, y, p, c;
	Query() {}
	Query(int t, int a, int b, int y) : type(t), a(a), b(b), y(y) {}
	Query(int t, int p, int c) : type(t), p(p), c(c) {}
};


namespace HLD {
	const int N = 2e5+15;

	int chainNo=0,chainHead[N],chainPos[N],chainInd[N],chainSize[N];

	void hld(int cur) {
	    if(chainHead[chainNo] == -1) chainHead[chainNo]=cur;
	    chainInd[cur] = chainNo;
	    chainPos[cur] = chainSize[chainNo];
	    chainSize[chainNo]++;
	    int ind = -1,mai = -1;
	    for(int i = 0; i < adj[cur].sz; i++) if(subsize[ adj[cur][i] ] > mai) {
	        mai = subsize[ adj[cur][i] ];
	        ind = i;
	    }
	    if(ind >= 0) hld( adj[cur][ind] );
	    for(int i = 0; i < adj[cur].sz; i++) {
	        if(i != ind) {
	            chainNo++;
	            hld( adj[cur][i] );
	        }
	    }
	}

	int query(int u, int v) {
	    int lca = LCA(u, v);
	    return max( query_up(u, lca), query_up(v, lca) );
	}

	int query_up(int u, int v) {
	    int uchain, vchain = chainInd[v], ans = -1;
	    while(1) {
	        if(uchain == vchain) {
	            int cur = query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
	            if( cur > ans ) ans = cur;
	            break;
	        }
	        int cur = query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
	        if( cur > ans ) ans = cur;
	        u = chainHead[uchain];
	        u = parent(u);
	    }
	    return ans;
	}
};


int main() {
#ifdef DEBUG
	freopen("593D.in", "r", stdin);
	freopen("593D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	// cin >> n >> nQ;
	// fori(i,1,n-1) {
	// 	int x, y;
	// 	ll c;
	// 	cin >> x >> y >> c;
	// 	e[x].pb(mp(c, y));
	// 	e[y].pb(mp(c, x));
	// }



	return 0;
}