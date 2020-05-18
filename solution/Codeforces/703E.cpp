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


template<class Flow, class Cost>
struct MinCostFlow {
	struct Edge {
		int v, inv;
		Flow c, f;
		Cost w;
		Edge() {}
		Edge(int v, Flow c, Cost w, int inv) : v(v), inv(inv), c(c), f(0), w(w) {}
	};

	static const int MAX_N = 1e5+55;
	static const Cost oo = 1e18;
	int n, s, t;
	vector<Edge> e[MAX_N];
	Cost d[MAX_N];
	int p[MAX_N], pEdge[MAX_N], state[MAX_N];

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		fori(i,1,n) e[i].clear();
	}

	void addEdge(int u, int v, Flow c, Cost w) {
		int i = sz(e[u]), j = sz(e[v]);
		e[u].pb(Edge(v, c, w, j));
		e[v].pb(Edge(u, 0, -w, i));
	}

	bool findPath() {
		fori(i,1,n) {
			d[i] = oo;
			state[i] = 0;
			p[i] = pEdge[i] = -1;
		}
		d[s] = 0;
		deque<int> q;
		q.push_back(s);
		while (!q.empty()) {
			int u = q.front();		q.pop_front();
			state[u] = 2;
			fori(i, 0, sz(e[u])-1) if (e[u][i].f < e[u][i].c) {
				int v = e[u][i].v;
				Cost tmp = d[u] + e[u][i].w;
				if (tmp >= d[v]) continue;
				d[v] = tmp;
				p[v] = u;	pEdge[v] = i;
				if (state[v] == 0) q.push_back(v);
				else if (state[v] == 2) q.push_front(v);
				state[v] = 1;
			}
		}
		return p[t] > -1;
	}

	pair<Flow, Cost> getFlow(Flow limit = oo) {
		Flow flow = 0;	Cost cost = 0;
		while (findPath()) {
			Flow add = limit-flow;
			if (add <= 0) break;
			for (int v = t; v != s; v = p[v]) {
				int u = p[v], i = pEdge[v];
				add = min(add, e[u][i].c - e[u][i].f);
			}
			flow += add;
			for (int v = t; v != s; v = p[v]) {
				int u = p[v], i = pEdge[v];
				e[u][i].f += add;
				e[v][e[u][i].inv].f -= add;
				cost += Cost(add) * e[u][i].w;
			}
		}
		return mp(flow, cost);
	}
};


const ll COST_0 = 1e15+15;

MinCostFlow<int, ll> flow;


bool solve() {
	int nC = 2, s=1, t=2;
	for (int i = 1; i <= n; ++i) id[0][i] = ++nC;
	for (int i = 1; i <= nP; ++i) id[1][i] = ++nC;
	flow.init(nC, s, t);
	for (int i = 1; i <= n; ++i) {
		flow.addEdge(s, id[0][i], nP, COST_0);
		for (int j = 1; j <= nP; ++j)
			flow.addEdge(id[0][i], id[1][j], 1, a[i]);
	}

	return false;
}


int main() {
#ifdef DEBUG
	freopen("703E.in", "r", stdin);
	freopen("703E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> K;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	nP = 0;
	for (ll d = 2; d*d <= K; ++d) if ((K%d) == 0) {
		p[++nP] = d;
		while ((K%d)==0) K /= d;
	}

	if (!solve()) cout << -1 << endl;

	return 0;
}