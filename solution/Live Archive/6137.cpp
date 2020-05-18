#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


struct Matching {
	static const int MAX_N = 3000;

	int nx, ny, mx[MAX_N], my[MAX_N], d[MAX_N];
	queue<int> q;
	vector<int> e[MAX_N];
	bool ok[MAX_N];

	void init(int x, int y) {
		nx = x, ny = y;
		for (int i = 0; i <= nx; ++i) {
			e[i].clear();
			ok[i] = true;
		}
	}

	inline void disableX(int x) {	ok[x] = false;	}
	inline void enableX(int x) {	ok[x] = true;	}

	void addEdge(int u, int v) {
		e[u].push_back(v);
	}

	bool bfs_matching() {
		while (!q.empty()) q.pop();
		for (int i = 1; i <= nx; ++i)
			if (ok[i] && !mx[i]) {
				d[i] = 1;
				q.push(i);
			}
			else d[i] = 0;
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			foreach(it, e[u]) {
				int v = my[*it];
				if (ok[v] && !d[v]) {
					d[v] = d[u] + 1;
					if (!v) return true;
					q.push(v);
				}
			}
		}
		return false;
	}

	bool dfs_matching(int u) {
		if (u == 0) return true;
		foreach(it, e[u]) {
			int v = *it;
			if (d[my[v]] == d[u]+1 && dfs_matching(my[v])) {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
		d[u] = 0;
		return false;
	}

	int getMatch() {
		int ans = 0;
		filla(mx, 0);
		filla(my, 0);
		while (bfs_matching())
			for (int i = 1; i <= nx; ++i)
				if (ok[i] && !mx[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};


const int MAX_N = 55;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m;
int id[MAX_N][MAX_N];
char s[MAX_N];
Matching matching;


bool onBoard(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return id[x][y] > 0;
}


int main() {
#ifdef DEBUG
	freopen("6137.in", "r", stdin);
	freopen("6137.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	while (cin >> n >> m) {
		int nx = 0, ny = 0;
		filla(id, 0);
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 0; j < m; ++j) {
				if (s[j] == 'X') continue;
				if ((i+j)&1) id[i][j] = ++nx;
				else id[i][j] = ++ny;
			}
		}
		matching.init(nx, ny);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if ((i+j)&1) continue;
				for (int k = 0; k < 4; ++k) {
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (!onBoard(ii, jj)) continue;
					matching.addEdge(id[i][j], id[ii][jj]);
				}
			}
		int ans = (matching.getMatch() < max(nx, ny)) ? 1 : 2;
		cout << ans << endl;
	}

	return 0;
}