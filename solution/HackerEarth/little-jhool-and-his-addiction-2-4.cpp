#include <bits/stdc++.h>

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

inline int read() {   int x;   cin >> x;   return x;   }


const int MAX_N = 1e6 + 66;
const int oo = 1e9;


int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("little-jhool-and-his-addiction-2-4.in", "r", stdin);
	freopen("little-jhool-and-his-addiction-2-4.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		sort(a, a+n);
		int minS = oo, maxS = -oo;
		for (int i = 0, j = n-1; i < j; ++i, --j) {
			int x = a[i] + a[j];
			minS = min(minS, x);
			maxS = max(maxS, x);
		}
		int ans = maxS - minS;
		cout << ans << '\n';
		if (ans > k) cout << "No more girlfriends!\n";
		else if (ans == k) cout << "Lucky chap!\n";
		else cout << "Chick magnet Jhool!\n";
	}
	return 0;
}