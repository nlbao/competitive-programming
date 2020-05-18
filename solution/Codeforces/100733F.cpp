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

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int L = 1e6+3;
const int MAX_F = 4*(2*MAX_N + L);


int n, m, pos, u, v;
ll d[MAX_N], val[MAX_N], a[MAX_N], f[MAX_F], value;
map<ll, int> id;


void update(int k, int l, int r) {
	if (l>pos || r<pos) return;
	if (l==r) {
		f[k]=max(f[k], value);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	f[k]=max(f[kl], f[kr]);
}


int get(int k, int l, int r) {
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return f[k];
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return max(get(kl, l, mid), get(kr, mid+1, r));
}


int main() {
#ifdef DEBUG
	freopen("100733F.in", "r", stdin);
	freopen("100733F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int t;
		cin >> d[i] >> val[i] >> t;
		d[i]+=L;
		a[i]=d[i]-t;
		id[d[i]];
		id[a[i]];
	}
	m=0;
	foreach(it, id) it->sc=++m;

	ll ans=0;
	filla(f, 0);
	fori(i,1,n) {
		u=id[a[i]], v=id[d[i]];
		ll f=get(1, 1, m) + val[i];
		ans=max(ans, f);
		pos=id[d[i]];
		value=f;
		update(1, 1, m);
	}
	cout << ans << endl;

	return 0;
}