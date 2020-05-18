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


struct RangeBIT {
	static const int MAX_N = 5e4+5;
	int n;
	ll t1[MAX_N], t2[MAX_N];

	void init(int nn) {
		n = nn;
		filla(t1, 0);
		filla(t2, 0);
	}

	void update(ll f[], int i, ll val) {
		for (; i <= n; i += lowbit(i)) f[i] += val;
	}

	ll get(ll f[], int i) {
		ll ans = 0;
		for (; i > 0; i -= lowbit(i)) ans += f[i];
		return ans;
	}

	void update(int l, int r, ll val) {  // f[i] += val for l <= i <= r
		update(t1, l, val);
		update(t2, l, val*(l-1));
		update(t1, r+1, -val);
		update(t2, r+1, -val*r);
	}

	ll get(int k) {
		return get(t1, k)*k - get(t2, k);
	}

	ll get(int l, int r) {
		return get(r) - get(l-1);
	}
};


const int MAX_N = 5e4+14;
const int MAX_A = 151;
const int MAX_P = 36;


int n, nP, nA;
int g[MAX_N], p[MAX_N], prime[MAX_N], a[MAX_N];
ll c[MAX_P];
ll MOD;
RangeBIT bit[MAX_P];


inline ll mmod(ll x) {
	return x%MOD;
	if (x>=MOD) return x%MOD;
	return x;
}


ll mpow(ll x, ll n) {
	ll t = 1;
	x = mmod(x);
	while (n) {
		if (n&1) t=mmod(t*x);
		x = mmod(x*x);
		n >>= 1;
	}
	return t;
}


inline void cal(int x) {
	nA=0;
	while (x>1) {
		int y=g[x];
		a[++nA]=p[y];
		c[nA]=0;
		while (x%y==0) {
			x/=y;
			++c[nA];
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("100541E.in", "r", stdin);
	freopen("100541E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	nP=0;
	fori(i,1,MAX_A-1) g[i]=i;
	fori(i,2,MAX_A-1) if (g[i]==i) {
		p[i]=++nP;
		prime[nP] = i;
		for (int j=i+i; j<MAX_A; j+=i)
			g[j]=i;
	}

	int nTest=read(), nQ;
	while (nTest--) {
		MOD = 1;
		cin >> n >> nQ;
		fori(i,1,nP) bit[i].init(n);
		while (nQ--) {
			int t, l, r, x;
			cin >> t >> l >> r >> x;
			if (t==0) {
				MOD = x;
				filla(c, 0);
				fori(i,1,nP) {
					if (l<=r) c[i] = bit[i].get(l, r);
					else c[i] = bit[i].get(l, n) + bit[i].get(1, r);
				}
				ll ans = 1;
				fori(i,1,nP) ans = mmod(ans * mpow(prime[i], c[i]));
				ans %= MOD;
				cout << ans << endl;
			}
			else {
				cal(x);
				fori(i,1,nA) {
					int k = a[i];
					if (t==2) c[i] = -c[i];
					if (l<=r) bit[k].update(l, r, c[i]);
					else {
						bit[k].update(l, n, c[i]);
						bit[k].update(1, r, c[i]);
					}
				}
			}
		}
	}
	return 0;
}