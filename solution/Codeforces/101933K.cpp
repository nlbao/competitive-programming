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


const int MAX_N = 2505;
const int MAX_K = 2505;
const ll MOD = 1e9 + 7;


int n, k;
ll f[MAX_N][MAX_N], sumf[MAX_N];
vector<int> e[MAX_N];


inline ll mmod(ll x) {
	x %= MOD;
	while (x < 0) x += MOD;
	return x;
}


void dfs(int u) {
	foreach(it, e[u]) {
		int v = *it;
		dfs(v);
	}
	for (int i = 0; i < k; ++i)
		f[u][i] = 1;
	foreach(it, e[u]) {
		int v = *it;
		for (int i = 0; i < k; ++i)
			f[u][i] = mmod(f[u][i] * (sumf[v] - f[v][i]));
	}
	for (int i = 0; i < k; ++i) {
		cout << u << " " << i << ": " << f[u][i] << endl;
		sumf[u] += f[u][i];
	}
}


int main() {
#ifdef DEBUG
	freopen("101933K.in", "r", stdin);
	freopen("101933K.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> k;
	for (int i = 0; i < n-1; ++i) {
		int p = read() + 1;
		e[p].push_back(i+2);
	}
	for (int u = 1; u <= n; ++u) {
		f[u][0] = 1;	// no color at u ; previous colors at sub nodes
		f[u][1] = 0;	// previous colors at u ; previous colors at sub nodes
		f[u][2] = 0;	// no colors at u ; current colors at sub nodes
		f[u][2] = 0;	// previous colors at u ; current colors at sub nodes
		f[u][3] = 0;	// current color at u
	}
	for (int i = 0; i < k; ++i) {
		for (int u = 1; u <= n; ++u) {
			f[u][1] = mmod(f[u][1] + f[u][2]);
			f[u][2] = 0;
		}
		dfs(1);
	}
	cout << mmod(f[1][1]+f[1][2]) << endl;

	return 0;
}