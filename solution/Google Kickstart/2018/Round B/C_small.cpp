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


const int MAX_N = 1011;
const int MAX_X = 1011;


int N, A, B, C, D, E, F, MOD;
int x[MAX_N], y[MAX_N];
int cnt[MAX_X][MAX_X];


void init() {
	for (int i = 0; i < MAX_X; ++i)
		for (int k = 0; k < MAX_X; ++k)
			cnt[i][k] = 0;
	for (int i = 0; i < N; ++i)
		++cnt[x[i]][y[i]];
	for (int i = 1; i < MAX_X; ++i) {
		cnt[0][i] += cnt[0][i-1];
		cnt[i][0] += cnt[i-1][0];
	}
	for (int i = 1; i < MAX_X; ++i)
		for (int k = 1; k < MAX_X; ++k)
			cnt[i][k] += cnt[i-1][k] + cnt[i][k-1] - cnt[i-1][k-1];
}


inline ll get_cnt(int x, int y) {
	assert(x < MOD && y < MOD);
	if (x < 0 || y < 0) return 0;
	return cnt[x][y];
}


inline ll cnt_square(int x1, int y1, int x2, int y2) {
	assert(x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0);
	assert(x1 < MOD && y1 < MOD && x2 < MOD && y2 < MOD);
	int xmin = min(x1, x2), xmax = max(x1, x2);
	int ymin = min(y1, y2), ymax = max(y1, y2);
	return get_cnt(xmax, ymax) - get_cnt(xmin-1, ymax) - get_cnt(xmax, ymin-1) + get_cnt(xmin-1, ymin-1);
}


inline ll cnt_top_left(int x, int y) {
	return cnt_square(x, y, MOD-1, MOD-1);
}

inline ll cnt_top_right(int x, int y) {
	// return cnt_square(x, y, MOD-1, 0);
	return cnt_square(x, y, 0, MOD-1);
}

inline ll cnt_bot_left(int x, int y) {
	// return cnt_square(x, y, 0, MOD-1);
	return cnt_square(x, y, MOD-1, 0);
}

inline ll cnt_bot_right(int x, int y) {
	return cnt_square(x, y, 0, 0);
}


ll solve() {
	ll ans = 0;
	for (int i = 0; i < N; ++i)
		for (int k = i+1; k < N; ++k) {
			ll add = 0;
			if (x[i] == x[k]) {
				add += N-2;
			}
			else if (y[i] == y[k]) {
				add += N-2;
			}
			else {
				int x1 = x[i], y1 = y[k];
				int x2 = x[k], y2 = y[i];
				if (y1 > y2) {
					swap(x1, x2);
					swap(y1, y2);
				}
				if (x1 < x2) {
					add += cnt_top_left(x1, y1);
					add += cnt_bot_right(x2, y2);
					if (x1+1 <= x2-1 && y1+1 <= y2-1)
						add -= cnt_square(x1+1, y1+1, x2-1, y2-1);
				}
				else {
					add += cnt_top_right(x1, y1);
					add += cnt_bot_left(x2, y2);
					if (x2+1 <= x1-1 && y1+1 <= y2-1)
						add -= cnt_square(x1-1, y1+1, x2+1, y2-1);
				}
				add -= cnt_square(x1, y1, x2, y2);
				add -= 2;
			}
			ans += add;
		}
	assert((ans%3) == 0);
	return ans / 3;
}


int main() {
#ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> N >> x[0] >> y[0] >> A >> B >> C >> D >> E >> F >> MOD;
		for (int i = 1; i < N; ++i) {
			x[i] = (A*x[i-1] + B*y[i-1] + C) % MOD;
			y[i] = (D*x[i-1] + E*y[i-1] + F) % MOD;
			assert(0 <= x[i] && x[i] < MOD);
			assert(0 <= y[i] && y[i] < MOD);
		}
		init();
		ll ans = solve();
		cout << "Case #" << testid << ": " << ans << endl;
		assert(0 <= ans && ans <= 1LL*N*(N-1)*(N-2));
	}

	return 0;
}