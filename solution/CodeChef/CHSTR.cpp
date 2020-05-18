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


const int MAX_N = 5005;
const ll MODULE = 1e9 + 7;
const int MAX_CHAR = 26;


struct node {
	int cnt, mask;
	node *next[MAX_CHAR];
	node() {
		cnt = 0;
		mask = 0;
	}
};


int n, nQ, maxA;
char s[MAX_N];
int f[MAX_N];
ll a[MAX_N];
ll fac[MAX_N], invfac[MAX_N];
node *root;


ll mpow(ll x, ll d) {
	if (d < 1) return 1;
	if (d == 1) return x % MODULE;
	ll t = mpow(x, d>>1);
	t = (t*t) % MODULE;
	if (d&1) return (t*x) % MODULE;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("CHSTR.in", "r", stdin);
	freopen("CHSTR.out", "w", stdout);
#endif
	fac[0] = 1;
	invfac[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fac[i] = (fac[i-1] * i) % MODULE;
		invfac[i] = mpow(fac[i], MODULE-2);
	}

	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &nQ);
		scanf("%s", s);

		maxA = 0;
		filla(a, 0);
		root = new node();
		for (int i = 0; i < n; ++i) {
			node *p = root;
			for (int j = i; j < n; ++j) {
				int x = s[j] - 'a';
				if (!(p->mask & (1<<x))) {
					p->mask |= (1<<x);
					p->next[x] = new node();
				}
				p = p->next[x];
				--a[p->cnt];
				p->cnt += 1;
				++a[p->cnt];
				maxA = max(maxA, p->cnt);
			}
		}

		filla(f, 0);
		for (int k = 1; k <= maxA; ++k)
			for (int i = k; i <= maxA; ++i) if (a[i] > 0) {
				ll ans = a[i] * fac[i];
				if (ans >= MODULE) ans %= MODULE;
				ans *= invfac[k];
				if (ans >= MODULE) ans %= MODULE;
				ans *= invfac[i-k];
				if (ans >= MODULE) ans %= MODULE;
				f[k] += ans;
				if (f[k] >= MODULE) f[k] -= MODULE;
			}

		while (nQ--) {
			int k = read();
			if (k > maxA) printf("0\n");
			else printf("%d\n", f[k]);
		}
	}
	return 0;
}