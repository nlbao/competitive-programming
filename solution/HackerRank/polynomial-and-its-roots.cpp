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


const int MAX_N = 22;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("polynomial-and-its-roots.in", "r", stdin);
	freopen("polynomial-and-its-roots.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i <= n; ++i)
		a[i] = read();
	int s = -a[n-1] / a[n];
	int p = a[0] / a[n];
	if (n%2 == 1) p = -p;
	printf("%d %d\n", s, p);
	return 0;
}