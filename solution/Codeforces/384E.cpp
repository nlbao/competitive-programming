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

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2*int(1e5) + 5;
const int MAX_F = 4*MAX_N;

int n, nQ, nTime, ans, u, v, value;
int a[MAX_N], h[MAX_N], start[MAX_N], finish[MAX_N], id[MAX_N];
bool ok[MAX_N];
int f[MAX_F][2], tmp[2];
vector<int> e[MAX_N];


void dfs(int u) {
	ok[u] = false;
	start[u] = finish[u] = ++nTime;
	id[nTime] = u;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (ok[v]) {
			h[v] = h[u]+1;
			dfs(v);
			finish[u] = max(finish[u], finish[v]);
		}
	}
}


void update(int k, int l, int r, int d) {
	if (l > r || u > v) return;
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		f[k][d] += value;
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid, d);
	update(right, mid+1, r, d);
}


void get(int k, int l, int r) {
	if (l > r || l > u || r < u) return;
	for (int i = 0; i < 2; ++i)
		tmp[i] += f[k][i];
	if (l == r) {
		int x = id[l];
		if (h[x]&1) ans = tmp[1] - tmp[0];
		else ans = tmp[0] - tmp[1];
		return;
	}
	int mid = (l+r)>>1;
	get(k<<1, l, mid);
	get((k<<1)+1, mid+1, r);
}



int main() {
#ifdef DEBUG
	freopen("384E.in", "r", stdin);
	freopen("384E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	for (int i = 0; i < n-1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	nTime = 0;
	filla(ok, true);
	h[1] = 0;
	dfs(1);

	for (int i = 0; i <= 4*nTime; ++i)
		for (int j = 0; j < 2; ++j)
			f[i][j] = 0;

	while (nQ--) {
		int t = read(), x = read();
		if (t == 1) {
			value = read();
			a[x] += value;
			u = start[x] + 1;
			v = finish[x];
			update(1, 1, nTime, h[x]&1);
		}
		else {
			ans = 0;
			if (x > 1) {
				u = start[x];
				tmp[0] = tmp[1] = 0;
				get(1, 1, nTime);
			}
			printf("%d\n", a[x] + ans);
		}
	}
	return 0;
}