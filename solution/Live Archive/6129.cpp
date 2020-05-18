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
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


template<class Flow, class Cost>
struct MinCostFlow {
	struct Edge {
		int v, inv;
		Flow c, f;
		Cost w;
		Edge() {};
		Edge(int v, Flow c, Cost w, int inv) : v(v), inv(inv), c(c), f(0), w(w) {}
	};

	static const int MAX_N = 2e5 + 55;
	static const Cost oo = 1e9;
	int n, s, t;
	vector<Edge> e[MAX_N];
	Cost d[MAX_N];
	int parent[MAX_N], pEdge[MAX_N], state[MAX_N];
	deque<int> q;

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		for (int i = 0; i <= n; ++i)
			e[i].clear();
	}

	void addEdge(int u, int v, Flow c, Cost w) {
		int i = e[u].size(), j = e[v].size();
		e[u].push_back(Edge(v, c, w, j));
		e[v].push_back(Edge(u, 0, -w, i));
	}

	bool findPath() {
		for (int i = 1; i <= n; ++i) {
			d[i] = oo;
			state[i] = 0;
			parent[i] = pEdge[i] = -1;
		}
		d[s] = 0;
		while (!q.empty()) q.pop_front();
		q.push_front(s);
		while (!q.empty()) {
			int u = q.front();  q.pop_front();
			state[u] = 2;
			for (int i = 0, sz = (int)e[u].size(); i < sz; ++i)
				if (e[u][i].f < e[u][i].c) {
					int v = e[u][i].v;
					Cost tmp = d[u] + e[u][i].w;
					if (tmp < d[v]) {
						d[v] = tmp;
						parent[v] = u;
						pEdge[v] = i;
						if (state[v] == 0) q.push_back(v);
						else if (state[v] == 2) q.push_front(v);
						state[v] = 1;
					}
				}
		}
		return (parent[t] > -1);
	}

	pair<Flow, Cost> getFlow(Flow flowLimit = oo) {
		Flow flow = 0, cost = 0;
		while (findPath()) {
			Flow add = flowLimit - flow;
			if (add <= 0) break;
			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v], i = pEdge[v];
				add = min(add, e[u][i].c - e[u][i].f);
			}
			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v], i = pEdge[v];
				e[u][i].f += add;
				e[v][e[u][i].inv].f -= add;
				cost += Cost(add) * e[u][i].w;
			}
			flow += add;
		}
		return make_pair(flow, cost);
	}
};


const int MAX_N = 111;


int n;
int id[2][MAX_N], a[2][MAX_N][MAX_N], assign[2][MAX_N];
int finish[MAX_N], cTime[MAX_N];
MinCostFlow<int, int> flow;


int main() {
#ifdef DEBUG
	freopen("6129.in", "r", stdin);
	freopen("6129.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	while (1) {
		cin >> n;
		if (n==0) break;
		fori(x,0,1) fori(i,1,n) fori(j,1,n) cin >> a[x][i][j];
		int nC=2, s=1, t=2, idle=0;
		fori(x,0,1) fori(i,1,n) id[x][i]=++nC;

		// phase 1
		flow.init(nC, s, t);
		fori(i,1,n) {
			flow.addEdge(s, id[0][i], 1, 0);
			flow.addEdge(id[1][i], t, 1, 0);
		}
		fori(i,1,n) fori(j,1,n) flow.addEdge(id[0][i], id[1][j], 1, a[0][i][j]);

		flow.getFlow();
		fori(i,1,n) {
			int u=id[0][i]-2;
			foreach(it, flow.e[id[0][i]]) if (it->v!=s && it->f>0) {
				int v=it->v-n-2;
				assign[0][u]=v;
				finish[v]=cTime[u]=it->w;
				break;
			}
		}

		// phase 2
		flow.init(nC, s, t);
		fori(i,1,n) {
			flow.addEdge(s, id[0][i], 1, 0);
			flow.addEdge(id[1][i], t, 1, 0);
		}
		fori(i,1,n) fori(j,1,n) flow.addEdge(id[0][i], id[1][j], 1, max(cTime[i], finish[j]) + a[1][i][j]);

		flow.getFlow();
		fori(i,1,n) {
			int u=id[0][i]-2;
			foreach(it, flow.e[id[0][i]]) if (it->v!=s && it->f>0) {
				int v=it->v-n-2;
				assign[1][u]=v;
				idle += it->w-a[1][u][v]-cTime[u];
				cTime[u]=it->w;
				break;
			}
		}

		cout << "Case " << ++testid << ":\n";
		fori(i,1,n) cout << "Worker " << i << ": " << assign[0][i] << " " << assign[1][i] << " " << cTime[i] << endl;
		cout << "Total idle time: " << idle << endl;
	}

	return 0;
}