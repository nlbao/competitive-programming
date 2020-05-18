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

const int MAX_N = int(1e3)+5;
const int MAX_BIT = 32;
const ll MODULE = ll(1e8)+7;
const ll oo = ll(1e9);


int n, m;
int a[MAX_N], b[MAX_N];
vector< bitset<MAX_N> > e;


ll mpow(ll a, ll n) {
	if (n < 1) return 1;
	a %= MODULE;
	if (n == 1) return a;
	ll t = mpow(a, n>>1);
	t = (t*t)%MODULE;
	if (n&1) t = (t*a)%MODULE;
	return t;
}


int gauss(vector< bitset<MAX_N> > &a, int m, int &rank) {
	int n = e.size();
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		for (int i = row; i < n; ++i)
			if (a[i][col]) {
				swap(a[row], a[i]);
				break;
			}
		if (!a[row][col]) continue;
		for (int i = 0; i < n; ++i)
			if (i != row && a[i][col])
				a[i] ^= a[row];
		++row;
	}

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
			++rank;
			++i;
		}
	if (rank < m) return oo;
	return 1;
}



int main() {
#ifdef DEBUG
	freopen("BADXOR.in", "r", stdin);
	freopen("BADXOR.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);

		e.clear();
		e.resize(MAX_BIT);
		for (int p = 0; p < MAX_BIT; ++p)
			for (int i = 0; i < n; ++i)
				e[p][i] = (a[i]>>p)&1;

		ll ans = 0;
		int rank;
		for (int i = 0; i < m; ++i) {
			for (int p = 0; p < MAX_BIT; ++p)
				e[p][n] = (b[i]>>p)&1;
			int nSolution = gauss(e, n, rank);
			if (nSolution > 0) {
				if (nSolution == 1) ans = (ans+1) % MODULE;
				else ans = (ans + mpow(2, n-rank)) % MODULE;
			}
		}
		ans = (mpow(2, n) - ans) % MODULE;
		ans = (ans + MODULE) % MODULE;
		printf("Case %d: %d\n", test_id, (int)ans);
	}
	return 0;
}