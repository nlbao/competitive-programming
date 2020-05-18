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


const int MAX_N = 1e5+55;


int n, nTime, m, nQ;
int num[MAX_N], low[MAX_N], p[MAX_N], len[MAX_N];
vector< vector<int> > bc;
vector<int> e[MAX_N];
stack<int> stk;
unordered_set<int> s[MAX_N];
map<pii, bool> qans;


void dfs(int u) {
	num[u]=low[u]=++nTime;
	if (e[u].empty()) {
		bc.pb(vector<int>(1, u));
		return;
	}
	stk.push(u);
	foreach(it, e[u]) {
		int v=*it;
		if (v==p[u]) continue;
		if (p[v]) {
			low[u]=min(low[u], num[v]);
			continue;
		}
		p[v]=u;
		dfs(v);
		low[u]=min(low[u], low[v]);
		if (p[u]<0 || low[v]>=num[u]) {
			bc.pb(vector<int>(1, u));
			int x=-1;
			while (x!=v) {
				x=stk.top();	stk.pop();
				bc.back().pb(x);
			}
		}
	}
}


inline bool check(int u, int v) {
	if (u>v) swap(u, v);
	if (len[u]>len[v]) swap(u, v);
	pii t(u, v);
	if (has(qans, t)) return qans[t];
	foreach(it, s[u]) if (has(s[v], *it)) return qans[t]=1;
	return qans[t]=0;
}


int main() {
#ifdef DEBUG
	freopen("special-pairs.in", "r", stdin);
	freopen("special-pairs.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> nQ;
	fori(i,1,m) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}

	nTime=0;
	filla(p, 0);
	fori(i,1,n) if (p[i]==0) {
		p[i]=-1;
		dfs(i);
	}
	m=0;
	for (int i=0; i < sz(bc); ++i) {
		if (sz(bc[i]) < 3) continue;
		++m;
		foreach(it, bc[i]) s[*it].insert(m);
	}
	fori(i,1,n) len[i]=sz(s[i]);

	while (nQ--) {
		int x, y;
		cin >> x >> y;
		if (check(x, y)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}