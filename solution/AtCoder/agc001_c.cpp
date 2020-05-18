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


const int MAX_N = 2222;

int n, K, ans;
int h[MAX_N], nChild[MAX_N];
bool ok[MAX_N];
vector<int> e[MAX_N];


void dfs(int u) {
	ok[u]=0;
	nChild[u] = 1;
	cout << u << " " << h[u] << endl;
	foreach(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		h[v] = h[u]+1;
		dfs(v);
		nChild[u] += nChild[v];
		if (h[v] == K) {
			ans += nChild[v]-1;
			cout << "!!! " << u << " " << v << ": " << nChild[v]-1 << endl;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("agc001_c.in", "r", stdin);
	freopen("agc001_c.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> K;
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}

	int minAns = 0;
	for (int i = 1; i <= n; ++i) {
		filla(ok, 1);
		h[i]=0;
		ans = 0;
		cout << i << endl;
		dfs(i);
		cout << "ans = " << ans << endl;
		minAns = max(minAns, ans);
	}
	cout << minAns;

	return 0;
}