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


const int MAX_N = int(1e3) + 3;
const int oo = int(1e9);


int a[MAX_N];


int cal(int s, int t) {
	int r = s%t, ans = s/t;
	if (r == 0) --ans;
	return max(ans, 0);
}


int main() {
#ifdef DEBUG
	// freopen("B.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		int n = read();
		for (int i = 0; i < n; ++i)
			a[i] = read();
		int maxA = 0;
		for (int i = 0; i < n; ++i)
			maxA = max(maxA, a[i]);
		int ans = maxA;
		for (int x = 1; x < maxA; ++x) {
			int s = 0;
			for (int i = 0; i < n; ++i)
				s += cal(a[i], x);
			ans = min(ans, s + x);
		}
		printf("Case #%d: %d\n", testid, ans);
	}
	return 0;
}