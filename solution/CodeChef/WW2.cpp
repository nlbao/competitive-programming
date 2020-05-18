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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e9)+9;
const int MAX_M = 33;
const ll MODULE = int(1e9)+7;


struct Mat {
	int n, m;
	ll val[MAX_M][MAX_M];

	Mat() {}
	Mat(int _n, int _m, int value = 0) {
		n = _n, m = _m;
		for (int i = 0; i < MAX_M; ++i)
			for (int j = 0; j < MAX_M; ++j)
				val[i][j] = value;
	}

	void operator = (const Mat &other) {
		n = other.n;	m = other.m;
		for (int i = 0; i < MAX_M; ++i)
			for (int j = 0; j < MAX_M; ++j)
				val[i][j] = other.val[i][j];
	}

	Mat operator * (const Mat &other) {
		Mat ans(n, other.m);
		for (int k = 0; k < other.n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < other.m; ++j)
					ans.val[i][j] = (ans.val[i][j] + (val[i][k]*other.val[k][j])%MODULE)%MODULE;
		return ans;
	}

	Mat operator ^ (int p) {
		Mat t = *this;
		Mat ans(n, m);
		for (int i = 0; i < n; ++i)
			ans.val[i][i] = 1;
		while (p > 0) {
			if (p&1)
				ans = ans * t;
			t = t*t;
			p >>= 1;
		}
		return ans;
	}
};


int n, m;


// Mat matPow(const Mat& a, int n) {
// 	if (n == 0) return Mat(a.n, a.m, -1);
// 	if (n == 1) return a;
// 	Mat t = matPow(a, n>>1);
// 	t = t*t;
// 	if (n&1) t = t*a;
// 	return t;
// }


int solve() {
	--n;
	if (n == 0) return m%MODULE;
	Mat base_odd(m, m);
	Mat base_even(m, m);
	for (int j = 0; j < m; ++j)
		for (int d = -1; d <= 1; ++d) {
			int i = j+d;
			if (i < 0 || i >= m) continue;
			base_even.val[i][j] = 1;
			if (d != 0) base_odd.val[i][j] = 1;
		}
	Mat base = base_odd * base_even;

	Mat t;
	int d = n/2, r = n%2;
	if (d > 0) {
		// t = matPow(base, d);
		t = base ^ d;
		if (r > 0) t = t * base_odd;
	}
	else t = base_odd;		// r must > 0 because n > 0

	ll ans = 0;
	for (int j = 0; j < m; ++j)
		for (int i = 0; i < m; ++i)
			ans = (ans + t.val[i][j])%MODULE;
	return ans;
}



int main() {
#ifdef DEBUG
	freopen("WW2.in", "r", stdin);
	freopen("WW2.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		m = read();
		printf("%d\n", solve());
	}
	return 0;
}