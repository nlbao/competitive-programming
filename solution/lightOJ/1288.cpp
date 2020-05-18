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
const int MAX_P = 303;
const ll MODULE = 1000000007LL;
const ll oo = ll(1e9);


int nP;
int p[MAX_P];
bool ok[MAX_P];
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
	freopen("1288.in", "r", stdin);
	freopen("1288.out", "w", stdout);
#endif
	nP = 0;
	filla(ok, true);
	for (int i = 2; i < MAX_P; ++i)
		if (ok[i]) {
			p[nP++] = i;
			for (int j = i*i; j < MAX_P; j += i)
				ok[j] = false;
		}

	e.clear();
	e.resize(nP);

	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		int n = read();
		for (int i = 0; i < nP; ++i)
			e[i].reset();
		for (int i = 0; i < n; ++i) {
			ll x;
			scanf("%lld", &x);
			for (int k = 0; k < nP; ++k) {
				ll d = p[k];
				if (d > x) break;
				if (x%d == 0) {
					int c = 0;
					while (x%d == 0) {
						c ^= 1;
						x /= d;
					}
					e[k][i] = c;
				}
			}
		}

		ll ans = 0;
		int rank;
		int nSolution = gauss(e, n, rank);
		if (nSolution > 0) {
			if (nSolution == 1) ans = 1;
			else ans = mpow(2, n-rank);
		}
		ans = (ans - 1 + MODULE) % MODULE;
		printf("Case %d: %d\n", test_id, (int)ans);
	}
	return 0;
}