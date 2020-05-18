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


pii a[55];


int main() {
#ifdef DEBUG
	freopen("balanced-contest-or-not.in", "r", stdin);
	freopen("balanced-contest-or-not.out", "w", stdout);
#endif
	int n = 5;
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a, a+n);
	for (int i = 1; i < n; ++i)
		if (a[i].first <= a[i-1].first || a[i].second <= a[i-1].second) {
			printf("0\n");
			return 0;
		}
	printf("1\n");
	return 0;
}