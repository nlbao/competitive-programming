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

const int MAX_N = 1003;
const ll BASE = 10007;


int n, limit;
char s[MAX_N];
int a[MAX_N];
ll b[MAX_N], h[MAX_N], p[MAX_N];


ll getH(int i, int j) {
	if (i == 0) return h[j];
	return h[j] - h[i-1] * p[j-i+1];
}

// ll getG(int i, int j) {
// 	return g[i] - g[j+1] * p[j-i+1];
// }


bool check(int pos) {
	// g[pos+1] = 0;
	// for (int i = pos; i >= 0; --i)
	// 	g[i] = g[i+1] * BASE + b[i];
	h[0] = b[0];
	for (int i = 1; i < n; ++i) {
		h[i] = h[i-1]*BASE + ll(b[i]);
	}
	ll g = b[pos];
	for (int i = pos-1; i >= 0; --i) {
		g = g*BASE + b[i];
		if (g == getH(i, pos))
			return false;
	}
	return true;
}


bool solve() {
	int pos = n-1;
	for (int i = 0; i < n; ++i)
		b[i] = a[i];
	while (1) {
		if (pos >= n) return true;
		++b[pos];
		if (b[pos] >= limit) {
			if (pos == 0) return false;
			--pos;
			continue;
		}
		if (check(pos)) {
			for (int i = pos+1; i < n; ++i)
				b[i] = -1;
			++pos;
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("464A.in", "r", stdin);
	freopen("464A.out", "w", stdout);
#endif
	scanf("%d%d\n", &n, &limit);
	scanf("%s", s);

	for (int i = 0; i < n; ++i)
		a[i] = s[i] - 'a';
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1]*BASE;

	if (solve()) {
		for (int i = 0; i < n; ++i)
			printf("%c", char(b[i] + 'a'));
	}
	else printf("NO");
	return 0;
}