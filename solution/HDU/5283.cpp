#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

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
const int MAX_F = 4*MAX_N;
const ll oo = 1e18;


int n, u, v, types, value;
ll netX[4], netY[4], x[MAX_N], y[MAX_N];
ll maxX[MAX_F][4], maxY[MAX_F][4], addX[MAX_F], addY[MAX_F];
int f[MAX_F][4], ans[4];


inline void push_up(int k) {
	int pl = k<<1, pr = pl+1;
	for (int i = 0; i < 4; ++i) {
		maxX[k][i] = max(maxX[pl][i], maxX[pr][i]);
		maxY[k][i] = max(maxY[pl][i], maxY[pr][i]);
		f[k][i] = f[pl][i] + f[pr][i];
	}
}


inline void push_down(int k) {
	int pl = k<<1, pr = pl+1;
	ll dx = addX[k], dy = addY[k];
	addX[pl] += dx, addX[pr] += dx;
	addY[pl] += dy, addY[pr] += dy;
	for (int i = 0; i < 4; ++i) {
		maxX[pl][i] += dx, maxX[pr][i] += dx;
		maxY[pl][i] += dy, maxY[pr][i] += dy;
	}
	addX[k] = addY[k] = 0;
}


void build(int k, int l, int r) {
	addX[k] = addY[k] = 0;
	if (l == r) {
		for (int i = 0; i < 4; ++i) {
			maxX[k][i] = x[l], maxY[k][i] = y[l];
			f[k][i] = 1;
		}
		return;
	}
	int mid = (l+r)>>1;
	int pl = k<<1, pr = pl+1;
	build(pl, l, mid);
	build(pr, mid+1, r);
	push_up(k);
}


void update(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		if (types == 1) {
			addX[k] += value;
			for (int i = 0; i < 4; ++i)
				maxX[k][i] += value;
		}
		else {
			addY[k] += value;
			for (int i = 0; i < 4; ++i)
				maxY[k][i] += value;
		}
		return;
	}
	push_down(k);
	int mid = (l+r)>>1;
	int pl = k<<1, pr = pl+1;
	update(pl, l, mid);
	update(pr, mid+1, r);
	push_up(k);
}


void remove(int k, int l, int r) {
	int mid = (l+r)>>1, pl = k<<1, pr = pl+1;
	for (int i = 0; i < 4; ++i)
		if (maxX[k][i] > netX[i] || maxY[k][i] > netY[i]) {
			if (l == r) {
				maxX[k][i] = -oo;
				maxY[k][i] = -oo;
				f[k][i] = 0;
				continue;
			}
			push_down(k);
			remove(pl, l, mid);
			remove(pr, mid+1, r);
			push_up(k);
		}
}


void get(int k, int l, int r) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		for (int i = 0; i < 4; ++i)
			ans[i] += f[k][i];
		return;
	}
	push_down(k);
	int mid = (l+r)>>1;
	int pl = k<<1, pr = pl+1;
	get(pl, l, mid);
	get(pr, mid+1, r);
}


int main() {
#ifdef DEBUG
	freopen("5283.in", "r", stdin);
	freopen("5283.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d", &n);
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		netX[0] = x2,	netY[0] = y2;
		netX[1] = x1-1, netY[1] = y2;
		netX[2] = x2,	netY[2] = y1-1;
		netX[3] = x1-1, netY[3] = y1-1;
		for (int i = 1; i <= n; ++i)
			x[i] = read(), y[i] = read();
		build(1, 1, n);

		int nQ = read();
		while (nQ--) {
			scanf("%d%d%d", &types, &u, &v);
			if (types == 1) {
				value = read();
				update(1, 1, n);
			}
			else if (types == 2) {
				value = read();
				update(1, 1, n);
			}
			else {
				remove(1, 1, n);
				filla(ans, 0);
				get(1, 1, n);
				printf("%d\n", ans[0] - ans[1] - ans[2] + ans[3]);
			}
		}
	}
	return 0;
}