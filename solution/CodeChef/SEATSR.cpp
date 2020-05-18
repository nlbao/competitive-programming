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
const int oo = int(1e5);

int a, b, k;
char s[MAX_N], w[MAX_N];
int turn[2][MAX_N], f[2][MAX_N];


int solve() {
	if (a == 0) return 0;
	int n = strlen(s), m = strlen(w);
	if (b == 0) return abs(n-m)*a;

	int da = k/a+1, db = k/b+1;
	// int d = min(da, db);
	int d = da;
	for (int i = n; i > 0; --i) s[i] = s[i-1];
	for (int i = m; i > 0; --i) w[i] = w[i-1];

	int t = 0, crrTurn = 0;
	for (int i = 0; i <= m; ++i)
		for (int j = 0; j < 2; ++j) {
			f[j][i] = oo;
			turn[j][i] = 0;
		}
	for (int i = 0; i <= m; ++i)
		f[t][i] = i*a;
	for (int i = 1; i <= n; ++i) {
		int tt = t;
		t = 1-t;
		f[t][0] = i*a;
		turn[t][0] = ++crrTurn;
		for (int len = -d; len <= d; ++len) {
			int j = i+len;
			if (j < 1 || j > m) continue;
			f[t][j] = oo;
			if (turn[tt][j] == crrTurn-1)
				f[t][j] = f[tt][j] + a;
			if (turn[t][j-1] == crrTurn)
				f[t][j] = min(f[t][j], f[t][j-1] + a);
			if (turn[tt][j-1] == crrTurn-1)
				f[t][j] = min(f[t][j], f[tt][j-1] + (s[i] == w[j] ? 0 : b));
			if (f[t][j] > k)
				f[t][j] = oo;
			turn[t][j] = crrTurn;
		}
	}
	return f[t][m];
}


int main() {
#ifdef DEBUG
	freopen("SEATSR.in", "r", stdin);
	freopen("SEATSR.out", "w", stdout);
#endif
	int nTest = readln();
	while (nTest--) {
		scanf("%s\n%s\n", s, w);
		scanf("%d%d%d\n", &a, &b, &k);
		int ans = solve();
		if (ans > k) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}