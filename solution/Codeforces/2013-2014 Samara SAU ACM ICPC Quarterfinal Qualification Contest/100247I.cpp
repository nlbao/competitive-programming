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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

priority_queue<int> h;

int main() {
#ifdef DEBUG
	freopen("100247I.in", "r", stdin);
	freopen("100247I.out", "w", stdout);
#endif
	int n = read(), ans = 0;
	ll p = 0, preT = 0;
	for (int i = 0; i < n; ++i) {
		ll t = read(), d = read();
		p += t-preT - d;
		preT = t;
		h.push(d);
		while (p < 0) {
			p += ll(h.top());
			h.pop();
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}