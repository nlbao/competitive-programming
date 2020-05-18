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


const int MAX_N = 2e5+5;


int n;
int a[MAX_N], p[MAX_N], ans[MAX_N], c[MAX_N];
bool used[MAX_N], okRoot[MAX_N];


int getRoot(int u) {
	return p[u] < 0 ? u : p[u] = getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("699D.in", "r", stdin);
	freopen("699D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	n = read();
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = -1;
		ans[i] = -1;
	}

	filla(used, 0);
	for (int i = 1; i <= n; ++i) {
		int k = a[i];
		int u = getRoot(i), v = getRoot(k);
		if (u != v) {
			p[u] = v;
			used[i] = 1;
			ans[i] = a[i];
		}
	}

	filla(c, 0);
	filla(okRoot, 0);
	for (int i = 1; i <= n; ++i) if (!used[i]) {
		++c[getRoot(i)];
		okRoot[i]=1;
	}

	int root=-1, root2=-1;
	for (int i = 1; i <= n; ++i) {
		int u = getRoot(i);
		if (c[u]==1 && okRoot[i]) {
			if (a[i]==i) root = i;
			root2 = i;
		}
	}
	if (root < 0) root = root2;

	int cntAns = int(a[root] != root);
	ans[root] = root;
	for (int i = 1; i <= n; ++i) if (i!=root && !used[i]) {
		ans[i] = root;
		++cntAns;
	}

	cout << cntAns << endl;
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	return 0;
}