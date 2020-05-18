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
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 3e5 + 55;
const ll oo = 1e18;


int n, k, crrTurn;
int a[MAX_N];
ll s[MAX_N], f[2][MAX_N];
int turn[2][MAX_N];


inline ll getS(int i, int j) {
	if (i >= j) return 0;
	++i;
	return s[j] - s[i];
}


int main() {
#ifdef DEBUG
	freopen("571B.in", "r", stdin);
	freopen("571B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a+1, a+1+n);

	s[0] = s[1] = 0;
	for (int i = 2; i <= n; ++i)
		s[i] = s[i-1] + ll(a[i] - a[i-1]);

	int d = n/k;
	int m = k - (n%k);

	int t = 0;
	for (int i = 0; i <= n; ++i)
		f[0][i] = f[1][i] = oo;
	f[0][0] = f[1][0] = 0;
	for (int i = d+1; i <= n; i += d+1)
		f[0][i] = f[0][i-(d+1)] + getS(i-(d+1), i);

	crrTurn = 0;
	filla(turn, 0);
	for (int nd = 1, l = 0; nd <= m; ++nd) {
		int tt = t;
		t ^= 1;
		l += d;
		++crrTurn;
		for (int i = l; i <= n; i += d+1) {
			f[t][i] = oo;
			turn[t][i] = crrTurn;
			if (turn[tt][i-d] == crrTurn-1)
				f[t][i] = min(f[t][i], f[tt][i-d] + getS(i-d, i));
			if (i >= d+1 && turn[t][i-(d+1)] == crrTurn)
				f[t][i] = min(f[t][i], f[t][i-(d+1)] + getS(i-(d+1), i));
		}
	}
	cout << f[t][n] << endl;

	return 0;
}