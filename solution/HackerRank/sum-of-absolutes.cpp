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


int n, nQ;
int s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("sum-of-absolutes.in", "r", stdin);
	freopen("sum-of-absolutes.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int x = read() % 2;
		if (x != 0) x = 1;
		s[i] = s[i-1] + x;
	}
	while (nQ--) {
		int x, y;
		scanf("%d%d", &x, &y);
		int t = (s[y] - s[x-1]) % 2;
		if (t != 0) printf("Odd\n");
		else printf("Even\n");
	}
	return 0;
}