#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6 + 6;


string a, b;
int l[MAX_N], r[MAX_N];


int main() {
#ifdef DEBUG
	freopen("523C.in", "r", stdin);
	freopen("523C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> a >> b;
	int n = a.size(), m = b.size();
	l[0] = b[0] == a[0] ? 0 : -1;
	for (int i = 1; i < m; ++i) {
		l[i] = l[i-1];
		if (l[i] < n-1 && b[i] == a[l[i]+1])
			++l[i];
	}
	r[m] = n;
	for (int i = m-1; i >= 0; --i) {
		r[i] = r[i+1];
		if (r[i] > 0 && b[i] == a[r[i]-1])
			--r[i];
	}
	int ans = 0;
	for (int i = 0; i < m-1; ++i)
		if (l[i] == n-1 && r[i+1] == 0)
			++ans;
	cout << ans << '\n';

	return 0;
}