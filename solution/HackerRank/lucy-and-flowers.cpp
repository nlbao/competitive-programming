#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 5003;
const ll MODULE = int(1e9+9);

ll f[MAX_N], c[MAX_N][MAX_N];


ll mmod(ll x) {
	return x%MODULE;
}


int main() {
#ifdef DEBUG
	freopen("lucy-and-flowers.in", "r", stdin);
	freopen("lucy-and-flowers.out", "w", stdout);
#endif
	fill(c, 0);
	c[0][0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = mmod(c[i-1][j] + c[i-1][j-1]);
	}

	f[0] = 1;
	for (int n = 1; n < MAX_N; ++n) {
		f[n] = 0;
		for (int i = 0; i < n; ++i)
			f[n] = mmod(f[n] + mmod(f[i]*f[n-1-i]));
	}

	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n = read();
		ll res = 0;
		for (int i = 1; i <= n; ++i)
			res = mmod(res + mmod(c[n][i]*f[i]));
		printf("%d\n", int(res));
	}
	return 0;
}