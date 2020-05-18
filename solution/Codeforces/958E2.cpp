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

	static const int MAX_K = 5001;
	static const int MAX_N = 2*(2*MAX_K+100) + 100;
	static const Cost oo = 1e9 + 99;
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


const int MAX_N = 5e5+55;

int N, K;
int a[MAX_N], id[MAX_N];
MinCostFlow<int, int> minCostFlow;
bool isIn[MAX_N], isOut[MAX_N];
vector<pii> b;
vector<pair<pii, int> > edges;


int solve() {
	int s = 1, t0 = 2, t = 3, nNode = 3;
	for (int i = 0; i < N; ++i)
		isIn[i] = isOut[i] = false;

	int limit = min(2*K+100, (int)b.size());
	edges.clear();
	for (int i = 0; i < limit; ++i) {
		int cost = b[i].first, u = b[i].second;
		int v = u+1;
		if (u&1) swap(u, v);
		isIn[u] = true;
		isOut[v] = true;
		edges.push_back(make_pair(pii(u, v), cost));
	}

	for (int i = 0; i < N; ++i)
		if (isIn[i] || isOut[i])
			id[i] = ++nNode;
	minCostFlow.init(nNode, s, t);
	for (int i = 0; i < N; ++i) {
		if (isIn[i]) minCostFlow.addEdge(s, id[i], 1, 0);
		if (isOut[i]) minCostFlow.addEdge(id[i], t0, 1, 0);
	}
	foreach(it, edges) {
		int u = it->first.first, v = it->first.second;
		int cost = it->second;
		minCostFlow.addEdge(id[u], id[v], 1, cost);
	}
	minCostFlow.addEdge(t0, t, K, 0);
	pair<int, int> flow = minCostFlow.getFlow();
	return flow.second;
}


int main() {
#ifdef DEBUG
	freopen("958E2.in", "r", stdin);
	freopen("958E2.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> K >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a+N);
	for (int i = 0; i < N-1; ++i)
		b.push_back(pii(a[i+1]-a[i], i));
	sort(b.begin(), b.end());
	cout << solve() << endl;

	return 0;
}