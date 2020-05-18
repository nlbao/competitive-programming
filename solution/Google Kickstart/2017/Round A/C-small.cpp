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


const int MAX_N = 17;
const int MAX_P = 1<<MAX_N;
const ll oo = 1e18;


int n;
ll x[MAX_N], y[MAX_N], z[MAX_N], r[MAX_N];
ll minX[MAX_P], minY[MAX_P], minZ[MAX_P];
ll maxX[MAX_P], maxY[MAX_P], maxZ[MAX_P];


ll calculateLength(int mask) {
	ll lx = (maxX[mask]-minX[mask]);
	ll ly = (maxY[mask]-minY[mask]);
	ll lz = (maxZ[mask]-minZ[mask]);
	return max(max(lx, ly), lz);
}


ll solve() {
	int nMask = 1<<n;
	minX[0] = oo;
	minY[0] = oo;
	minZ[0] = oo;
	maxX[0] = -oo;
	maxY[0] = -oo;
	maxZ[0] = -oo;
	for (int mask = 0; mask < nMask; ++mask) {
		for (int i = 0; i < n; ++i) {
			int newMask = mask | (1<<i);
			if (newMask == mask) continue;
			minX[newMask] = min(minX[mask], x[i]-r[i]);
			minY[newMask] = min(minY[mask], y[i]-r[i]);
			minZ[newMask] = min(minZ[mask], z[i]-r[i]);
			maxX[newMask] = max(maxX[mask], x[i]+r[i]);
			maxY[newMask] = max(maxY[mask], y[i]+r[i]);
			maxZ[newMask] = max(maxZ[mask], z[i]+r[i]);
		}
	}

	int final = nMask - 1;
	ll ans = calculateLength(final);
	for (int mask = 1; mask < final; ++mask)
		ans = min(ans, max(calculateLength(mask), calculateLength(final-mask)));
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i] >> z[i] >> r[i];
		ll ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}