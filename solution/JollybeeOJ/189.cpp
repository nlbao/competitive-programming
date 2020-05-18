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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const ll oo = 1e18;


int n, nQ, m;
vector<pii> e[MAX_N], e2[MAX_N];
ll d[MAX_N], f[MAX_N];
set<pll> heap;


void dijkstra(int s, vector<pii> e[MAX_N]) {
	fori(i,1,n) d[i]=oo;
	d[s]=0;
	heap.insert(pll(d[s],s));
	while (!heap.empty()) {
		int u=heap.begin()->sc;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v=it->sc;
			ll tmp=d[u]+it->fr;
			if (tmp<d[v]) {
				if (has(heap, pll(d[v], v))) heap.erase(pll(d[v], v));
				d[v]=tmp;
				heap.insert(pll(d[v], v));
			}
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("189.in", "r", stdin);
	freopen("189.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m >> nQ;
		fori(i,1,n) {
			e[i].clear();
			e2[i].clear();
		}
		fori(i,1,m) {
			int x, y, c;
			cin >> x >> y >> c;
			++x, ++y;
			e[x].pb(mp(c, y));
			e2[y].pb(mp(c, x));
		}
		dijkstra(1, e);
		fori(i,1,n) f[i]=d[i];
		dijkstra(n, e2);

		cout << "Case #" << testid << ":\n";
		ll limit=f[n];
		fori(qid,1,nQ) {
			int x, y;
			ll c;
			cin >> x >> y >> c;
			++x, ++y;
			if (f[x]+c+d[y]<limit) cout << "YES";
			else cout << "NO";
			cout << endl;
		}
	}

	return 0;
}