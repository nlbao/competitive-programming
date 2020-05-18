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


const int MAX_N = 111;
const int oo = 1e9;


int n, m;
pair<int, pii> elist[MAX_N];
vector<pii> e[MAX_N];
int d[MAX_N], fd[MAX_N][MAX_N];
ll c[MAX_N], fc[MAX_N][MAX_N];
ld ans[MAX_N];
set<pii> heap;
map<string, int> id;


void dijkstra(int s) {
	fori(i,1,n) d[i]=oo, c[i]=0;
	d[s]=0, c[s]=1;
	heap.clear();
	heap.insert(mp(d[s], s));
	while (!heap.empty()) {
		int u=heap.begin()->sc;
		heap.erase(heap.begin());
		foreach(it, e[u]) {
			int v=it->sc;
			int tmp=d[u]+it->fr;
			if (tmp<d[v]) {
				heap.erase(mp(d[v], v));
				d[v]=tmp;
				heap.insert(mp(d[v], v));
				c[v]=c[u];
			}
			else if (tmp==d[v]) c[v] += c[u];
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("100484I.in", "r", stdin);
	freopen("100484I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	fori(testid,1,nTest) {
		id.clear();
		fori(i,0,MAX_N-1) e[i].clear();
		cin >> m >> s;
		id[s]=n=1;
		fori(i,1,m) {
			string a, b;
			int c;
			cin >> a >> b >> c;
			if (!has(id, a)) id[a]=++n;
			if (!has(id, b)) id[b]=++n;
			int u=id[a], v=id[b];
			elist[i]=mp(c, mp(u, v));
			e[u].pb(mp(c, v));
		}
		fori(i,1,n) {
			dijkstra(i);
			fori(x,1,n) fd[i][x]=d[x], fc[i][x]=c[x];
		}

		filla(ans, 0);
		ll nDest=0;
		fori(t,2,n) if (fd[1][t]<oo) {
			++nDest;
			fori(i,1,m) {
				int u=elist[i].sc.fr, v=elist[i].sc.sc;
				if (fd[1][u] + elist[i].fr + fd[v][t] > fd[1][t]) continue;
				ans[i] += ld(fc[1][u] * fc[v][t]) / fc[1][t];
			}
		}

		cout << "Case #" << testid << ": ";
		fori(i,1,m) cout << ans[i] / nDest << " ";
		cout << endl;
	}

	return 0;
}