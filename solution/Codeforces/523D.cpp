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
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 5e5 + 5;


int n, m;
multiset<ll> heap;


int main() {
#ifdef DEBUG
	freopen("523D.in", "r", stdin);
	freopen("523D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(9);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		heap.insert(0);
	for (int i = 0; i < n; ++i) {
		ll s, d;
		cin >> s >> d;
		ll x = *heap.begin();
		heap.erase(heap.begin());
		x = max(s, x) + d;
		cout << x << endl;
		heap.insert(x);
	}

	return 0;
}