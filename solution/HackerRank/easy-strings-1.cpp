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


const int MAX_N = 3e5 + 5;
const ll BASE = 1e4 + 7;


char s[MAX_N];
ll p[MAX_N], h[MAX_N];


ll getH(int i, int j) {
	if (i == 0) return h[j];
	return h[j] - h[i-1] * p[j-i+1];
}


int main() {
#ifdef DEBUG
	freopen("easy-strings-1.in", "r", stdin);
	freopen("easy-strings-1.out", "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	scanf("%s", s);
	int n = strlen(s);
	h[0] = s[0];
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1] * BASE + s[i];

	ll ans = 0;
	for (int i = 0, j = n-1; i+1 < j; ++i, --j) {
		int len = i+1;
        if (getH(0, len-1) == getH(n-len, n-1))
			++ans;
	}
	for (int i = 0; i < n-2; ++i) {
		int len = n-1-i;
		if (len&1) continue;
		int d = len>>1;
		if (getH(i+1, i+d) == getH(i+d+1, n-1))
			++ans;
	}
	for (int i = n-1; i > 1; --i) {
		int len = i;
		if (len&1) continue;
		int d = len>>1;
		if (getH(0, d-1) == getH(d, len-1))
			++ans;
	}
	cout << ans << endl;
	return 0;
}