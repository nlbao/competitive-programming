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
const int MAX_A = 29;
const int MAX_F = 4*MAX_N;


int n, nQ, u, v, types;
char s[MAX_N];
int f[MAX_F][MAX_A];
int g[MAX_F];
vector<pii> e;


void build(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		++f[k][s[l-1]-'a'];
		return;
	}
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	build(pleft, l, mid);
	build(pright, mid+1, r);
	for (int i = 0; i < MAX_A; ++i)
		f[k][i] = f[pleft][i] + f[pright][i];
}


inline void push(int k, int l, int r) {
	if (l >= r) return;
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	filla(f[pleft], 0);
	filla(f[pright], 0);
	if (g[k] == 1) {
		for (int i = 0, c = mid-l+1; i < MAX_A; ++i) if (f[k][i] > 0) {
			int x = min(f[k][i], c);
			f[pleft][i] += x;
			f[pright][i] += f[k][i] - x;
			c -= x;
		}
	}
	else {
		for (int i = MAX_A-1, c = mid-l+1; i >= 0; --i) if (f[k][i] > 0) {
			int x = min(f[k][i], c);
			f[pleft][i] += x;
			f[pright][i] += f[k][i] - x;
			c -= x;
		}
	}
	g[pleft] = g[pright] = g[k];
	g[k] = -1;
}


void update(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		e.push_back(pii(k, r-l+1));
		return;
	}
	if (g[k] > -1) push(k, l, r);
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	update(pleft, l, mid);
	update(pright, mid+1, r);
	for (int i = 0; i < MAX_A; ++i)
		f[k][i] = f[pleft][i] + f[pright][i];
}


void updateParrent(int k, int p, int d) {
	if (p < 1) return;
	for (int x = 0; x < MAX_A; ++x)
		f[p][x] += d*f[k][x];
	updateParrent(k, p>>1, d);
}


void rebuild() {
	int m = e.size();
	int c[MAX_A];
	filla(c, 0);
	for (int i = 0; i < m; ++i) {
		int k = e[i].first;
		updateParrent(k, k>>1, -1);
		for (int x = 0; x < MAX_A; ++x)
			c[x] += f[k][x];
		filla(f[k], 0);
	}

	int x = 0, d = 1;
	if (types == 0) x = MAX_A-1, d = -1;
	for (int i = 0; i < m; ++i) {
		int k = e[i].first, len = e[i].second;
		while (len > 0) {
			int t = min(c[x], len);
			f[k][x] += t;
			c[x] -= t;
			len -= t;
			if (c[x] == 0) x += d;
		}
		g[k] = types;
		updateParrent(k, k>>1, 1);
	}
}


void get(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		int i = 0;
		while (f[k][i] < 1) ++i;
		s[l-1] = char(i+'a');
		return;
	}
	if (g[k] > -1) push(k, l, r);
	int mid = (l+r)>>1;
	int pleft = k<<1, pright = pleft+1;
	get(pleft, l, mid);
	get(pright, mid+1, r);
}


int main() {
#ifdef DEBUG
	freopen("558E.in", "r", stdin);
	freopen("558E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	scanf("%s", s);

	filla(g, -1);
	filla(f, 0);
	build(1, 1, n);

	while (nQ--) {
		scanf("%d%d%d", &u, &v, &types);
		e.clear();
		update(1, 1, n);
		rebuild();
	}

	get(1, 1, n);
	printf("%s\n", s);
	return 0;
}