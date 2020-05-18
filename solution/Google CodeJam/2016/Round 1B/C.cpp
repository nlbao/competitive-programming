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
		filla(d, 0);	d[s] = 1;
		queue<int> q;	q.push(s);
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




const int MAX_N = 1011;


int n;
string a[MAX_N], b[MAX_N];
string la[MAX_N], lb[MAX_N];
set<string> qa, qb;
Flow flow;
int id[3][MAX_N];


int solve() {
	int na=0, nb=0;
	foreach(it, qa) la[++na] = *it;
	foreach(it, qb) lb[++nb] = *it;

	int nC = 2, s = 1, t = 2;
	for (int i = 1; i <= na; ++i) id[0][i] = ++nC;
	for (int i = 1; i <= n; ++i) id[1][i] = nC;
	for (int i = 1; i <= nb; ++i) id[2][i] = ++nC;

	flow.init(nC, s, t);
	for (int i = 1; i <= na; ++i) {
		flow.addEdge(s, id[0][i], 1);
		for (int j = 1; j <= n; ++j)
			if (la[i] == a[j])
				flow.addEdge(id[0][i], id[1][j], 1);
	}
	for (int i = 1; i <= nb; ++i) {
		flow.addEdge(id[2][i], t, 1);
		for (int j = 1; j <= n; ++j)
			if (lb[i] == b[j])
				flow.addEdge(id[1][j], id[2][i], 1);
	}

	int ans = flow.getFlow(), sum = 0;
	foreach(it, flow.e[s]) if (it->c > 0 && it->f < it->c) ++sum;
	// foreach(it, flow.e[t]) if (it->c == 0 && it->f < it->c) ++sum;
	// if (sum == 0) sum = nb - ans;
	sum += nb - ans;
	ans += sum;
	ans = max(ans, na);
	ans = max(ans, nb);
	return n - ans;
}


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	// freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i] >> b[i];
		qa.clear();
		qb.clear();
		for (int i = 1; i <= n; ++i) {
			qa.insert(a[i]);
			qb.insert(b[i]);
		}
		int ans = solve();
		cout << "Case #" << tid << ": " << ans << endl;
	}

	return 0;
}