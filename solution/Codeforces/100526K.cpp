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


const int MAX_N = 15;
const int MAX_M = 33;
const int MAX_P = 1<<(MAX_M / 2) + 4;


int n, m, m1, m2, ans, nMask1, nMask2;
char s[MAX_M];
int a[MAX_N][MAX_M], c[MAX_N];
int f1[MAX_P][MAX_N], f2[MAX_P][MAX_N];
int id[MAX_P], g[MAX_P];


bool cmp2(int x, int y) {
	for (int i = 0; i < n; ++i)
		if (f2[x][i] != f2[y][i])
			return f2[x][i] < f2[y][i];
	return x < y;
}


inline int cmp_find(int x, int y) {
	for (int i = 0; i < n; ++i) {
		int d = c[i] - f1[x][i];
		if (f2[y][i] != d)
			return f2[y][i] < d ? -1 : 1;
	}
	return 0;
}


int find(int pos) {
	int l = 0, r = nMask2-1, ans = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		int y = id[mid];
		int t = cmp_find(pos, y);
		if (t == 0) {
			ans = mid;
			r = mid-1;
		}
		else if (t == -1) l = mid+1;
		else r = mid-1;
	}
	return ans;
}


int solve() {
	int nSol = 0;
	if (m == 1) {
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if (a[i][0] == c[i]) {
				ok = false;
				break;
			}
		if (ok) ++nSol, ans = 0;
		ok = true;
		for (int i = 0; i < n; ++i)
			if (a[i][0] != c[i]) {
				ok = false;
				break;
			}
		if (ok) ++nSol, ans = 1;
		return nSol;
	}

	m1 = m / 2, m2 = m - m1;
	nMask1 = 1<<m1, nMask2 = 1<<m2;
	filla(f1, 0);
	for (int mask = 0; mask < nMask1; ++mask)
		for (int i = 0; i < m1; ++i) {
			int x = (mask>>i)&1;
			for (int k = 0; k < n; ++k)
				if (a[k][i] == x)
					++f1[mask][k];
		}
	filla(f2, 0);
	for (int mask = 0; mask < nMask2; ++mask) {
		id[mask] = mask;
		for (int i = 0; i < m2; ++i) {
			int x = (mask>>i)&1;
			for (int k = 0; k < n; ++k)
				if (a[k][m1+i] == x)
					++f2[mask][k];
		}
	}

	sort(id, id + nMask2, cmp2);
	g[nMask2-1] = 1;
	for (int i = nMask2-2; i >= 0; --i) {
		g[i] = 1;
		bool ok = true;
		for (int k = 0; k < n; ++k)
			if (f2[id[i]][k] != f2[id[i+1]][k]) {
				ok = false;
				break;
			}
		if (ok) g[i] += g[i+1];
	}

	for (int x = 0; x < nMask1; ++x) {
		int i = find(x);
		if (i > -1) {
			int y = id[i];
			nSol += g[i];
			ans = x | (y<<m1);
		}
	}
	return nSol;
}


int main() {
#ifdef DEBUG
	freopen("100526K.in", "r", stdin);
	freopen("100526K.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s%d", &s, &c[i]);
			for (int j = 0; j < m; ++j)
				a[i][j] = s[j] - '0';
		}
		int nSol = solve();
		if (nSol != 1) printf("%d solutions\n", nSol);
		else {
			for (int i = 0; i < m; ++i)
				printf("%d", (ans>>i)&1);
			printf("\n");
		}
	}
	return 0;
}