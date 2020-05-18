#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e3 + 13;
const int MAX_M = 4 * MAX_N;


int n;
string a[MAX_N], b[MAX_N];
char c[MAX_M], d[MAX_M], tc[MAX_M];


inline bool isEqual(int m) {
	for (int i = 0; i < m; ++i)
		if (c[i] != d[i])
			return false;
	return true;
}


bool check(int x, int len) {
	int y = x+len-1, m = 0;
	for (int i = x; i <= y; ++i)
		c[m] = a[x][i], d[m++] = b[x][i];
	for (int i = x+1; i < y; ++i)
		c[m] = a[i][y], d[m++] = b[i][y];
	for (int i = y; i >= x; --i)
		c[m] = a[y][i], d[m++] = b[y][i];
	for (int i = y-1; i > x; --i)
		c[m] = a[i][x], d[m++] = b[i][x];

	if (isEqual(m)) return true;
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < m; ++i)
			tc[i] = c[i];
		for (int i = 0; i < m; ++i)
			c[(i+len-1)%m] = tc[i];
		if (isEqual(m)) return true;
	}
	return false;
}


int main() {
#ifdef DEBUG
	freopen("picture-rotation.in", "r", stdin);
	freopen("picture-rotation.out", "w", stdout);
#endif
	n = read();
	getline(cin, a[0]);
	for (int i = 0; i < n; ++i)
		getline(cin, a[i]);
	for (int i = 0; i < n; ++i)
		getline(cin, b[i]);
	bool ok = true;
	for (int len = n, i = 0; len > 0; len -= 2, ++i) {
		ok = check(i, len);
		if (!ok) break;
	}
	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}