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


const int MAX_N = 1e3 + 3;


int n, k, a[MAX_N];
bool f[MAX_N][MAX_N];
char ans[MAX_N][MAX_N];


inline bool check(int i, int x) {
	if (x < 0 || x > k) return false;
	return f[i][x];
}


void printAns(int i, int x) {
	if (i < 1) return;
	if (ans[i][x] == '+') printAns(i-1, x-a[i]);
	else printAns(i-1, x+a[i]);
	printf("%c", ans[i][x]);
}


int main() {
#ifdef DEBUG
	freopen("100703G.in", "r", stdin);
	freopen("100703G.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) a[i] = read();
	filla(f, false);
	f[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int x = 0; x <= k; ++x) {
			if (check(i-1, x-a[i])) {
				f[i][x] = true;
				ans[i][x] = '+';
			}
			else if (check(i-1, x+a[i])) {
				f[i][x] = true;
				ans[i][x] = '-';
			}
		}
	}
	for (int i = n; i >= 0; --i)
		for (int x = 0; x <= k; ++x)
			if (f[i][x]) {
				printf("%d\n", i);
				printAns(i, x);
				return 0;
			}
	return 0;
}