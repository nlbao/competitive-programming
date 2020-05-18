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


const int MAX_N = 1e5+5;
const int MAX_C = 2*MAX_N;


int n, nC, nTime, m, nQ;
int num[MAX_N], low[MAX_N], p[MAX_C], c[MAX_N];
vector<int> bc[MAX_C], e[MAX_N], e2[MAX_C];
bool isCut[MAX_N];
stack<int> stk;


void dfs(int u) {	// number of BCCs may > n
	num[u]=low[u]=++nTime;
	if (e[u].empty()) {
		bc[++nC]=vector<int>(1, u);
		return;
	}
	stk.push(u);
	foreach(it, e[u]) {
		int v=*it;
		if (v==p[u]) continue;
		if (p[v]) low[u]=min(low[u], num[v]);
		else {
			p[v]=u;
			dfs(v);
			low[u]=min(low[u], low[v]);
			if (p[u]<0 || low[v]>=num[u]) {
				bc[++nC]=vector<int>(1, u);
				int x=-1;
				while (x!=v) {
					x=stk.top();	stk.pop();
					bc[nC].pb(x);
				}
			}
		}
	}
}


void dfs_2(int u) {
	foreach(it, e2[u]) {
		int v=*it;
		if (v==p[u]) continue;
		p[v]=u;
		dfs_2(v);
	}
}


bool check(int u, int v) {
	int r=-1;
	if (isCut[v]) swap(u, v);
	if (isCut[u] && isCut[v]) {
		u=c[u], v=c[v];
		if (p[u]==p[v]) r=p[u];
		else if (p[p[u]]==v) r=p[u];
		else if (p[p[v]]==u) r=p[v];
	}
	else if (isCut[u]) {
		u=c[u], v=c[v];
		if (p[u]==v || p[v]==u) r=v;
	}
	else if (c[u]==c[v]) r=c[u];
	return r>0 && sz(bc[r])>2;
}


int main() {
#ifdef DEBUG
	freopen("special-pairs.in", "r", stdin);
	freopen("special-pairs.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	// input
	cin >> n >> m >> nQ;
	fori(i,1,m) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}

	// find BCCs
	nTime=0;
	filla(p, 0);
	fori(i,1,n) if (!p[i]) {
		p[i]=-1;
		dfs(i);
	}

	// find cut-vertices
	filla(c, 0);
	filla(isCut, 0);
	fori(i,1,nC) foreach(it, bc[i]) {
		int u=*it;
		if (c[u]) isCut[u]=1;
		else c[u]=i;
	}

	// create edges of BC-tree
	m=nC;
	fori(i,1,n) if (isCut[i]) {
		c[i]=++nC;
		bc[nC]=vector<int>(1,i);
	}
	fori(i,1,m) foreach(it, bc[i]) {
		int u=*it;
		if (isCut[u]) {
			e2[i].pb(c[u]);
			e2[c[u]].pb(i);
		}
	}

	// build BC-tree
	filla(p, 0);
	fori(i,1,nC) if (!p[i]) {
		p[i]=i;
		dfs_2(i);
	}

	// answer queries
	while (nQ--) {
		int x, y;
		cin >> x >> y;
		if (check(x,y)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}