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


const int MAX_N = 222;


int n, nC, crrTurn;
int e[MAX_N], turn[MAX_N], root[MAX_N], id[MAX_N], h[MAX_N], d[MAX_N];
int len[MAX_N], f[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	ok[u] = false;
	turn[u] = crrTurn;
	int v = e[u];
	if (ok[v]) {
		h[v] = h[u]+1;
		dfs(v);
		root[u] = root[v];
		if (id[v] && root[v] != v)
			id[u] = id[v];
	}
	else {
		if (turn[u] == turn[v]) {
			root[u] = v;
			id[u] = id[v] = ++nC;
			len[nC] = h[u] - h[v] + 1;
		}
		else {
			if (id[v] > 0)	// on circle
				root[u] = v;
			else			// not
				root[u] = root[v];
		}
	}
}


void update(int u) {
	int l = 0;
	while (id[u] == 0) {
		u = e[u];
		++l;
	}
	f[id[u]] = max(f[id[u]], l);
}


ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


ll lcm(ll a, ll b) {
	ll d = gcd(a, b);
	return (a/d)*b;
}


ll solve_0() {
	ll ans = 1;
	for (int i = 1; i <= nC; ++i) {
		int t = (f[i] / len[i]) * len[i];
		while (t < f[i]) t += len[i];
		if (f[i] == 0) t = len[i];
		ans = lcm(ans, t);
	}
	return ans;
}


ll solve_1() {
	ll ans = 1, maxF = 0;
	for (int i = 1; i <= nC; ++i) {
		maxF = max(maxF, ll(f[i]));
		ans = lcm(ans, len[i]);
	}
	if (maxF > ans) {
		ll t = (maxF / ans) * ans;
		while (t < maxF) t += ans;
		ans = t;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("542C.in", "r", stdin);
	freopen("542C.out", "w", stdout);
#endif
	int n = read();
	filla(d, 0);
	for (int i = 1; i <= n; ++i) {
		e[i] = read();
		++d[e[i]];
	}

	nC = 0;
	filla(ok, true);
	filla(id, 0);
	filla(h, 0);
	filla(turn, 0);
	for (int i = 1; i <= n; ++i) if (d[i] == 0) {
		crrTurn = i;
		dfs(i);
	}
	for (int i = 1; i <= n; ++i) if (ok[i]) {
		crrTurn = i;
		dfs(i);
	}

	filla(f, 0);
	for (int i = 1; i <= n; ++i) if (d[i] == 0)
		update(i);

	// ll ans = min(solve_0(), solve_1());
	ll ans = solve_1();
	cout << ans << endl;
	return 0;
}