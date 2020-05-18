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


const int MAX_N = 111;


int N, nCell;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];
pii rCellID[MAX_N * MAX_N];


bool ok(int mask) {
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			b[i][k] = a[i][k];
	for (int i = 0; i < nCell; ++i)
		if ((mask>>i)&1) {
			int u = rCellID[i].first;
			int v = rCellID[i].second;
			b[u][v] = 0;
		}
	// check
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k) {
			if (b[i][k] == 0) continue;
			for (int h = 0; h < N; ++h) {
				if (h != k && b[i][k] == b[i][h]) return false;
				if (h != i && b[i][k] == b[h][k]) return false;
			}
		}
	return true;
}


// dream big
int solve_small() {
	nCell = 0;
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			rCellID[nCell++] = pii(i, k);
	int ans = 1e9;
	int nMask = 1<<nCell;
	for (int mask = 0; mask < nMask; ++mask) {
		int cnt = __builtin_popcount(mask);
		if (cnt >= ans) continue;
		if (ok(mask)) ans = cnt;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int k = 0; k < N; ++k)
				cin >> a[i][k];
		int ans = solve_small();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}