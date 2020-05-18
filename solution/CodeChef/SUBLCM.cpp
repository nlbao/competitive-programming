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

const int MAX_N = int(1e5) + 5;
const int MAX_A = int(1e6) + 6;

int a[MAX_N];
int d[MAX_A], prime[MAX_A], last[MAX_A], t[MAX_A];


int main() {
#ifdef DEBUG
	freopen("SUBLCM.in", "r", stdin);
	freopen("SUBLCM.out", "w", stdout);
#endif
	int nPrime = 0;
	filla(d, 0);
	for (int x = 2; x < MAX_A; ++x) {
		if (d[x] == 0) {
			d[x] = x;
			t[x] = x;
			prime[nPrime++] = x;
		}
		int limit = min(d[x], MAX_A/x);
		for (int i = 0; i < nPrime; ++i) {
			int p = prime[i];
			if (p > limit) break;
			int y = x*p;
			d[y] = p;
			t[y] = p;
			if (p == d[x])
				t[y] *= t[x];
		}
	}


	int nTest = read();
	while (nTest--) {
		int n = read(), ans = -1;
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		filla(last, 0);
		int f = 0;
		for (int i = 1; i <= n; ++i) {
			int pos = 0;
			for (int x = a[i]; x > 1;) {
				int p = d[x];
				pos = max(pos, last[p]);
				last[p] = i;
				x /= t[x];
			}
			f = min(f+1, i-pos);
			ans = max(ans, f);
		}
		if (ans < 2) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}