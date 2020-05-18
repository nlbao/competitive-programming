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


struct Flow {
	struct Edge {
		int v, c, f, inv;
		Edge() {}
		Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
	};

	static const int MAX_N = 2e5 + 55;
	static const int oo = 1e9;
	int n, s, t;
	vector<Edge> e[MAX_N];
	int d[MAX_N], pos[MAX_N], sz[MAX_N];
	queue<int> q;

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		filla(sz, 0);
		for (int i = 0; i <= n; ++i)
			e[i].clear();
	}

	void addEdge(int u, int v, int c) {
		e[u].push_back(Edge(v, c, sz[v]++));
		e[v].push_back(Edge(u, 0, sz[u]++));
	}

	bool bfs() {
		filla(d, 0);
		d[s] = 1;
		while (!q.empty()) q.pop();
		q.push(s);
		while (!q.empty()) {
			int u = q.front();  q.pop();
			if (u == t) return true;
			foreach(it, e[u]) {
				int v = it->v;
				if (!d[v] && it->f < it->c) {
					d[v] = d[u]+1;
					q.push(v);
				}
			}
		}
		return false;
	}

	int dfs(int u, int flow) {
		if (u == t || flow == 0) return flow;
		for (; pos[u] < sz[u]; ++pos[u]) {
			int i = pos[u], v = e[u][i].v;
			if (d[v] == d[u]+1) {
				int delta = dfs(v, min(flow, e[u][i].c - e[u][i].f));
				if (delta) {
					e[u][i].f += delta;
					e[v][e[u][i].inv].f -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	int getFlow() {
		int flow = 0;
		while (bfs()) {
			filla(pos, 0);
			for (int delta = 1; delta > 0; )
				flow += (delta = dfs(s, oo));
		}
		return flow;
	}
};


const int MAX_N = 505;


int nP, nS, C, m;
int id[2][MAX_N];
Flow flow;


int main() {
#ifdef DEBUG
	freopen("6851.in", "r", stdin);
	freopen("6851.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> nP >> nS >> C >> m;
		int nC=2, s=1, t=2;
		fori(i,1,nP) id[0][i]=++nC;
		fori(i,1,nS) id[1][i]=++nC;
		flow.init(nC, s, t);
		fori(i,1,nP) flow.addEdge(s, id[0][i], 1);
		fori(i,1,nS) flow.addEdge(id[1][i], t, C);
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			flow.addEdge(id[0][x], id[1][y], 1);
		}
		cout << flow.getFlow() << endl;
	}

	return 0;
}