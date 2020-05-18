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
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }



struct Matching {
	static const int MAX_N = 2e5 + 55;

	int nx, ny, mx[MAX_N], my[MAX_N], d[MAX_N];
	vector<int> e[MAX_N];
	queue<int> q;

	void init(int x, int y) {
		nx = x, ny = y;
		for (int i = 0; i <= nx; ++i)
			e[i].clear();
	}

	void addEdge(int u, int v) {	e[u].push_back(v);	}

	bool bfs_matching() {
		while (!q.empty()) q.pop();
		for (int i = 1; i <= nx; ++i)
			if (!mx[i]) {
				d[i] = 1;
				q.push(i);
			}
			else d[i] = 0;
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			foreach(it, e[u]) {
				int v = *it;
				if (!d[my[v]]) {
					d[my[v]] = d[u] + 1;
					if (!my[v]) return true;
					q.push(my[v]);
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
				if (!mx[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};


Matching matching;


int main() {
#ifdef DEBUG
	freopen("6811.in", "r", stdin);
	freopen("6811.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	fori(testid,1,nTest) {
		int nX, nY;
		cin >> nX >> nY;
		matching.init(nX, nY);
		fori(i,1,nX) {
			cin >> s;
			fori(j,1,nY) if (s[j-1]=='1') matching.addEdge(i, j);
		}
		cout << "Case #" << testid << ": " << matching.getMatch() << endl;
	}

	return 0;
}