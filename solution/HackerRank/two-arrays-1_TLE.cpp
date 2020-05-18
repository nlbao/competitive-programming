#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define mmod(x) ((x)%MODULE)
#define madd(x, y) x = mmod(x+mmod(y))


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 4*2e5+5;
const int MAX_F = 4*MAX_N;
const ll MODULE = 1000000007;


int n, nQ, u, v, typeQ;
int a[MAX_N], l[MAX_N], r[MAX_N], val[MAX_N], t[MAX_N];
ll value, f[MAX_F], g[MAX_F][2], add[MAX_F][2], len[MAX_F];
int x[MAX_F], y[MAX_F];
map<int, int> id;


void build(int k, int l, int r) {
	if (l>r) return;
	if (l==r) {
		x[k]=a[l], y[k]=a[l+1]-1;
		len[k]=y[k]-x[k]+1;
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	build(kl, l, mid);
	build(kr, mid+1, r);
	x[k]=x[kl], y[k]=y[kr];
	len[k]=len[kl]+len[kr];
}


inline void pushDown(int k) {
	int kl=k<<1, kr=kl+1;
	fori(i,0,1) {
		madd(f[kl], add[k][i] * g[kl][i^1]);	madd(add[kl][i], add[k][i]);
		madd(f[kr], add[k][i] * g[kr][i^1]);	madd(add[kr][i], add[k][i]);
	}
	ll t=mmod(add[k][0]*add[k][1]);
	madd(f[kl], t);
	madd(f[kr], t);
	fori(i,0,1) {
		madd(g[kl][i], add[k][i] * len[kl]);
		madd(g[kr][i], add[k][i] * len[kr]);
	}
	fori(i,0,1) add[k][i]=0;
}


void update(int k, int l, int r) {
	if (l<r) pushDown(k);
	if (x[k]>v || y[k]<u) return;
	if (u<=x[k] && y[k]<=v) {
		madd(f[k], value * g[k][typeQ^1]);
		madd(g[k][typeQ], value * len[k]);
		madd(add[k][typeQ], value);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	f[k]=mmod(f[kl]+f[kr]);
	fori(i,0,1) g[k][i]=mmod(g[kl][i]+g[kr][i]);
}


ll get(int k, int l, int r) {
	if (l<r) pushDown(k);
	if (x[k]>v || y[k]<u) return 0;
	if (u<=x[k] && y[k]<=v) return f[k];
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return mmod(get(kl, l, mid) + get(kr, mid+1, r));
}


int main() {
#ifdef DEBUG
	freopen("two-arrays-1.in", "r", stdin);
	freopen("two-arrays-1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	n=0;
	id.clear();
	fori(i,1,nQ) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i]<3) cin >> val[i];
		id[l[i]];
		id[r[i]];
		n=max(n, r[i]);
	}
	n=0;
	foreach(it, id) {
		if (n==0 || it->fr>a[n]) a[++n]=it->fr;
		a[++n]=it->fr+1;
	}
	--n;
	filla(f, 0);
	filla(g, 0);
	filla(add, 0);
	build(1,1,n);

	fori(i,1,nQ) {
		if (t[i]<3) {
			typeQ=t[i]-1;
			u=l[i], v=r[i];
			value=val[i];
			update(1,1,n);
		}
		else {
			u=l[i], v=r[i];
			cout << get(1,1,n) << endl;
		}
	}

	return 0;
}