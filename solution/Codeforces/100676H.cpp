#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


struct edge {
	int v, c, i;
	edge() 	{}
	edge(int v, int c, int i) : v(v), c(c), i(i) {}
};


const int MAX_N = 2e5+5;
const ll oo = 1e18;


int n, m, nTime, nC, ansU;
ll ansF, g[MAX_N], f[MAX_N], l[MAX_N], r[MAX_N];
int num[MAX_N], low[MAX_N], p[MAX_N], id[MAX_N], c[MAX_N];
bool ok[MAX_N];
vector<pii> e2[MAX_N];
vector<edge> e[MAX_N];
stack<int> stk;
pii a[MAX_N];


void dfs_0(int u) {
	num[u]=low[u]=++nTime;
	stk.push(u);
	foreach(it, e[u]) {
		if (!ok[it->i]) continue;
		ok[it->i]=0;
		int v=it->v;
		if (num[v]) low[u]=min(low[u], num[v]);
		else {
			p[v]=u;
			dfs_0(v);
			low[u]=min(low[u], low[v]);
		}
	}
	if (p[u]<0 || low[u]>=num[u]) {
		id[++nC]=u;
		int v=-1;
		while (v!=u) {
			v=stk.top();	stk.pop();
			c[v]=nC;
			id[nC]=min(id[nC], v);
		}
	}
}


void dfs_1(int u) {
	f[u]=0;
	foreach(it, e2[u]) {
		int v=it->fr;
		if (p[v]) continue;
		p[v]=u;
		dfs_1(v);
		f[u]=max(f[u], f[v]+it->sc);
	}
}


void dfs_2(int u) {
	ll t=max(f[u], g[u]);
	if (t<ansF || (t==ansF && id[u]<ansU)) {
		ansF=t;
		ansU=id[u];
	}

	int m=0;
	foreach(it, e2[u]) {
		int v=it->fr;
		if (p[v]!=u) continue;
		a[++m]=*it;
		g[v]=g[u]+it->sc;
	}
	l[0]=0;
	fori(i,1,m) l[i]=max(l[i-1], f[a[i].fr]+a[i].sc);
	r[m+1]=0;
	ford(i,m,1) r[i]=max(r[i+1], f[a[i].fr]+a[i].sc);
	fori(i,1,m) {
		int v=a[i].fr;
		g[v]=max(g[v], max(l[i-1], r[i+1])+a[i].sc);
	}

	foreach(it, e2[u]) {
		int v=it->fr;
		if (p[v]==u) dfs_2(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("100676H.in", "r", stdin);
	freopen("100676H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) e[i].clear();
		fori(i,1,m) {
			int x, y, c;
			cin >> x >> y >> c;
			e[x].pb(edge(y, c, i));
			e[y].pb(edge(x, c, i));
			ok[i]=1;
		}
		nC=nTime=0;
		filla(num, 0);
		p[1]=-1;
		dfs_0(1);

		fori(i,1,nC) e2[i].clear();
		fori(u,1,n) {
			foreach(it, e[u]) {
				int v=it->v;
				if (c[u]==c[v]) continue;
				e2[c[u]].pb(mp(c[v], it->c));
			}
		}

		ansU=-1, ansF=oo;
		filla(p, 0);
		p[1]=-1;
		dfs_1(1);
		g[1]=0;
		dfs_2(1);
		cout << ansU << " " << ansF << endl;
	}

	return 0;
}