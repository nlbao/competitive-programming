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


const int MAX_N = 1e6+6;

int n, m;
int p[MAX_N], a[MAX_N];
set<int, greater<int> > s[MAX_N];


int getRoot(int u) {
	return p[u] < 0 ? u : p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("691D.in", "r", stdin);
	freopen("691D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x = getRoot(x);
		y = getRoot(y);
		if (x == y) continue;
		p[x] = y;
	}
	for (int i = 1; i <= n; ++i)
		s[getRoot(i)].insert(a[i]);
	for (int i = 1; i <= n; ++i) {
		int u = getRoot(i);
		cout << *s[u].begin() << " ";
		s[u].erase(s[u].begin());
	}

	return 0;
}