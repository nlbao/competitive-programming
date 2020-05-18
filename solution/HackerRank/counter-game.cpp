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


int main() {
#ifdef DEBUG
	freopen("counter-game.in", "r", stdin);
	freopen("counter-game.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		unsigned long long n;
		cin >> n;
		// scanf("%lld", &n);
		if (n == 1) {
			printf("Louise\n");
			continue;
		}
		bool ok = true;
		for (ll k = 63; k >= 0 && n > 1; --k) {
			unsigned long long t = 1LL<<k;
			if (t > n) continue;
			if (t == n) n >>= 1;
			else n -= t;
			ok = !ok;
		}
		if (!ok) printf("Louise\n");
		else printf("Richard\n");
	}
	return 0;
}