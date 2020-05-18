#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const ll oo=1e18+4;
const ld EPS = 1e-9;
const ll LIMIT = 1e5;


ll need;


struct Fraction {
	ll x, y;

	void g() {
		ll d=__gcd(x, y);
		x/=d;
		y/=d;
	}

	Fraction(ll x=0, ll y=1) : x(x), y(y) {
		g();
	}

	ld cal() const {
		if (x>=oo || y>=oo) return oo+10;
		ll t=floor(1.0*need*y/x);
		while (ll(floor(1.0*t*x/y)) < need) ++t;
		if (t>LIMIT) return oo-10;
		return 1.0*t*x/y;
	}

	bool operator < (const Fraction &o) const {
		ld valA=cal();
		ld valB=o.cal();
		if (valA>=oo) return 0;
		if (valB>=oo) return 1;
		return (valA+EPS<valB);
	}

	Fraction operator * (const Fraction &o) const {
		return Fraction(x*o.x, y*o.y);
	}
};


struct edge {
	int v;
	Fraction w;
	edge(int v, int x, int y) : v(v), w(x, y) {}
};


const int MAX_N = 111;


int n, m;
map<string, int> id;
set<pair<Fraction, int> > heap;
Fraction d[MAX_N];
vector<edge> e[MAX_N];
string rev_id[MAX_N];


void solve(int s) {
	int cnt=0;
	heap.clear();
	fori(i,1,n) d[i]=Fraction(oo, 1);
	foreach(it, e[s]) {
		int u=it->v;
		if (it->w<d[u]) d[u]=it->w;
	}
	fori(i,1,n) if (d[i].x<oo) heap.insert(mp(d[i], i)), ++cnt;

	int minU=-1;
	Fraction ans(oo, 1);
	while (cnt>0) {
		int u=heap.begin()->sc;
		heap.erase(heap.begin());
		--cnt;
		if (u==s) continue;
		if (u!=s && d[u]<ans) {
			ans=d[u];
			minU=u;
		}
		foreach(it, e[u]) {
			int v=it->v;
			Fraction tmp=d[u]*it->w;
			if (tmp<d[v]) {
				if (heap.count(mp(d[v], v))) heap.erase(mp(d[v], v));
				else ++cnt;
				d[v]=tmp;
				heap.insert(mp(d[v], v));
			}
		}
	}
	if (minU<0) return;
	ll t=floor(1.0*need*ans.y/ans.x);
	while (ll(floor(1.0*t*ans.x/ans.y)) < need) ++t;
	string name=rev_id[minU];
	cout << t << " " << name;
}


int main() {
#ifdef DEBUG
	freopen("6128.in", "r", stdin);
	freopen("6128.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	string a, b;
	int x, y, u, v;
	while (1) {
		cin >> m;
		if (m==0) break;
		n=0;
		id.clear();
		fori(i,1,MAX_N-1) e[i].clear();
		fori(i,1,m) {
			cin >> x >> a >> b;
			cin >> y >> b;
			if (!id.count(a)) id[a]=++n;
			if (!id.count(b)) id[b]=++n;
			u=id[a], v=id[b];
			if (u==v) continue;
			e[u].pb(edge(v, x, y));
			e[v].pb(edge(u, y, x));
		}
		foreach(it, id) rev_id[it->sc]=it->fr;
		cin >> need >> a;
		cout << "Case " << ++testid << ": ";
		solve(id[a]);
		cout << endl;
	}
	return 0;
}