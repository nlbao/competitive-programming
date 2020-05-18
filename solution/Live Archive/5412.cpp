#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;


int n, m, nTime;
int num[MAX_N], low[MAX_N], p[MAX_N], pre[MAX_N];
bool ok[MAX_N];
vector<pii> e[MAX_N], ans[MAX_N];


void dfs(int u) {
	num[u]=low[u]=++nTime;
	foreach(it, e[u]) {
		int v=it->sc, id=it->fr;
		if (!ok[id]) continue;
		ok[id]=0;
		if (p[v])
			low[u]=min(low[u], num[v]);
		else {
			pre[v]=id;
			p[v]=u;
			dfs(v);
			low[u]=min(low[u], low[v]);
		}
		ans[id].pb(mp(u, v));
	}
	if (p[u]>0 && low[u]>=num[u]) {	// is bridge
		int id=pre[u], v=p[u];
		ans[id].pb(mp(u, v));
	}
}


int main() {
#ifdef DEBUG
	freopen("5412.in", "r", stdin);
	freopen("5412.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	while (true) {
		cin >> n >> m;
		if (n==0) break;
		fori(i,1,n) e[i].clear();
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(mp(i, y));
			e[y].pb(mp(i, x));
			ans[i].clear();
			ok[i]=1;
		}
		nTime=0;
		fori(i,1,n) p[i]=0;
		p[1]=-1;
		dfs(1);

		cout << ++testid << endl << endl;
		fori(i,1,m) foreach(it, ans[i]) cout << it->fr << " " << it->sc << endl;
		cout << "#" << endl;
	}

	return 0;
}