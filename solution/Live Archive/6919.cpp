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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e4 + 44;
const int MAX_C = 55;
const ll MODULE = 21092013;


int n;
int a[MAX_N], b[MAX_N], p[MAX_N], id[MAX_N];
vector<int> e[MAX_N];
ll f[MAX_N][MAX_C], s[MAX_N][MAX_C], ans[MAX_N], c[MAX_N];


inline ll mmod(ll x) {
	x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


void dfs(int u) {
	fori(i,1,50) {
		f[u][i] = 1;
		s[u][i] = 0;
		for (int x = i; x <= b[u]; x += i)
			if (a[u] <= x)
				++s[u][i];
	}
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != 0) continue;
		p[v] = u;
		dfs(v);
		fori(i, 1, 50) f[u][i] = mmod(f[u][i] + f[v][i]);
	}

	fori(x,1,50) {
		c[x] = 1;
		ans[x] = mmod(ans[x] + s[u][x]);
		f[u][x] = mmod(s[u][x] * f[u][x]);
	}
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != u) continue;
		fori(x,1,50) {
			if (s[u][x] && f[v][x])
			ans[x] = mmod(ans[x] + mmod(c[x] * s[u][x]) * f[v][x]);
			c[x] = mmod(c[x] + f[v][x]);
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("6919.in", "r", stdin);
	freopen("6919.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) e[i].clear();
		fori(i,1,n-1) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		fori(i,1,n) cin >> a[i];
		fori(i,1,n) cin >> b[i];

		filla(ans, 0);
		filla(p, 0);
		p[1] = -1;
		dfs(1);

		ford(i,50,1)
			forix(x,i+i,50,i)
				ans[i] = mmod(ans[i]-ans[x]);

		cout << "Case " << testid << ":" << endl;
		fori(i,1,50) cout << i << ": " << ans[i] << endl;
	}

	return 0;
}