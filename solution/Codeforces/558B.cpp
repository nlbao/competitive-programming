#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;
const int MAX_A = 1e6 + 6;


int n;
int a[MAX_A], b[MAX_A], c[MAX_A];


int main() {
#ifdef DEBUG
	freopen("558B.in", "r", stdin);
	freopen("558B.out", "w", stdout);
#endif
	int n = read(), maxC = 0;
	for (int i = 0; i < MAX_A; ++i) {
		a[i] = MAX_N;
		b[i] = -MAX_N;
	}
	filla(c, 0);
	for (int i = 0; i < n; ++i) {
		int x = read();
		a[x] = min(a[x], i);
		b[x] = max(b[x], i);
		++c[x];
		maxC = max(maxC, c[x]);
	}

	int minLen = n;
	pii ans(0, n-1);
	for (int i = 1; i < MAX_A; ++i) {
		if (c[i] < maxC) continue;
		int l = b[i] - a[i] + 1;
		if (l < minLen) {
			minLen = l;
			ans = pii(a[i], b[i]);
		}
	}
	printf("%d %d\n", ans.first+1, ans.second+1);
	return 0;
}