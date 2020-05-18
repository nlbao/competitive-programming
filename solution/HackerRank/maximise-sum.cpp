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


int main() {
#ifdef DEBUG
	freopen("maximise-sum.in", "r", stdin);
	freopen("maximise-sum.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
        int n = read();
        ll m, ans = 0, s = 0, minS = m, x;
        scanf("%lld", &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &x);
            s = (s+x)%m;
            ans = max(ans, s);            
            if (minS <= s) ans = max(ans, s - minS);
            else ans = max(ans, m + s - minS);
            if (s > 0 && s < minS)
                minS = s;
        }
        printf("%lld\n", ans);
	}
	return 0;
}
