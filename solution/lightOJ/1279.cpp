#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e2)+5;
const ll MODULE = 1000000007LL;
const ll oo = ll(1e9);


ll K;
vector< vector<ll> > a;


ll mpow(ll a, ll n, ll module) {
	if (n < 1) return 1;
	a %= module;
	if (n == 1) return a;
	ll t = mpow(a, n>>1, module);
	t = (t*t)%module;
	if (n&1) t = (t*a)%module;
	return t;
}


inline ll inverse(ll x) {
	return mpow(x, K-2, K);
}

inline ll mmod(ll x) {
	x %= K;
	if (x < 0) x += K;
	return x;
}


int gauss(vector< vector<ll> > &a, int &rank) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
	int k = row;
	for (int i = row+1; i < n; ++i)
		if (a[i][col] > a[k][col])
			k = i;
	if (a[k][col] == 0) continue;
	for (int i = col; i <= m; ++i)
		swap(a[k][i], a[row][i]);
	for (int i = 0; i < n; ++i)
		if (i != row) {
			ll c = mmod(a[i][col] * inverse(a[row][col]));
			for (int j = col+1; j <= m; ++j)
				a[i][j] = mmod(a[i][j] - mmod(a[row][j] * c));
			a[i][col] = 0;
		}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
		if (a[i][j]) {
			zero = false;
			break;
		}
		if (zero && a[i][m])
			return 0;
	}

	rank = 0;
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j]) {
			++i;
			++rank;
		}
	if (rank < m) return oo;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("1279.in", "r", stdin);
	freopen("1279.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		int n, m;
		scanf("%d%d%lld", &n, &m, &K);
		ll tmp = mmod(-1);
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(n+1, 0);
			a[i][i] = tmp;
		}
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			a[x][y] = a[y][x] = 1;
		}

		ll ans = 0;
		int rank;
		int nSolution = gauss(a, rank);
		if (nSolution > 0) {
			if (nSolution == 1) ans = 1;
			else ans = mpow(K, n-rank, MODULE);
		}
		printf("Case %d: %d\n", test_id, (int)ans);
	}
	return 0;
}