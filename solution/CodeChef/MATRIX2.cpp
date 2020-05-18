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

const int MAX_N = 2004;

char s[MAX_N];
int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("MATRIX2.in", "r", stdin);
	freopen("MATRIX2.out", "w", stdout);
#endif
	ll ans = 0;
	int n, m;
	scanf("%d%d\n", &n, &m);
	filla(a, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%s\n", s);
		b[0] = (s[0] == '1');
		for (int j = 1; j < m; ++j)
			b[j] = (s[j] == '1') ? min(a[j-1], a[j]) + 1 : 0;
		for (int j = 0; j < m; ++j) {
			ans += ll(b[j]);
			a[j] = b[j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}