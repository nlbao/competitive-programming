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


bool solve(int s, int c) {
	if (s > 100) return false;
	if (s == 100) return false;
	if (100-s > c) return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("SEAVOTE.in", "r", stdin);
	freopen("SEAVOTE.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		int s = 0;
		int c = 0;
		for (int i = 0; i < n; ++i) {
			int b = read();
			if (b == 0) continue;
			s += b-1;
			++c;
		}
		if (solve(s, c)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}