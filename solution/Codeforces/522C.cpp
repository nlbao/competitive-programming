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


const int MAX_N = 1e5 + 5;
const int oo = 1e9;


int a[MAX_N], t[MAX_N], r[MAX_N], last[MAX_N];


int main() {
#ifdef DEBUG
	freopen("522C.in", "r", stdin);
	freopen("522C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i)
			cin >> a[i];
		--n;
		for (int i = 0; i < n; ++i)
			cin >> t[i] >> r[i];

		int c = 0;
		bool has1 = false;
		for (int i = 1; i <= m; ++i)
			last[i] = -1;
		for (int i = 0; i < n; ++i)
			last[t[i]] = i;

		for (int i = 0; i < n; ++i) {
			if (r[i] == 1 && !has1) {
				has1 = true;
				int minA = oo;
				for (int k = 1; k <= m; ++k)
					if (last[k] < i)
						minA = min(minA, a[k]);
				for (int k = 1; k <= m; ++k)
					if (last[k] < i && a[k] <= c)
						a[k] = 0;
				c -= minA;
			}
			if (t[i] > 0) --a[t[i]];
			else ++c;
		}
		for (int i = 1; i <= m; ++i)
			if (a[i]-c > 0) cout << "N";
			else cout << "Y";
		cout << '\n';
	}

	return 0;
}