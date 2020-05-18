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


const int MAX_N = 155;


int n, m;
vector<pii> e[MAX_N];
bool f[MAX_N][MAX_N][MAX_N];
typedef pair<int, pii> node;
queue<node> q;


int main() {
#ifdef DEBUG
	freopen("MAXMAGIC.in", "r", stdin);
	freopen("MAXMAGIC.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	while (m--) {
		int x, y, c;
		cin >> x >> y >> c;
		e[x].pb(mp(c, y));
		e[y].pb(mp(c, x));
	}

	int ans=0;
	filla(f, 0);
	fori(u,1,n) foreach(it, e[u]) {
		int v=it->sc, w=it->fr;
		if (f[v][w][0]) continue;
		f[v][w][0]=1;
		q.push(mp(v,mp(w,0)));
	}

	while (!q.empty()) {
		node p=q.front();	q.pop();
		int u=p.fr, pre=p.sc.fr, val=p.sc.sc;
		ans=max(ans, val);
		foreach(it, e[u]) {
			int v=it->sc, w=it->fr;
			int k=val^(pre&w);
			if (f[v][w][k]) continue;
			f[v][w][k]=1;
			q.push(mp(v,mp(w,k)));
		}
	}
	cout << ans << endl;

	return 0;
}