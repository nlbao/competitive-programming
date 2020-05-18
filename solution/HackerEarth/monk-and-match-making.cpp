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
const ll BASE = 1e4 + 7;


int n;
char s[MAX_N];
ll p[MAX_N], h[MAX_N];


ll getH(int i, int j) {
	if (i < 1) return h[j];
	return h[j] - h[i-1] * p[j-i+1];
}


int main() {
#ifdef DEBUG
	freopen("monk-and-match-making.in", "r", stdin);
	freopen("monk-and-match-making.out", "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	scanf("%s", s);
	n = strlen(s);
	h[0] = s[0] + 1;
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1]*BASE + s[i] + 1;

	int nQ = read();
	while (nQ--) {
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		ll x = getH(--l1, --r1);
		ll y = getH(--l2, --r2);
		if (x == y) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}