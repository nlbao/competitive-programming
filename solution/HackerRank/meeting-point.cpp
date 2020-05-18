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
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+55;
const ll oo = 2e18;


int n, m;
pii a[MAX_N];
ll f[MAX_N], c[MAX_N];
map<int, int> id;


inline void update(int i, int val) {
	while (i<=m) {
		f[i]+=val;
		++c[i];
		i+=lowbit(i);
	}
}


inline pll get(int i) {
	pll ans(0,0);
	while (i>0) {
		ans.fr+=c[i];
		ans.sc+=f[i];
		i-=lowbit(i);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("meeting-point.in", "r", stdin);
	freopen("meeting-point.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int x, y;
		cin >> x >> y;
		a[i].fr=x+y;
		a[i].sc=x-y;
		id[a[i].sc];
	}
	sort(a+1,a+1+n);
	m=0;
	foreach(it, id) it->sc=++m;

	filla(f, 0);
	filla(c, 0);
	fori(i,1,n) update(id[a[i].sc], a[i].sc);
	ll ans=oo, sx=0, sy=0, sumx=0;
	fori(i,1,n) sx+=a[i].fr, sy+=a[i].sc;
	fori(i,1,n) {
		ll x=a[i].fr, y=a[i].sc;
		sumx+=x;
		ll tx=-sumx + x*i + sx-sumx - x*(n-i);
		pll p=get(id[y]);
		ll cy=p.fr, sumy=p.sc;
		ll ty=-sumy + y*cy + sy-sumy - y*(n-cy);
		ans=min(ans, tx+ty);
	}
	cout << ans/2 << endl;

	return 0;
}