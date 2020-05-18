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


const int MAX_N = 2e4 + 44;
const int MAX_A = 66;
const ll MODULE = 1e9+7;
const int nPrime = 17;
const int PRIME[nPrime] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};


int n, nQ, crrTurn;
int a[MAX_N], cnt[MAX_N][nPrime];
int turn[MAX_A], c[nPrime], ans[MAX_N];
ld best[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100570A.in", "r", stdin);
	freopen("100570A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		int x = a[i];
		for (int j = 0; j < nPrime; ++j) {
			cnt[i][j] = 0;
			while ((x%PRIME[j]) == 0) {
				++cnt[i][j];
				x /= PRIME[j];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		best[i] = 1e100;
		ans[i] = -1;
	}

	crrTurn = 0;
	filla(turn, 0);
	for (int i = 1; i <= n; ++i) {
		filla(c, 0);
		ll tmp = 1;
		ld value = 1;
		++crrTurn;
		for (int j = i; j <= n; ++j) {
			if (turn[a[j]] != crrTurn) {
				turn[a[j]] = crrTurn;
				for (int k = 0; k < nPrime; ++k)
					while (c[k] < cnt[j][k]) {
						tmp = (tmp * PRIME[k]) % MODULE;
						value *= PRIME[k];
						++c[k];
					}
			}
			int len = j-i+1;
			if (value + 1e-9 < best[len]) {
				ans[len] = tmp;
				best[len] = value;
			}
		}
	}

	while (nQ--) {
		int x;
		cin >> x;
		cout << ans[x] << endl;
	}

	return 0;
}