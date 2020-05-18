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

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e3 + 33;


struct Matching {
	int nX, nY;
	vector<vector<int> > e;
	vector<int> matchX, matchY, d;
	queue<int> q;

	Matching(int nX, int nY) : nX(nX), nY(nY), d(nX+1), e(nX+1), matchX(nX+1), matchY(nY+1)	{}

	void addEdge(int u, int v) {
		e[u].push_back(v);
	}

	bool bfs_matching() {
		while (!q.empty()) q.pop();
		for (int i = 1; i <= nX; ++i)
			if (!matchX[i]) {
				d[i] = 1;
				q.push(i);
			}
			else d[i] = 0;
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			foreach(it, e[u]) {
				int v = *it;
				if (!d[matchY[v]]) {
					d[matchY[v]] = d[u] + 1;
					if (!matchY[v]) return true;
					q.push(matchY[v]);
				}
			}
		}
		return false;
	}

	bool dfs_matching(int u) {
		if (u == 0) return true;
		foreach(it, e[u]) {
			int v = *it;
			if (d[matchY[v]] == d[u]+1 && dfs_matching(matchY[v])) {
				matchX[u] = v;
				matchY[v] = u;
				return true;
			}
		}
		d[u] = 0;
		return false;
	}

	int getMatch() {
		int ans = 0;
		fillv(matchX, 0);
		fillv(matchY, 0);
		while (bfs_matching())
			for (int i = 1; i <= nX; ++i)
				if (!matchX[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};


int main() {
#ifdef DEBUG
	freopen("GCPC2015_B.in", "r", stdin);
	freopen("GCPC2015_B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int n = read();
	Matching matching(n, n);
	for (int i = 1; i <= n; ++i) {
		int m, x;
		cin >> m;
		for (int k = 0; k < m; ++k) {
			cin >> x;
			matching.addEdge(i, x+1);
		}
	}

	cout << n - matching.getMatch() << '\n';

	return 0;
}