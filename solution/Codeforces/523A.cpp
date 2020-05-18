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


const int MAX_N = 111;


int w, h;
char a[MAX_N][MAX_N], b[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("523A.in", "r", stdin);
	freopen("523A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	cin >> w >> h;
	for (int i = 0; i < h; ++i)
		cin >> a[i];

	for (int j = 0; j < w; ++j)
		for (int i = 0; i < h; ++i)
			b[j][h-1-i] = a[i][j];

	swap(h, w);
	for (int j = 0, k = w-1; j <= k; ++j, --k)
		for (int i = 0; i < h; ++i) {
			a[i][j] = b[i][k];
			a[i][k] = b[i][j];
		}

	for (int i = 0; i < (h<<1); ++i) {
		for (int j = 0; j < (w<<1); ++j)
			cout << a[i>>1][j>>1];
		cout << '\n';
	}

	return 0;
}