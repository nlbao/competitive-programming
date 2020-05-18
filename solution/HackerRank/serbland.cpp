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


const int MAX_N = 1e5+55;


int n, limit;
pair<pii, int> a[MAX_N];
ll f[MAX_N];
vector<pll> tmp;
map<int, int> id;


void update(int i, ll val) {
	while (i<=limit) {
		f[i]=max(f[i], val);
		i+=lowbit(i);
	}
}

ll get(int i) {
	ll ans=0;
	while (i>0) {
		ans=max(ans, f[i]);
		i-=lowbit(i);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("serbland.in", "r", stdin);
	freopen("serbland.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int x, y, w;
		cin >> x >> y >> w;
		a[i]=mp(mp(x, y), w);
		id[y];
	}
	a[++n]=mp(mp(0,0),0);
	id[0];
	limit=0;
	foreach(it, id) it->sc=++limit;
	fori(i,1,n) a[i].fr.sc=id[a[i].fr.sc];
	sort(a+1,a+1+n);

	ll ans=0;
	filla(f, 0);
	for (int i=1, j=1; i<=n; i=j) {
		int x=a[i].fr.fr;
		while (j<=n && a[j].fr.fr==x) ++j;
		fori(k,i,j-1) {
			int y=a[k].fr.sc;
			ll f=get(y)+a[k].sc;
			ans=max(ans, f);
			tmp.pb(pll(y, f));
		}
		foreach(it, tmp) update(it->fr, it->sc);
		tmp.clear();
		////////////
		fori(k,i,j-1) {
			int y=a[k].fr.sc;
			ll f=get(y-1)+a[k].sc;
			ans=max(ans, f);
			update(y, f);
		}
	}
	cout << ans << endl;

	return 0;
}