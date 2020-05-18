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

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e5) + 5;
const int MAX_F = 4*MAX_N;


int n, nQ, pos, value, u, v;
char s[MAX_N];
int sum[MAX_F], gsum[MAX_F];
ll f[MAX_F], fl[MAX_F][3], fr[MAX_F][3];
ll g[MAX_F], gl[MAX_F][3], gr[MAX_F][3];
bool isBuild;


inline void subupdate(int k, int left, int right) {
	sum[k] = (sum[left] + sum[right]) % 3;
	for (int i = 0; i < 3; ++i) {
		fl[k][i] += fl[left][i];
		fr[k][i] += fr[right][i];
		fl[k][(sum[left]+i)%3] += fl[right][i];
		fr[k][(sum[right]+i)%3] += fr[left][i];
	}
	f[k] = f[left] + f[right];
	for (int i = 0; i < 3; ++i)
		f[k] += fr[left][i] * fl[right][(3-i)%3];
}


void update(int k, int l, int r) {
	if (l > r) return;
	if (!isBuild)
		if (l > pos || r < pos) return;
	for (int i = 0; i < 3; ++i)
		fl[k][i] = fr[k][i] = 0;
	f[k] = sum[k] = 0;
	if (l == r) {
		if (isBuild)
			value = (s[l-1] - '0') % 3;
		++fl[k][value], ++fr[k][value];
		if (value == 0) ++f[k];
		sum[k] = value;
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid);
	update(right, mid+1, r);
	subupdate(k, left, right);
}


ll get(int k, int l, int r) {
	for (int i = 0; i < 3; ++i)
		gl[k][i] = gr[k][i] = 0;
	g[k] = gsum[k] = 0;
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) {
		gsum[k] = sum[k];
		for (int i = 0; i < 3; ++i) {
			gl[k][i] = fl[k][i];
			gr[k][i] = fr[k][i];
		}
		return g[k] = f[k];
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	get(left, l, mid);
	get(right, mid+1, r);
	gsum[k] = (gsum[left] + gsum[right]) % 3;
	for (int i = 0; i < 3; ++i) {
		gl[k][i] += gl[left][i];
		gr[k][i] += gr[right][i];
		gl[k][(gsum[left]+i)%3] += gl[right][i];
		gr[k][(gsum[right]+i)%3] += gr[left][i];
	}
	g[k] = g[left] + g[right];
	for (int i = 0; i < 3; ++i)
		g[k] += gr[left][i] * gl[right][(3-i)%3];
	return g[k];
}


int main() {
#ifdef DEBUG
	freopen("QSET.in", "r", stdin);
	freopen("QSET.out", "w", stdout);
#endif
	scanf("%d%d\n", &n, &nQ);
	scanf("%s", s);
	isBuild = true;
	update(1, 1, n);
	isBuild = false;
	while (nQ--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			pos = x;
			value = y % 3;
			update(1, 1, n);
		}
		else {
			u = x, v = y;
			ll ans = get(1, 1, n);
			printf("%lld\n", ans);
		}
	}
	return 0;
}