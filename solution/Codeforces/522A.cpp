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


int main() {
#ifdef DEBUG
	freopen("522A.in", "r", stdin);
	freopen("522A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	map<string, int> d;
	d["polycarp"] = 1;
	int n = read(), ans = 1;
	for (int i = 0; i < n; ++i) {
		string a, b, x;
		cin >> a >> x >> b;
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(b.begin(), b.end(), b.begin(), ::tolower);
		if (d.find(a) == d.end())
			d[a] = 0;
		d[a] = max(d[a], d[b]+1);
		ans = max(ans, d[a]);
	}
	cout << ans << '\n';

	return 0;
}