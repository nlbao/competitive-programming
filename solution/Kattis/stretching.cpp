#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }


const int MAX_N = 205;
const int oo = 1e9;


int n, m, crrTurn;
char a[MAX_N], b[MAX_N], ans[MAX_N];
bool f[MAX_N][MAX_N][MAX_N];
bool _equal[MAX_N];
int turn[MAX_N][MAX_N][MAX_N];


void init() {
	for (int i = 0; i < n; ++i) {
		if (i < m-1) {
			_equal[i] = false;
			continue;
		}
		_equal[i] = true;
		for (int k = 0; k < m; ++k)
			if (a[i-k] != b[m-1-k]) {
				_equal[i] = false;
				break;
			}
	}
}


inline bool isEqual(int x) {
	if (x < m-1) return false;
	return _equal[x];
}


bool check(int cnt, int x, int y) {
	if (y < 0) y = m-1;

	cout << "	" << cnt << " " << x << " " << y << endl;

	if (x < 0 && y < 0) return cnt < 1;
	if (x < 0 && y == m-1) return cnt < 1;
	if (x < 0 || y < 0) return false;


	if (turn[cnt][x][y] == crrTurn)
		return f[cnt][x][y];
	turn[cnt][x][y] = crrTurn;

	if (cnt < 1) {
		if (x != y || a[x] != b[y]) return f[cnt][x][y] = false;
		if (x == 0) return f[cnt][x][y] = true;
		return f[cnt][x][y] = check(0, x-1, y-1);
	}

	bool ans = false;
	if (a[x] == b[y]) {
		if (y == m-1) ans = check(cnt-1, x-1, y-1);
		else ans = check(cnt, x-1, y-1);
	}
	if (ans) return f[cnt][x][y] = ans;
	cout << "			" << cnt << " " << x << " " << y << ": " << isEqual(x) << endl;
	if (isEqual(x))
		ans = check(cnt-1, x-m, y);
	if (ans) return f[cnt][x][y] = ans;
	if (y != m-1)
		ans = check(cnt, x, m-1);
	return f[cnt][x][y] = ans;
}


int main() {
#ifdef DEBUG
	freopen("G.in", "r", stdin);
	freopen("G.out", "w", stdout);
#endif
	scanf("%s", a);
	n = strlen(a);

	crrTurn = 0;
	filla(turn, 0);
	int minLen = n;
	for (int i = 0; i <= n; ++i)
		ans[i] = a[i];

	for (int len = 1; len <= n; ++len) {
		if (len > minLen) break;
		if (n%len != 0) continue;
		int cnt = n / len;
		for (int i = 0; i < n-len+1; ++i) {
			if (len != 5 || i != 3) continue;
			bool ok = len < minLen;
			if (!ok)
				for (int k = 0; k < len; ++k)
					if (a[i+k] != ans[k]) {
						ok = a[i+k] < ans[k];
						break;
					}
			if (!ok) continue;

			for (int k = 0; k < len; ++k) {
				b[k] = a[i+k];
				// cout << "					" << k << " " << (int)b[k] << " " << (int)a[i+k] << endl;
			}
			m = len;
			++crrTurn;

			cout << len << " " << i << endl;

			init();

			if (check(cnt, n-1, m-1)) {
				minLen = len;
				for (int k = 0; k < len; ++k)
					ans[k] = b[k];
			}
		}
	}

	ans[minLen] = 0;
	printf("%s\n", ans);
	return 0;
}