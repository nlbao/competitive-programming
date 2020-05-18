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


void update(int u, int target_parent, int cid) {
	if (cid < 0 || target_parent < 0 || h[target_parent] >= h[u]) return;
	if (circleID[u] < 0) {
		circleID[u] = cid;
		target[u] = target_parent;
	}
	else {
		if (circleID[u] != cid) {
			markInf(circleID[u]);
			markInf(cid);
			circleID[u] = oo;
		}
		if (h[target_parent] <= h[target[u]])
			target[u] = target_parent;
	}
}


void update_edge(int i, int cid) {
	if (cid < 0) return;
	if (inCircle[i] < 0)
		inCircle[i] = cid;
	else if (inCircle[i] != cid) {
		markInf(inCircle[i]);
		markInf(cid);
		inCircle[i] = oo;
	}
}


void dfs(int u) {
	target[u] = -1;
	circleID[u] = -1;
	int p = par[u].first;
	int p_eid = par[u].second;
	foreach(it, e[u]) {
		int v = it->first, eid = it->second;
		if (h[v] >= oo) {
			h[v] = h[u] + 1;
			visited[eid] = true;
			par[v] = pii(u, eid);
			dfs(v);
			update(u, target[v], circleID[v]);
			if (target[v] > 0 && h[target[v]] <= h[u])
				update_edge(eid, circleID[v]);
			if (p > 0 && target[v] > 0 && h[target[v]] <= h[p])
				update_edge(p_eid, inCircle[eid]);
		}
		else if (!visited[eid]) {
			visited[eid] = true;
			if (h[v] > h[u]) continue; // this edge is processed
			update(u, v, nCircle);
			update_edge(eid, nCircle);
			update_edge(p_eid, nCircle);
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
			par[i] = pii(-1, -1);
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