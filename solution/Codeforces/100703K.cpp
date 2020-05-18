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


char s[222];


int main() {
#ifdef DEBUG
	freopen("100703K.in", "r", stdin);
	freopen("100703K.out", "w", stdout);
#endif
	int n = read();
	scanf("%s", s);
	int ans = 0;
	for (int i = 0, j = n-1; i < j; ++i, --j) {
		while (i < n && s[i] != 'F') ++i;
		while (j >= 0 && s[j] != 'A') --j;
		if (i < j) ans += (j-i);
	}
	printf("%d\n", ans);
	return 0;
}