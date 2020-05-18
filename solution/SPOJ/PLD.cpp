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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 3*int(1e4)+4;
const ll BASE = 10007;

int n;
char s[MAX_N];
ll p[MAX_N], h[MAX_N], g[MAX_N];


inline ll getH(int i, int j) {
	if (i == 0) return h[j];
	return h[j] - h[i-1]*p[j-i+1];
}


inline ll getG(int i, int j) {
	if (j == n-1) return g[i];
	return g[i] - g[j+1]*p[j-i+1];
}


int main() {
#ifdef DEBUG
	freopen("PLD.in", "r", stdin);
	freopen("PLD.out", "w", stdout);
#endif
	int k = readln();
	scanf("%s", s);
	n = strlen(s);
	p[0] = 1;
	for (int i = 1; i <= n; ++i)
		p[i] = p[i-1]*BASE;

	h[0] = s[0];
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1]*BASE + ll(s[i]);
	g[n-1] = s[n-1];
	for (int i = n-2; i >= 0; --i)
		g[i] = g[i+1]*BASE + ll(s[i]);

	int ans = 0;
	for (int i = 0; i < n-k+1; ++i) {
		int j = i+k-1;
		if (getH(i, j) == getG(i, j))
			++ans;
	}
	printf("%d\n", ans);
	return 0;
}