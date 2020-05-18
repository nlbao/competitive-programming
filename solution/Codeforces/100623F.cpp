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


int n;
ll a[MAX_N], s[MAX_N], f[MAX_N];


void update(int i, ll val) {
	while (i<=n) {
		f[i]+=val;
		i+=lowbit(i);
	}
}


ll get(int i) {
	ll ans=0;
	while (i>0) {
		ans+=f[i];
		i-=lowbit(i);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100623F.in", "r", stdin);
	freopen("100623F.out", "w", stdout);
#else
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	s[0]=0;
	fori(i,1,n) {
		cin >> a[i];
		s[i]=s[i-1]+a[i];
	}

	filla(f, 0);
	fori(i,1,n) {
		int k=0;
		while (i%(1LL<<(k+1))==0) ++k;
		int l=1<<k;
		if (i==1 || l==1) continue;
		int x=i-l, y=i-1;
		ll tx=s[x]+get(x);
		ll ty=s[y]+get(y);
		// cout << i << ": " << x << " " << y << ": " << tx << " " << ty << endl;
		if (tx!=ty) {
			ll d=tx-ty;
			a[y]+=d;
			update(y, d);
		}
	}

	fori(i,1,n) cout << a[i] << " ";

	/////
	// cout << endl;
	// fori(i,1,n) s[i]=s[i-1]+a[i];
	// fori(i,1,n) cout << s[i] << " ";
	// cout << endl;

	return 0;
}