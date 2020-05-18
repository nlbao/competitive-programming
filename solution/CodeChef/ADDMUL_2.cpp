// WA + TLE

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


const int MAX_N = 1e5+5;
const int MAX_F = 4*MAX_N;
const ll MOD = 1e9+7;

#define mmod(x) ((x)%MOD)

int n, crrType, u, v;
ll value;
int a[MAX_N];
ll f[MAX_F], fset[MAX_F], ssum[MAX_F], smul[MAX_F];
bool newSet[MAX_F];


void clearNode(int k) {
	f[k]=0;
	newSet[k]=0;	fset[k]=0;
	ssum[k]=0;
	smul[k]=1;
}


void build(int k, int l, int r) {
	clearNode(k);
	if (l==r) {
		f[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	build(kl,l,mid);
	build(kr,mid+1,r);
	f[k]=mmod(f[kl]+f[kr]);
}


void pushDown(int k, int l, int r) {
	if (l>=r) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	ll lenkl=mid-l+1, lenkr=r-mid;
	if (newSet[k]) {
		clearNode(kl);	clearNode(kr);
		newSet[kl]=newSet[kr]=1;
		fset[kl]=fset[kr]=fset[k];
		f[kl]=mmod(fset[k]*lenkl);
		f[kr]=mmod(fset[k]*lenkr);
		newSet[k]=0, fset[k]=0;
		// return;
	}
	ssum[kl]=mmod(ssum[kl]+ssum[k]);
	ssum[kr]=mmod(ssum[kr]+ssum[k]);
	f[kl]=mmod(f[kl] + ssum[k]*lenkl);
	f[kr]=mmod(f[kr] + ssum[k]*lenkr);
	ssum[k]=0;
	smul[kl]=mmod(smul[kl]*smul[k]);
	smul[kr]=mmod(smul[kr]*smul[k]);
	f[kl]=mmod(f[kl]*smul[k]);
	f[kr]=mmod(f[kr]*smul[k]);
	smul[k]=1;
}


void update(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return;
	ll len=r-l+1;
	if (u<=l && r<=v) {
		if (crrType==1) {
			ssum[k]=mmod(ssum[k]+value);
			f[k]=mmod(f[k]+value*len);
		}
		else if (crrType==2) {
			smul[k]=mmod(smul[k]*value);
			f[k]=mmod(f[k]*value);
		}
		else {
			clearNode(k);
			newSet[k]=1;
			fset[k]=value;
			f[k]=mmod(value*len);
		}
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl,l,mid);
	update(kr,mid+1,r);
	f[k]=mmod(f[kl]+f[kr]);
}


ll get(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return f[k];
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return mmod(get(kl,l,mid) + get(kr,mid+1,r));
}


int main() {
#ifdef DEBUG
	freopen("ADDMUL.in", "r", stdin);
	freopen("ADDMUL.out", "w", stdout);
#endif
	int nQ;
	scanf("%d%d", &n, &nQ);
	fori(i,1,n) scanf("%d", &a[i]);
	build(1,1,n);
	while (nQ--) {
		scanf("%d%d%d", &crrType, &u, &v);
		if (crrType<4) {
			scanf("%lld", &value);
			update(1,1,n);
		}
		else printf("%lld\n", get(1,1,n));
	}

	return 0;
}