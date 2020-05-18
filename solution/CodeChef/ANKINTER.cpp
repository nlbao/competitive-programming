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


const int MAX_N = 1e6 + 6;


int n, minLen, crrTurn;
int a[MAX_N], minA[MAX_N], maxA[MAX_N];
int f[MAX_N], state[MAX_N];
int c[4][3*MAX_N], turn[4][3*MAX_N];
bool ok[MAX_N];


inline void setBit0(int &x, int i) {
	x &= ~(1<<i);
}


inline int getBit(int x, int i) {
	return (x>>i) & 1;
}


inline void up(int id, int value) {
	int i = state[id], j = f[id] + MAX_N;
	if (turn[i][j] != crrTurn) {
		turn[i][j] = crrTurn;
		c[i][j] = 0;
	}
	c[i][j] += value;
}


inline ll getC(int i, int value) {
	int j = value + MAX_N;
	if (turn[i][j] != crrTurn) {
		turn[i][j] = crrTurn;
		c[i][j] = 0;
	}
	return c[i][j];
}


inline void update(int i, bool isMin) {
	if (ok[i]) up(i, -1);
	f[i] = i;
	if (isMin) {
		setBit0(state[i], 0);
		if (getBit(state[i], 1)) f[i] += maxA[i];
	}
	else {
		setBit0(state[i], 1);
		if (getBit(state[i], 0)) f[i] -= minA[i];
	}
	if (ok[i]) up(i, 1);
}


ll solve(int l, int r) {
	if (l > r || r-l+1 < minLen) return 0;
	if (l == r) return 1;

	int mid = (l+r)>>1;
	ll ans = solve(l, mid) + solve(mid+1, r);

	// init
	int k = mid;
	minA[k] = maxA[k] = a[k];
	for (int i = k-1; i >= l; --i) {
		minA[i] = min(minA[i+1], a[i]);
		maxA[i] = max(maxA[i+1], a[i]);
	}
	for (int i = k+1; i <= r; ++i) {
		minA[i] = min(minA[i-1], a[i]);
		maxA[i] = max(maxA[i-1], a[i]);
	}

	++crrTurn;
	for (int i = l; i <= k; ++i) {
		f[i] = maxA[i] - minA[i] + i;
		state[i] = 3;
		ok[i] = false;
	}

	// two pointers
	int imin = k, imax = k, i = l;
	for (int j = k+1; j <= r; ++j) {
		while (imin >= l && minA[imin] >= minA[j]) {
			update(imin, true);
			--imin;
		}
		while (imax >= l && maxA[imax] <= maxA[j]) {
			update(imax, false);
			--imax;
		}
		while (i <= k && j-i+1 >= minLen) {
			ok[i] = true;
			up(i, 1);
			++i;
		}
		ans += getC(0, -maxA[j] + minA[j] + j);
		ans += getC(1, -maxA[j] + j);
		ans += getC(2, minA[j] + j);
		ans += getC(3, j);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("ANKINTER.in", "r", stdin);
	freopen("ANKINTER.out", "w", stdout);
#endif
	crrTurn = 0;
	filla(turn, 0);
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &minLen);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		printf("%lld\n", solve(1, n));
	}
	return 0;
}