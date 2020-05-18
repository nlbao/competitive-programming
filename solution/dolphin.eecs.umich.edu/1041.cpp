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

const int MAX_N = int(1e5)+5;

int n, m;
pair<int, pii> a[MAX_N];
int p[MAX_N];


int getRoot(int u) {
	if (p[u] < 1) return u;
	return p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("1041.in", "r", stdin);
	freopen("1041.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		a[i] = make_pair(-t, make_pair(x, y));
	}
	sort(a, a+m);

	int ans = 0;
	for (int i = 1; i <= n; ++i) p[i] = -1;
	for (int i = 0, c = n; i < m; ++i) {
		int x = a[i].second.first, y = a[i].second.second;
		int px = getRoot(x), py = getRoot(y);
		if (px != py) {
			p[px] = py;
			--c;
		}
		if (c <= 1) {
			ans = -a[i].first;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}