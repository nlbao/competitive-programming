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


const int MAX_N = 1e5+55;
const ll oo = 1e18;


int n, m, k;
vector<pii> e[MAX_N];
ll d[MAX_N];
set<pll> q;


int main() {
#ifdef DEBUG
	freopen("707B.in", "r", stdin);
	freopen("707B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].pb(mp(w, v));
		e[v].pb(mp(w, u));
	}

	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	for (int i = 0; i < k; ++i) {
		int u;
		cin >> u;
		d[u] = 0;
		q.insert(pll(0, u));
	}
	while (!q.empty()) {
		int u = q.begin()->sc;
		q.erase(q.begin());
		foreach(it, e[u]) {
			int v = it->sc, w = it->fr;
			if (d[u]+w < d[v]) {
				q.erase(pll(d[v], v));
				d[v] = d[u]+w;
				q.insert(pll(d[v], v));
			}
		}
	}

	ll minD = oo;
	for (int i = 1; i <= n; ++i)
		if (d[i] > 0 && d[i] < minD)
			minD = d[i];
	if (minD >= oo) minD = -1;
	cout << minD << endl;
	return 0;
}