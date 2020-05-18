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


int n;
pii a[MAX_N];
int f[MAX_N];


void update(int i, int val) {
	while (i<=n) {
		f[i]+=val;
		i+=lowbit(i);
	}
}


int get(int i) {
	int ans=0;
	while (i>0) {
		ans+=f[i];
		i-=lowbit(i);
	}
	return ans;
}


int getRange(int l, int r) {
	if (l>r) return 0;
	return get(r)-get(l-1);
}


int main() {
#ifdef DEBUG
	freopen("100796E.in", "r", stdin);
	freopen("100796E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int x, y=i;
		cin >> x;
		if (x>y) swap(x, y);
		a[i]=mp(x, y);
	}
	sort(a+1, a+1+n);

	ll ans=0;
	filla(f, 0);
	for (int i=1, j=1; i<=n; i=j) {
		while (j<=n && a[j].fr==a[i].fr) ++j;
		fori(k,i,j-1) {
			int x=a[k].fr, y=a[k].sc;
			ans += getRange(x+1, y-1);
		}
		fori(k,i,j-1) update(a[k].sc, 1);
	}
	cout << ans << endl;

	return 0;
}