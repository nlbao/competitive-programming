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


const int MAX_N = 1e5 + 5;
const ll BASE = 1e4 + 7;


char s[MAX_N];
ll h[MAX_N], g[MAX_N], p[MAX_N];


inline ll getH(int i, int j) {
	if (i > j) return 0;
	return h[j] - h[i-1] * p[j-i+1];
}


inline ll getG(int i, int j) {
	if (i > j) return 0;
	return g[i] - g[j+1] * p[j-i+1];
}


bool check(int l, int r) {
	return getH(l, r) == getG(l, r);
}


bool solve(int i, int j, int l, int r) {
	if (j < l || i > r) return check(l, r);
	if (i <= l && r <= j) {
		// return check(l, r);
		return check(j-(r-i), j-(l-i));
	}
	if (l <= i && j <= r) {
		ll a = getH(l, i-1);
		a = a * p[j-i+1] + getG(i, j);
		a = a * p[r-j] + getH(j+1, r);
		ll b = getG(j+1, r);
		b = b * p[j-i+1] + getH(i, j);
		b = b * p[i-l] + getG(l, i-1);
		return a == b;
	}
	if (i <= l && l <= j) {
		ll a = getG(i, i+j-l);
		a = a * p[r-j] + getH(j+1, r);
		ll b = getG(j+1, r);
		b = b * p[j-l+1] + getH(i, i+j-l);
		return a == b;
	}
	if (i <= r && r <= j) {
		ll a = getH(l, i-1);
		a = a * p[r-i+1] + getG(j-(r-i), j);
		ll b = getH(j-(r-i), j);
		b = b * p[i-l] + getG(l, i-1);
		return a == b;
	}
	return check(l, r);
}


int main() {
#ifdef DEBUG
	freopen("ANKPAL.in", "r", stdin);
	freopen("ANKPAL.out", "w", stdout);
#endif
	// init
	scanf("%s", s);
	int n = strlen(s);
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;
	h[0] = 0;
	for (int i = 1; i <= n; ++i)
		h[i] = h[i-1]*BASE + ll(s[i-1]);
	g[n+1] = g[0] = 0;
	for (int i = n; i >= 1; --i)
		g[i] = g[i+1]*BASE + ll(s[i-1]);

	// solve
	int nQ = read();
	while (nQ--) {
		int i, j, k, l;
		scanf("%d%d%d%d", &i, &j, &k, &l);
		if (solve(i, j, k, l)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}