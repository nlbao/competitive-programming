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

const int MAX_N = int(1e5) + 5;

int n;
ll a[MAX_N];
int f[MAX_N];
pair<ll, int> s[MAX_N];


void update(int i) {
	if (i < 1 || i > n) return;
	++f[i];
	update(i + (i&(-i)));
}


int get(int i) {
	if (i < 1 || i > n) return 0;
	return f[i] + get(i - (i&(-i)));
}


ll cnt(ll limit) {
	ll ans = 0;
	filla(f, 0);
	for (int i = 0, j = 0; i <= n; ++i) {
		while (j <= n && s[i].first - s[j].first >= limit) {
			update(s[j].second);
			++j;
		}
		if (s[i].second)
			ans += get(s[i].second - 1) + (s[i].first - a[0] >= limit);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("191E.in", "r", stdin);
	freopen("191E.out", "w", stdout);
#endif
	n = read();
	ll k, l = 0, r = 0;
	cin >> k;
	s[0] = make_pair(0, 0);
	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		ll x = read();
		a[i] = a[i-1] + x;
		s[i] = make_pair(a[i], i);
		if (x < 0) l += x;
		else r += x;
	}

	sort(s, s+1+n);

	ll ans = -1;
	while (l <= r) {
		ll mid = (l+r)/2;
		if (cnt(mid) >= k) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans << endl;
	return 0;
}