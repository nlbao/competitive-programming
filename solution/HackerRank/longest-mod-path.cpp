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



void bfs() {
	sumOnCircle = 0;
	filla(ok, 1);
	filla(d, 0);
	filla(dCircle, 0);
	queue<int> q;
	q.push(S);
	ok[S]=0;
	while (!q.empty()) {
		int u = q.front();	q.pop();
		if (u == T) return;
		foreach(it, e[u]) {
			int v = it->sc, w = it->fr;
			if (!ok[v]) continue;
			ok[v] = 0;
			q.push(v);
			if (onCircle[u] && onCircle[v]) dCircle[v] = 
			else d[v] = d[u]+w;
		}
	}
	return len;
}


int main() {
#ifdef DEBUG
	freopen("longest-mod-path.in", "r", stdin);
	freopen("longest-mod-path.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		e[x].pb(mp(w, y));
		e[y].pb(mp(-w, x));
	}

	sumCircle = 0;
	filla(onCircle, 0);
	dfs(1);
	// for (int i = 1; i <= n; ++i) p[i] = i;
	// for (int u = 1; u <= n; ++u) if (!onCircle[u]) {
	// 	foreach(it, e[u]) {
	// 		int v = it->sc;
	// 		if (onCircle[v]) continue;
			// int ru = getRoot(u), rv = getRoot(v);
			// if (ru != rv) p[ru] = rv;
		// }
	// }

	int nQ = read();
	while (nQ--) {
		cin >> S >> E >> M;
		ll len = bfs(), ans = 0;
		for (ll i = 1; i < 100*M; ++i) {
			ll t = ((sumCircle * i) + len + sumOnCircle) % M;
			ans = max(ans, t);
			if (sumOnCircle > 0) {
				t = ((sumCircle * i) + len + sumCircle - sumOnCircle) % M;
				ans = max(ans, t);
			}
		}
		cout << ans << endl;
	}

	return 0;
}