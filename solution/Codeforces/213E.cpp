#include <cstdio>
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
typedef pair<int, int> pii;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }

const int MAX_N = 2*int(1e5) + 5;
const ll BASE = 10007;

int n, m, u, value;
int a[MAX_N], b[MAX_N], cnt[4*MAX_N], pos[MAX_N];
ll p[MAX_N], h[4*MAX_N];


void update(int k, int l, int r) {
	if (l > r || r < u || l > u) return;
	if (l == r) {
		cnt[k] += value;
		h[k] = ll(b[u]) * ll(cnt[k]);
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid);
	update(right, mid+1, r);
	cnt[k] = cnt[left] + cnt[right];
	h[k] = h[left] * p[cnt[right]] + h[right];
}


void cal_update(int pos, int v) {
	u = pos;
	value = v;
	update(1, 1, m);
}


int main() {
#ifdef DEBUG
	freopen("213E.in", "r", stdin);
	freopen("213E.out", "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	scanf("%d%d", &n, &m);
	ll f = 0, pre = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		f = f*BASE + ll(a[i]);
		pre = pre*BASE + 1LL;
	}
	for (int i = 1; i <= m; ++i) {
		b[i] = read();
		pos[b[i]] = i;
	}

	int ans = 0;
	fill(cnt, 0);
	fill(h, 0);
	for (int i = 1; i <= m; ++i) {
		cal_update(pos[i], 1);
		if (i > n) {
			cal_update(pos[i-n], -1);
			f += pre;
		}
		if (h[1] == f) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}