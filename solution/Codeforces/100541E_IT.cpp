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


const int MAX_N = 5e4+14;
const int MAX_F = 3.5*MAX_N;
const int MAX_A = 151;
const int MAX_P = 36;


int n, u, v, value, nP, nA;
int g[MAX_N], p[MAX_N], prime[MAX_N], a[MAX_N];
ll f[MAX_F][MAX_P], c[MAX_P];
int add[MAX_F][MAX_P];
ll MOD;


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


inline void pushDown(int k, int l, int r) {
	if (l>=r) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	fori(i,1,nP) if (add[k][i]) {
		ll val = add[k][i];
		add[kl][i] += val;	f[kl][i] += val * (mid-l+1);
		add[kr][i] += val;	f[kr][i] += val * (r-mid);
		add[k][i]=0;
	}
}


void update(int k, int l, int r) {
	pushDown(k, l, r);
	if (l>v || r<u) return;
	if (u<=l && r<=v) {
		fori(i,1,nA) if (c[i]) {
			int id = a[i];
			ll t = c[i] * value;
			f[k][id] += t * (r-l+1);
			add[k][id] += t;
		}
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	fori(i,1,nP) f[k][i] = f[kl][i] + f[kr][i];
}


void get(int k, int l, int r) {
	pushDown(k, l, r);
	if (l>v || r<u) return;
	if (u<=l && r<=v) {
		fori(i,1,nP) c[i] += f[k][i];
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	get(kl, l, mid);
	get(kr, mid+1, r);
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
		filla(f, 0);
		filla(add, 0);
		while (nQ--) {
			int t, l, r, x;
			cin >> t >> l >> r >> x;
			if (t==0) {
				MOD = x;
				ll ans = 1;
				filla(c, 0);
				if (l<=r) {
					u=l, v=r;
					get(1, 1, n);
				}
				else {
					u=l, v=n;
					get(1, 1, n);
					u=1, v=r;
					get(1, 1, n);
				}
				fori(i,1,nP) ans = mmod(ans * mpow(prime[i], c[i]));
				ans %= MOD;
				cout << ans << endl;
			}
			else {
				value = (t==1) ? +1 : -1;
				cal(x);
				if (l<=r) {
					u=l, v=r;
					update(1, 1, n);
				}
				else {
					u=l, v=n;
					update(1, 1, n);
					u=1, v=r;
					update(1, 1, n);
				}
			}
		}
	}
	return 0;
}