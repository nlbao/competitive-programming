#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 3e5 + 5;
const int MAX_MODULE = 1e6 + 6;


int n, crrTurn;
ll MODULE;
int a[MAX_N], maxA[MAX_N], state[MAX_N];
int c[2][MAX_MODULE], turn[2][MAX_MODULE];
ll s[MAX_N], f[MAX_N];



inline ll mmod(ll x) {
	x %= MODULE;
	if (x < 0) x += MODULE;
	return x;
}


inline void reset(int i, int j) {
	if (turn[i][j] != crrTurn) {
		turn[i][j] = crrTurn;
		c[i][j] = 0;
	}
}


inline void update(int id, int value) {
	int i = state[id], j = f[id];
	reset(i, j);
	c[i][j] += value;
}


inline ll get(int i, int j) {
	reset(i, j);
	return c[i][j];
}


inline void updateMax(int i) {
	update(i, -1);
	f[i] = mmod(s[i-1]);
	state[i] = 0;
	update(i, 1);
}


ll solve(int l, int r) {
	if (l >= r) return 0;
	int k = (l+r)>>1;
	ll ans = solve(l, k) + solve(k+1, r);

	maxA[k] = a[k];
	for (int i = k-1; i >= l; --i) maxA[i] = max(maxA[i+1], a[i]);
	for (int i = k+1; i <= r; ++i) maxA[i] = max(maxA[i-1], a[i]);

	++crrTurn;
	for (int i = l; i <= k; ++i) {
		f[i] = mmod(s[i-1] + maxA[i]);
		state[i] = 1;
		update(i, 1);
	}

	int i = k;
	for (int j = k+1; j <= r; ++j) {
		while (i >= l && maxA[i] <= maxA[j]) {
			updateMax(i);
			--i;
		}
		ans += get(0, mmod(s[j] - maxA[j]));
		ans += get(1, mmod(s[j]));
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("549F.in", "r", stdin);
	freopen("549F.out", "w", stdout);
#endif
	n = read(), MODULE = read();
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		s[i] = s[i-1] + a[i];
	}

	crrTurn = 0;
	filla(turn, 0);

	cout << solve(1, n);
	return 0;
}