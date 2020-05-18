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


const int MAX_N = 1e5+1;


ll N, D;
ll f[MAX_N][3];


ll cal(ll x) {
	filla(f, 0);
	f[x][0] = 1;
	for (int i = x+1; i <= N; ++i) {
		f[i][0] = f[i-x][0];
		if (i>=x+1)
			f[i][1] = f[i-(x+1)][0] + f[i-(x+1)][1];
		if (i>=x+2)
			f[i][2] = f[i-(x+2)][0] + f[i-(x+2)][1] + f[i-(x+2)][2];
	}
	return f[N][0]+f[N][1]+f[N][2];
}


ll solve() {
	ll ans = 0;
	for (int i = D; i <= N; i += D)
		ans += cal(i);
	return ans;
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> N >> D;
		cout << "Case #" << testid << ": " << solve() << endl;
	}

	return 0;
}