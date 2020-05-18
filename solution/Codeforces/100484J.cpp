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
		Edge() {}
		Edge(int v, Flow c, Cost w, int inv) : v(v), inv(inv), c(c), f(0), w(w) {}
	};

	static const int MAX_N = 1e5+55;
	static const Cost oo = 1e9;
	int n, s, t;
	vector<Edge> e[MAX_N];
	Cost d[MAX_N];
	int p[MAX_N], pEdge[MAX_N], state[MAX_N];

	void init(int nn, int ss, int tt) {
		n = nn, s = ss, t = tt;
		fori(i,0,n) e[i].clear();
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


const int MAX_N = 111;
const int MAX_C = sqr(MAX_N);
const int oo = 1e9;

int n, nCell;
int a[MAX_N], val[MAX_N], b[MAX_N], len[MAX_N], id[MAX_N][MAX_N];
int d[MAX_C];
vector<int> e[MAX_C];
MinCostFlow<int, int> flow;


inline vector<string> parse(const string &s, char ch) {
	vector<string> a;	stringstream ss(s);		string x;
	while (getline(ss, x, ch)) a.pb(x);
	return a;
}


inline int num(const string &s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}


void bfs(int s) {
	fori(i,1,nCell) d[i]=oo;
	d[s]=0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u=q.front();	q.pop();
		foreach(it, e[u]) {
			int v=*it;
			if (d[u]+1<d[v]) {
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
}


int solve() {
	int nC=2, s=1, t=2, pos[2][MAX_N];
	fori(i,1,n) {
		pos[0][i]=++nC;
		pos[1][i]=++nC;
	}
	flow.init(nC, s, t);
	fori(i,1,n) {
		flow.addEdge(s, pos[0][i], 1, 0);
		flow.addEdge(pos[1][i], t, 1, 0);
	}
	fori(i,1,n) {
		bfs(a[i]);
		fori(j,1,n)
			flow.addEdge(pos[0][i], pos[1][j], 1, d[b[j]] * val[i]);
	}
	return flow.getFlow().sc;
}


int main() {
#ifdef DEBUG
	freopen("100484J.in", "r", stdin);
	freopen("100484J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	getline(cin, s);
	fori(testid,1,nTest) {
		getline(cin, s);
		vector<string> t=parse(s, ' ');
		n = sz(t);
		fori(i,1,n) a[i]=num(t[i-1]);
		getline(cin, s);
		t=parse(s, ' ');
		fori(i,1,n) val[i]=num(t[i-1]);

		// build hexagon
		nCell=0;
		int mid=(n+1)/2, l=mid, ck=1;
		fori(i,1,n) {
			len[i]=l;
			fori(j,1,l) id[i][j]=++nCell;
			if (i==mid) ck=0;
			if (ck) ++l;
			else --l;
		}
		fori(i,1,nCell) e[i].clear();
		for (int i=1, l=0, r=1; i<=n; ++i) {
			if (i==mid) l=-1, r=0;
			fori(j,1,len[i]) {
				int u=id[i][j], v=id[i][j+1];
				if (j<len[i]) {
					e[u].pb(v);
					e[v].pb(u);
				}
				if (i==n) continue;
				fori(k,l,r) {
					int jj=j+k;
					if (jj<1 || jj>len[i+1]) continue;
					int v=id[i+1][jj];
					e[u].pb(v);
					e[v].pb(u);
				}
			}
		}

		int ans=oo;
		// row-1
		fori(i,1,n) b[i]=id[mid][i];
		ans=min(ans, solve());
		// row-2
		ck=1;
		for (int i=1, j=1; i<=n; ++i) {
			b[i]=id[i][j];
			if (i==mid) ck=0;
			if (ck) ++j;
		}
		ans=min(ans, solve());
		// row-3
		ck=1;
		for (int i=1, j=mid; i<=n; ++i) {
			b[i]=id[i][j];
			if (i==mid) ck=0;
			if (!ck) --j;
		}
		ans=min(ans, solve());

		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}