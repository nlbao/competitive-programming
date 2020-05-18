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


const int MAX_N = 1e5+5;


int N;
float T[MAX_N], g[MAX_N], s[MAX_N], inv[MAX_N], f[MAX_N];
vector<int> e[MAX_N];
int d[MAX_N], p[MAX_N], nChild[MAX_N];


void dfs_0(int u) {
	g[u] = s[u] = 0;
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] > 0) continue;
		p[v] = u;
		dfs_0(v);
		++nChild[u];
		g[u] += g[v];
		s[u] += g[v];
	}
	if (nChild[u] > 0)
		g[u] /= nChild[u];
	g[u] += T[u];
}


void dfs_1(int u) {
	foreach(it, e[u]) {
		int v = *it;
		if (p[v] != u) continue;
		inv[v] = inv[u] + (s[u] - g[v]);
		int m = nChild[u] - 1 + int(p[u] != u);
		if (m > 0)
			inv[v] /= m;
		inv[v] += T[u];
		dfs_1(v);
	}
	int m = nChild[u] + int(p[u] != u);
	f[u] = s[u] + inv[u];
	if (m > 0)
		f[u] /= m;
	f[u] += T[u];
}


int main() {
#ifdef DEBUG
	freopen("related_questions.in", "r", stdin);
	freopen("related_questions.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i];
		d[i] = 0;
		nChild[i] = 0;
		p[i] = -1;
	}
	for (int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		++d[u], ++d[v];
	}

	p[1] = 1;
	dfs_0(1);
	inv[1] = 0;
	dfs_1(1);

	int ans = 1;
	float minF = f[1];
	for (int i = 2; i <= N; ++i)
		if (f[i] < minF) {
			minF = f[i];
			ans = i;
		}
	cout << ans << endl;

	// for (int i = 1; i <= N; ++i)
	// 	cout << i << " " << f[i] << endl;

	return 0;
}