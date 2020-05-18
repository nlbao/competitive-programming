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


const int MAX_N = 555;


int m, n[2], T, id[4][MAX_N];
vector<int> h[2];
Flow flow;


bool check(int nA, int nB, vector<int> hA, vector<int> hB) {
	int nC=2, s=1, t=2;
	fori(i,1,nA) id[0][i]=++nC;
	fori(i,1,nA) id[1][i]=++nC;
	fori(i,1,nB) id[2][i]=++nC;
	fori(i,1,nB) id[3][i]=++nC;
	flow.init(nC, s, t);

	fori(i,1,m) flow.addEdge(s, id[0][i], 1);
	fori(i,nB-m+1,nB) flow.addEdge(id[3][i], t, 1);
	fori(i,1,nA) flow.addEdge(id[0][i], id[1][i], 1);
	fori(i,1,nB) flow.addEdge(id[2][i], id[3][i], 1);

	fori(i,1,nA) fori(j,1,nB) if (abs(hA[i]-hB[j])<T) {
		flow.addEdge(id[1][i], id[2][j], 1);
		flow.addEdge(id[3][j], id[0][i], 1);
	}
	return flow.getFlow()==m;
}


int main() {
#ifdef DEBUG
	freopen("100733I.in", "r", stdin);
	freopen("100733I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> m >> n[0] >> n[1] >> T;
	fori(i,0,2) {
		h[i].clear();
		fori(j,1,n[i]) {
			int x;
			cin >> x;
			h[i].pb(x);
		}
		foreach(it, h[i]) *it = -*it;
		sort(h[i].begin(), h[i].end());
		foreach(it, h[i]) *it = -*it;
		h[i].insert(h[i].begin(), 0);
	}
	if (check(n[0], n[1], h[0], h[1]) || check(n[1], n[0], h[1], h[0]))
		cout << "S\n";
	else
		cout << "N\n";

	return 0;
}