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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }

const int MAX_N = 1e5+5;
const int MAX_M = 1e5+5;
const int oo = 1e9;


int n, m, nCircle;
int target[MAX_N], circleID[MAX_N], h[MAX_N];
pii par[MAX_N];
int inCircle[MAX_M];
bool visited[MAX_M], isInf[MAX_M];
vector<pii> e[MAX_N];


void markInf(int i) {
	if (i < 0 || i >= oo) return;
	isInf[i] = true;
}

void update_edges(int u, int v, int cid) {
	while (h[u] > h[v]) {
		int eid = par[u].second;
		if (inCircle[eid] < 0)
			inCircle[eid] = cid;
		else if (inCircle[eid] != cid) {
			markInf(inCircle[eid]);
			markInf(cid);
			inCircle[eid] = oo;
		}
		u = par[u].first;
	}
}

void dfs(int u) {
	// cout << u << endl;
	foreach(it, e[u]) {
		int v = it->first, eid = it->second;
		if (h[v] >= oo) {
			h[v] = h[u] + 1;
			visited[eid] = true;
			par[v] = pii(u, eid);
			dfs(v);
		}
		else if (!visited[eid]) {
			visited[eid] = true;
			if (h[v] > h[u]) continue; // this edge is processed
			inCircle[eid] = nCircle;
			update_edges(u, v, nCircle);
			// update_edge(eid, nCircle);
			nCircle += 1;
		}
	}
}


bool isInCircle(int i) {
	if (inCircle[i] < 0 || inCircle[i] >= oo) return false;
	return !isInf[inCircle[i]];
}


int main() {
#ifdef DEBUG
	freopen("962F.in", "r", stdin);
	freopen("962F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(mp(v, i));
		e[v].push_back(mp(u, i));
		inCircle[i] = -1;
		visited[i] = false;
	}

	nCircle = 0;
	for (int i = 0; i < MAX_M; ++i)
		isInf[i] = false;
	for (int i = 1; i <= n; ++i)
		h[i] = oo;
	for (int i = 1; i <= n; ++i)
		if (h[i] >= oo) {
			h[i] = 0;
			dfs(i);
		}

	int nAns = 0;
	for (int i = 1; i <= m; ++i)
		if (isInCircle(i)) ++nAns;
	cout << nAns << endl;
	for (int i = 1; i <= m; ++i)
		if (isInCircle(i))
			cout << i << " ";

	return 0;
}