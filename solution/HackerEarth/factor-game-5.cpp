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

const int MAX_N = int(1e5)+5;
const int MAX_A = int(1e5)+5;


int nP;
int p[MAX_A];
bool ok[MAX_A];


int cnt(int n) {
	int ans = 0;
	for (int i = 0; i < nP; ++i) {
		ll x = p[i];
		if (x > n || x*x > n) break;
		while (n%x == 0) {
			n /= x;
			++ans;
		}
	}
	if (n > 1) ++ans;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("factor-game-5.in", "r", stdin);
	freopen("factor-game-5.out", "w", stdout);
#endif
	nP = 0;
	filla(ok, true);
	for (ll i = 2; i < MAX_A; ++i) if (ok[i]) {
		p[nP++] = i;
		for (ll j = i*i; j < MAX_A; j += i)
			ok[j] = false;
	}

	int n = read(), f = 0;
	for (int i = 0; i < n; ++i) {
		int x = read();
		int a = cnt(x);
		f ^= a;
	}
	if (f) printf("ALICE\n");
	else printf("BOB\n");
	return 0;
}