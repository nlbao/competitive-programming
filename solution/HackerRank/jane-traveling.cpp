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


const int MAX_N = 5e5+15;
const int MAX_V = 7;
const int oo = 1e9+7;

int n;
int d[MAX_V][MAX_N];
vector<pii> e[MAX_V];
pii trace[MAX_V][MAX_N];


struct cmp {
	bool operator() (const pii &a, const pii &b) const {
		int i=a.fr, x=a.sc;
		int j=b.fr, y=b.sc;
		if (d[i][x]!=d[j][y]) return d[i][x]<d[j][y];
		return a<b;
	}
};
set<pii, cmp> heap;


bool solve() {
	fori(i,1,5) {
		fori(x,1,n) {
			d[i][x]=oo;
			trace[i][x]=mp(oo, oo);
		}
		d[i][0]=0;
		heap.insert(mp(i, 0));
	}
	while (!heap.empty()) {
		pii t=*heap.begin();
		heap.erase(heap.begin());
		int u=t.fr, x=t.sc;
		pii newTrace(u, x);
		foreach(it, e[u]) {
			int v=it->sc, y=x+it->fr;
			if (y>n) continue;
			int tmp=d[u][x]+1;
			if (tmp<d[v][y]) {
				heap.erase(mp(v, y));
				d[v][y]=tmp;
				trace[v][y]=newTrace;
				heap.insert(mp(v, y));
			}
			else if (tmp==d[v][y] && newTrace<trace[v][y]) {
				trace[v][y]=newTrace;
			}
		}
	}
	if (d[1][n]>=oo) return 0;

	int i=1, x=n;
	while (x) {
		cout << i << " ";
		int y=trace[i][x].sc;
		i=trace[i][x].fr;
		x=y;
	}
	cout << i << endl;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("jane-traveling.in", "r", stdin);
	freopen("jane-traveling.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,5) {
		int j=(i==5)?1:i+1;
		int k=(j==5)?1:j+1;
		int a, b;
		cin >> a >> b;
		e[j].pb(mp(a, i));
		e[k].pb(mp(b, i));
	}
	if (!solve()) cout << -1 << endl;

	return 0;
}