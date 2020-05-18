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


const ll MODULE = 1e6 + 3;

int f[MODULE+4];


int main() {
#ifdef DEBUG
	freopen("panda-and-chain-reaction.in", "r", stdin);
	freopen("panda-and-chain-reaction.out", "w", stdout);
#endif
	f[0] = 1;
	for (int i = 1; i < MODULE; ++i)
		f[i] = (ll(f[i-1]) * ll(i)) % MODULE;
	int nTest = read();
	while (nTest--) {
		ll n, x, ans;
		scanf("%lld%lld", &n, &x);
		x %= MODULE;
		if (n >= MODULE) ans = 0;
		else ans = f[n];
		ans = (ans * x) % MODULE;
		printf("%lld\n", ans);
	}
	return 0;
}