// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_A = 3e6+6;

ll c[MAX_A], f[MAX_A];


int main() {
#ifdef DEBUG
	freopen("691F.in", "r", stdin);
	freopen("691F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(c, 0);
	int n = read();
	for (int i = 0; i < n; ++i)
		c[read()]++;

	filla(f, 0);
	for (int i = 1; i < MAX_A; ++i) if (c[i]) {
		int limit = MAX_A / i;
		for (int j = i; j < limit; ++j) if (c[j]) {
			if (j == i) f[i*j] += c[i]*(c[i]-1);
			else f[i*j] += 2*c[i]*c[j];
		}
	}
	for (int i = 1; i < MAX_A; ++i)
		f[i] += f[i-1];
	ll total = 1LL*n*(n-1);

	int m = read();
	while (m--) {
		int x = read();
		cout << total - f[x-1] << endl;
	}

	return 0;
}