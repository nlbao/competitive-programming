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

const int MAX_N = int(1e5)+5;
const ll MODULE = ll(1e9)+7;

ll f[MAX_N], inf[MAX_N];
ll divisor[MAX_N];


ll mmod(ll x) { return x%MODULE; }


ll mpow(ll x, ll n) {
	if (n < 1) return 1;
	if (n == 1) return x;
	ll t = mpow(x, n>>1);
	t = mmod(t*t);
	if (n&1) t = mmod(t*x);
	return t;
}


ll calC(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	if (k == 0 || k == n) return 1;
	return mmod(f[n]*mmod(inf[k]*inf[n-k]));
}


int calF(int s, int n) {
	// s must >= n
	if (s < 1 || n < 1) return 0;
	if (s == 1) return 1;
	if (n == 1) return 0;
	// extract s
	int x = s;
	vector<int> d;
	while (x > 1) {
		int y = divisor[x];
		d.push_back(y);
		while (x%y == 0) x /= y;
	}
	// calculate result
	ll res = 0;
	int m = d.size();
	for (int mask = 0; mask < (1<<m); ++mask) {
		int x = 1;
		for (int i = 0; i < m; ++i)
			if (mask&(1<<i))
				x *= d[i];
		if (__builtin_popcount(mask)&1)
			res -= calC(s/x - 1, n - 1);
		else
			res += calC(s/x - 1, n - 1);
		res %= MODULE;
	}
	return mmod(res+MODULE);
}


int main() {
#ifdef DEBUG
	freopen("439E.in", "r", stdin);
	freopen("439E.out", "w", stdout);
#endif
	// init divisors
	fill(divisor, 0);
	divisor[1] = 1;
	for (ll i = 2; i < MAX_N; ++i)
		if (divisor[i] == 0) {
			divisor[i] = i;
			for (ll j = i*i; j < MAX_N; j += i)
				divisor[j] = i;
		}
	// calculate inverse function
	f[0] = 1;
	for (ll i = 1; i < MAX_N; ++i) {
		f[i] = mmod(f[i-1]*i);
		inf[i] = mpow(f[i], MODULE-2);
	}
	// solve
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int s, n;
		scanf("%d%d", &s, &n);
		printf("%d\n", calF(s, n));
	}
	return 0;
}