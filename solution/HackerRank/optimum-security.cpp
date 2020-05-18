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


/*

0:  |		1:  		2: |
    +		   --+--	   +--
    |

3:  |		4: --+		5: +--
  --+		     |		   |

*/


const int TILE_NEXT_MASK[6] = {0, 1, 1, 0, 0, 1};
const int TILE_PRE_MASK[6]  = {0, 1, 0, 1, 1, 0};
const int TILE_FIRST[3] = {1, 4, 5};
const int TITE_LAST[3]  = {1, 2, 3};
const int TILE_NEXT_TILE[6][3] = {
	{0, 2, 3}, {1, 4, 5}, {1, 4, 5},
	{1, 4, 5}, {0, 2, 3}, {0, 2, 3}
};

const int MAX_H = 15;
const int MAX_P = 15e6 + 6;
const int MAX_F = (1<<MAX_H) + 4;
const ll MODULE = 1e9 + 7;


int h, w, nP;
int a[MAX_H], preMask[MAX_P], nextMask[MAX_P];
int f[2][MAX_F];


inline bool notIn(int x, const int a[]) {
	for (int i = 0; i < 3; ++i)
		if (a[i] == x)
			return false;
	return true;
}


inline bool check(int pos, int x, int pre) {
	if (pos == 1 && notIn(x, TILE_FIRST)) return false;
	if (pos == h && notIn(x, TITE_LAST)) return false;
	if (pre == -1) return true;
	return !notIn(x, TILE_NEXT_TILE[pre]);
}


void tryP(int pos) {
	if (pos > h) {
		int next = 0, pre = 0;
		for (int i = 1; i <= h; ++i) {
			if (TILE_NEXT_MASK[a[i]]) next |= 1<<(i-1);
			if (TILE_PRE_MASK[a[i]]) pre |= 1<<(i-1);
		}
		nextMask[nP] = next;
		preMask[nP] = pre;
		++nP;
		return;
	}
	for (int i = 0; i < 6; ++i) {
		if (!check(pos, i, a[pos-1])) continue;
		a[pos] = i;
		tryP(pos+1);
	}
}


void init() {
	nP = 0;
	a[0] = -1;
	tryP(1);
}


int solve() {
	filla(f, 0);
	int n = 1<<h, t = 0;
	for (int x = 0; x < nP; ++x)
		if (preMask[x] == 0)
			f[t][nextMask[x]] = 1;
	for (int i = 1; i < w; ++i) {
		int tt = t;
		t ^= 1;
		for (int mask = 0; mask < n; ++mask) f[t][mask] = 0;
		for (int x = 0; x < nP; ++x) {
			int mask = nextMask[x];
			f[t][mask] = (f[t][mask] + f[tt][preMask[x]]) % MODULE;
		}
	}
	return f[t][0];
}


int main() {
#ifdef DEBUG
	freopen("optimum-security.in", "r", stdin);
	freopen("optimum-security.out", "w", stdout);
#endif
	scanf("%d%d", &h, &w);
	if (h > w) swap(h, w);
	if (h == 1) {
		printf("0\n");
		return 0;
	}
	init();
	printf("%d\n", solve());
	return 0;
}