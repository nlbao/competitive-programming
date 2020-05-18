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


const int MAX_N = 1e5 + 5;
const int oo = 1e9;


int n;
pair<int, pii> a[MAX_N];
int f[MAX_N];


void update(int i, int value) {
	if (i > n) return;
	f[i] = min(f[i], value);
	update(i + (i&(-i)), value);
}


int get(int i) {
	if (i < 1) return oo;
	return min(f[i], get(i - (i&(-i))));
}


int main() {
#ifdef DEBUG
	freopen("100526E.in", "r", stdin);
	freopen("100526E.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		for (int i = 0; i < n; ++i) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[i] = make_pair(x, pii(y, z));
		}
		sort(a, a+n);

		int ans = 0;
		for (int i = 0; i < MAX_N; ++i)
			f[i] = oo;
		for (int i = 0; i < n; ++i) {
			int x = a[i].second.first, y = a[i].second.second;
			int minY = get(x-1);
			if (minY > y) ++ans;
			update(x, y);
		}
		printf("%d\n", ans);
	}
	return 0;
}