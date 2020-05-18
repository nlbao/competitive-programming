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


const int MAX_N = int(1e5) + 5;
const ll MODULE = ll(1e9) + 7;


int n;
int p[MAX_N], f[MAX_N];


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("ikshu-and-his-class-1.in", "r", stdin);
	freopen("ikshu-and-his-class-1.out", "w", stdout);
#endif
	n = read();
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		f[i] = (ll(f[i-1]) * ll(i)) % MODULE;
	filla(p, -1);
	int k = read();
	for (int i = 0; i < k; ++i) {
		int x = getRoot(read() + 1), y = getRoot(read() + 1);
		if (x != y) {
			p[x] += p[y];
			p[y] = x;
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i) {
		int x = getRoot(i);
		if (x == i) {
			ans *= ll(f[-p[x]]);
			ans %= MODULE;
		}
	}
	printf("%d\n", (int)ans);
	return 0;
}