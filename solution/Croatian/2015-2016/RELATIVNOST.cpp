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


const int MAX_N = 1e5+2;
const int MAX_LIMIT = 20;
const int MAX_F = int(3.5*MAX_N);
const ll MOD = 1e4+7;


int n, limit, pos;
int a[MAX_N], b[MAX_N];
int f[MAX_F][MAX_LIMIT], h[MAX_F];


inline ll mmod(ll x) {
	x %= MOD;
	if (x<0) x+=MOD;
	return x;
}


void build(int k, int l, int r) {
	fori(i,0,limit-1) f[k][i]=0;
	if (l==r) {
		f[k][0]=b[l];
		f[k][1]=a[l];
		h[k]=mmod(a[l]+b[l]);
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	build(kl, l, mid);
	build(kr, mid+1, r);
	int len=min(limit-1, r-l+1);
	fori(x,0,len) fori(y,0,len-x)
		f[k][x+y] = mmod(f[k][x+y] + f[kl][x] * f[kr][y]);
	h[k]=mmod(h[kl]*h[kr]);
}


void update(int k, int l, int r) {
	if (l>pos || r<pos) return;
	if (l==r) {
		f[k][0]=b[l];
		f[k][1]=a[l];
		h[k]=a[l]+b[l];
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	int len=min(limit-1, r-l+1);
	fori(x,0,limit-1) f[k][x]=0;
	fori(x,0,len) fori(y,0,len-x)
		f[k][x+y] = mmod(f[k][x+y] + f[kl][x] * f[kr][y]);
	h[k]=mmod(h[kl]*h[kr]);
}


int main() {
#ifdef DEBUG
	freopen("RELATIVNOST.in", "r", stdin);
	freopen("RELATIVNOST.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> limit;
	fori(i,1,n) cin >> a[i];
	fori(i,1,n) cin >> b[i];
	fori(i,1,n) {
		a[i]%=MOD;
		b[i]%=MOD;
	}

	build(1,1,n);

	int nQ=read();
	while (nQ--) {
		cin >> pos;
		cin >> a[pos] >> b[pos];
		a[pos]%=MOD;
		b[pos]%=MOD;
		update(1,1,n);
		ll ans=h[1];
		fori(x,0,min(limit-1, n)) ans=mmod(ans-f[1][x]);
		cout << ans << endl;
	}

	return 0;
}