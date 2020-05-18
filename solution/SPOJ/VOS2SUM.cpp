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


int main() {
#ifdef DEBUG
	freopen("VOS2SUM.in", "r", stdin);
	freopen("VOS2SUM.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	int nQ = read();
	while (nQ--) {
		int x = read();
		ll l = 0, r = n*(n+1)/2;
		while (l <= r) {
			ll mid = (l+r)>>1;
			ll t = find(mid);
			if (t == mid) 
		}
	}
	return 0;
}