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


const int MAX_N = 2*int(1e5)+5;
const ll MODULE = ll(1e9)+7;

ll n, r, g;
ll f[2][MAX_N];


ll mmod(ll x) {
	return x%MODULE;
}


int main() {
#ifdef DEBUG
	freopen("478D.in", "r", stdin);
	freopen("478D.out", "w", stdout);
#endif
	cin >> r >> g;
	n = sqrt(2*(r+g));
	while (n*(n+1)/2 > r+g) --n;
	while ((n+1)*(n+2)/2 <= r+g) ++n;

	int t = 0;
	for (int i = 0; i <= r+g; ++i)
		f[t][i] = 0;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int tt = t;
		t = 1-t;
		int cnt = i*(i+1)/2;
		for (int j = 0; j <= r; ++j) {
			f[t][j] = 0;
			if (j > cnt) continue;
			if (j >= i) f[t][j] = mmod(f[t][j] + f[tt][j-i]);
			if (cnt - j <= g)
				f[t][j] = mmod(f[t][j] + f[tt][j]);
		}
	}

	ll ans = 0;
	for (int i = 0; i <= r; ++i)
		ans = mmod(ans + f[t][i]);
	cout << ans;
	return 0;
}