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
	freopen("100735H.in", "r", stdin);
	freopen("100735H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	string s;
	cin >> s >> n;
	int len=sz(s);
	matching.init(len, n);
	char a[111][7];
	fori(i,1,n) fori(x,0,5) cin >> a[i][x];
	fori(i,1,len) fori(j,1,n) {
		bool ok=0;
		fori(x,0,5) if (s[i-1]==a[j][x]) {
			matching.addEdge(i, j);
			ok=1;
			break;
		}
		if (ok) continue;
	}
	cout << ((matching.getMatch()>=len) ? "YES\n" : "NO\n");

	return 0;
}