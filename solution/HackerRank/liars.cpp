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
vector<pii> e[MAX_N];
int d[MAX_N];


bool check(int val) {
	e[0].back().fr = val;
	e[n].back().fr = -val;

	int c = 0, sum = 0, limit = 2*n;
	fori(i,0,n) {
		foreach(it, e[i]) if (it->fr<0) sum += it->fr;
		d[i]=oo;
	}
	d[0]=0;
	bool stop=0;
	while (!stop) {
		if (++c > limit) return 0;
		stop = 1;
		fori(u,0,n) foreach(it, e[u]) {
			if (d[u] < sum) return 0;
			int v = it->sc, tmp = d[u]+it->fr;
			if (tmp < d[v]) {
				d[v] = tmp;
				stop = 0;
			}
		}
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("liars.in", "r", stdin);
	freopen("liars.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,m) {
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		e[x].pb(mp(c, y));	// s(y)-s(x) <= c
		e[y].pb(mp(-c, x));	// s(x)-s(y) <= -c  <=>  s(y)-s(x) >= c
	}
	fori(x,0,n-1) {
		int y=x+1;
		e[x].pb(mp(1, y));	// s(y)-s(x) <= 1
		e[y].pb(mp(0, x));	// s(x)-s(y) <= 0
	}
	e[0].pb(mp(1, n));		// s(n)-s(0) <= val
	e[n].pb(mp(-1, 0));		// s(0)-s(n) <= -val


	int minF = oo, maxF = -oo;
	fori(val,1,n) {
		if (check(val)) {
			minF = min(1LL*minF, val);
			maxF = val;
		}
	}
	cout << minF << " " << maxF << endl;

	return 0;
}