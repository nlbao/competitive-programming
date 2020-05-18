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

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


int n, m;
int a[MAX_N], b[MAX_N];


bool check(ll limit) {
	for (int i = 1; i <= n; ++i)
		b[i] = a[i];
	int i = n;
	for (int j = 0; j < m; ++j) {
		while (i > 0 && b[i] == 0) --i;
		if (i < 1) return true;
		ll c = limit - i;
		while (i > 0 && b[i] <= c) {
			c -= b[i];
			--i;
		}
		b[i] -= c;
	}
	while (i > 0 && b[i] == 0) --i;
	return i < 1;
}


int main() {
#ifdef DEBUG
	freopen("551C.in", "r", stdin);
	freopen("551C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	ll l = 0, r = n;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		r += a[i];
	}

	ll ans = -1;
	while (l <= r) {
		ll mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << ans;
	return 0;
}