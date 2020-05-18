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


const int MAX_N = 2e5+55;
const ll oo = 2e18;


int n, m;
pii e[MAX_N];
ll a[MAX_N], b[MAX_N], f[MAX_N];
map<ll, int> id;


void update(int i, ll val) {
	for (; i<=m; i+=lowbit(i)) f[i] = max(f[i], val);
}


ll get(int i) {
	ll ans=-oo;
	for (; i>0; i-=lowbit(i)) ans=max(ans, f[i]);
	return ans;
}


bool solve() {
	fori(i,1,m) f[i] = -oo;
	for (int i = 1, j = 1; i <= n; i = j) {
		while (j<=n && a[j]==a[i]) ++j;
		fori(k,i,j-1) {
			if (get(a[k]-1) > b[k])
				return 1;
		}
		fori(k,i,j-1) update(a[k], b[k]);
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("593B.in", "r", stdin);
	freopen("593B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	ll x1, x2;
	cin >> x1 >> x2;
	fori(i,1,n) {
		int k, b;
		cin >> k >> b;
		e[i]=mp(k, b);
	}
	sort(e+1,e+1+n);
	fori(i,1,n) {
		ll k = e[i].fr, t = e[i].sc;
		b[i] = x1*k + t;
		a[i] = x2*k + t;
		id[a[i]];
	}
	m = 0;
	foreach(it, id) it->sc = ++m;
	fori(i,1,n) a[i] = id[a[i]];

	if (solve()) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}