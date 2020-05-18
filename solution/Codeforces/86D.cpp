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
const int MAX_A = int(1e6)+6;


int n, m, len;
int a[MAX_N], cnt[MAX_A];
pair<pii,int> q[MAX_N];
ll ans[MAX_N];


inline void update(ll &sum, ll value, int d) {
	if (d == 1) sum += value * ll(1 + 2*cnt[value]);
	else sum += value * ll(1 - 2*cnt[value]);
	cnt[value] += d;
}


bool cmp(const pair<pii, int> &a, const pair<pii, int> &b) {
	int da = a.first.second/len;
	int db = b.first.second/len;
	if (da != db) return da < db;
	return a.first.first < b.first.first;
}


int main() {
#ifdef DEBUG
	freopen("86D.in", "r", stdin);
	freopen("86D.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	len = sqrt(n) + 1;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		q[i] = make_pair(make_pair(y, x), i);
	}

	sort(q, q+m, cmp);
	int l = q[0].first.second, r = q[0].first.first;
	ll sum = 0;
	filla(cnt, 0);
	for (int i = l; i <= r; ++i)
		update(sum, a[i], 1);
	ans[q[0].second] = sum;

	for (int k = 1; k < m; ++k) {
		int x = q[k].first.second, y = q[k].first.first;
		if (y < r)
			for (int i = y+1; i <= r; ++i)
				update(sum, a[i], -1);
		else
			for (int i = r+1; i <= y; ++i)
				update(sum, a[i], 1);
		r = y;
		if (x < l)
			for (int i = x; i < l; ++i)
				update(sum, a[i], 1);
		else
			for (int i = l; i < x; ++i)
				update(sum, a[i], -1);
		l = x;
		ans[q[k].second] = sum;
	}

	for (int i = 0; i < m; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}