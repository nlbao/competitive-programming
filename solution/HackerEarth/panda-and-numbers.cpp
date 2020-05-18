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


const int MAX_N = 1e6 + 3;

bool f[MAX_N];


int cal(int x) {
	int ans = 1;
	for (int i = 0; i < x; ++i)
		ans *= x;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("panda-and-numbers.in", "r", stdin);
	freopen("panda-and-numbers.out", "w", stdout);
#endif
	filla(f, false);
	for (int i = 1; i < 8; ++i)
		f[cal(i)] = true;
	for (int i = 1; i < MAX_N; ++i) if (!f[i]) {
		int t = i;
		while (t > 0) {
			int x = t%10;
			t /= 10;
			x *= x;
			if (i > x && f[i-x]) {
				f[i] = true;
				break;
			}
		}
	}
	int nTest = read();
	while (nTest--) {
		int n = read();
		if (f[n]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}