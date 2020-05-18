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


const int MAX_N = 20;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m;
int a[MAX_N][MAX_N], id[2][MAX_N][MAX_N];
MinCostFlow<int, int> flow;


inline int num(char x) {
	if (x=='^') return 0;
	if (x=='>') return 1;
	if (x=='v') return 2;
	return 3;
}


int solve() {
	int nC=2, s=1, t=2;
	fori(i,1,n) fori(j,1,m) {
		id[0][i][j]=++nC;
		id[1][i][j]=++nC;
	}
	flow.init(nC, s, t);
	fori(i,1,n) fori(j,1,m) {
		int uout = id[0][i][j], uin = id[1][i][j];
		flow.addEdge(s, uout, 1, 0);
		flow.addEdge(uin, t, 1, 0);
		fori(k,0,3) {
			int x=i+dx[k], y=j+dy[k];
			if (x<1 || x>n || y<1 || y>m) continue;
			flow.addEdge(uout, id[1][x][y], 1, (k!=a[i][j]));
		}
	}
	pii ans=flow.getFlow();
	if (ans.fr<n*m) return -1;
	return ans.sc;
}


int main() {
#ifdef DEBUG
	freopen("184.in", "r", stdin);
	freopen("184.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) {
			cin >> s;
			fori(j,1,m) a[i][j]=num(s[j-1]);
		}
		cout << "Case #" << testid << ": " << solve() << endl;
	}

	return 0;
}