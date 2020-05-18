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


const ll MODULE = 1e9 + 7;
const int MAX_N = 1e5 + 5;
const int MAX_F = 4*MAX_N;


int n, nQ, types, u, v, value;
int a[MAX_N];
ll f[MAX_F];
pii q[MAX_F];


void build(int k, int l, int r) {
	if (l > r) return;
	q[k] = pii(1, 0);
	if (l == r) {
		f[k] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	build(pleft, l, mid);
	build(pright, mid+1, r);
	f[k] = (f[pleft] + f[pright]) % MODULE;
}


inline void push(int k, int l, int r, int lenL, int lenR) {
	ll a = q[k].first, b = q[k].second;
	q[l] = pii((a*q[l].first) % MODULE, (a*q[l].second + b) % MODULE);
	q[r] = pii((a*q[r].first) % MODULE, (a*q[r].second + b) % MODULE);
	f[l] = (a * f[l] + b * lenL) % MODULE;
	f[r] = (a * f[r] + b * lenR) % MODULE;
}


void update(int k, int l, int r) {
	if (l > r || l > v || r < u) return;
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	if (l != r)
		push(k, pleft, pright, mid-l+1, r-mid);
	q[k] = pii(1, 0);
	if (u <= l && r <= v) {
		if (types == 1) q[k] = pii(1, value);
		else if (types == 2) q[k] = pii(value, 0);
		else if (types == 3) q[k] = pii(0, value);
		f[k] = ((ll)q[k].first * f[k] + (ll)q[k].second * (r-l+1)) % MODULE;
		return;
	}
	update(pleft, l, mid);
	update(pright, mid+1, r);
	f[k] = (f[pleft] + f[pright]) % MODULE;
}


ll get(int k, int l, int r) {
	if (l > r || l > v || r < u) return 0;
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	if (l != r)
		push(k, pleft, pright, mid-l+1, r-mid);
	q[k] = pii(1, 0);
	if (u <= l && r <= v) return f[k];
	return (get(pleft, l, mid) + get(pright, mid+1, r)) % MODULE;
}


int main() {
#ifdef DEBUG
	freopen("ADDMUL.in", "r", stdin);
	freopen("ADDMUL.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	build(1, 1, n);

	while (nQ--) {
		scanf("%d%d%d", &types, &u, &v);
		if (types < 4) {
			scanf("%d", &value);
			update(1, 1, n);
		}
		else {
			int ans = get(1, 1, n);
			printf("%d\n", ans);
		}
	}
	return 0;
}