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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int MAX_G = 4*MAX_N;
const int MAX_LIMIT = 505;
const int MAX_Q = MAX_LIMIT+55;
const int oo = 1e9+7;


int n, u, v, value, m, K, limit;
int a[MAX_N], g[MAX_G], p[MAX_N], cost[MAX_N];
ll f[MAX_N][MAX_LIMIT];


void update(int k, int l, int r) {
	if (l>v || r<u) return;
	if (u<=l && r<=v) {
		g[k]=min(g[k], value);
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
}


void get(int k, int l, int r, int val, int f[]) {
	val=min(val, g[k]);
	if (l==r) {
		f[l]=val;
		return;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	get(kl, l, mid, val, f);
	get(kr, mid+1, r, val, f);
}


int main() {
#ifdef DEBUG
	freopen("xaero-and-game-of-thrones.in", "r", stdin);
	freopen("xaero-and-game-of-thrones.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m >> K >> limit;
	fori(i,1,n) cin >> a[i];
	fori(i,0,MAX_G-1) g[i]=oo;
	fori(i,1,m) {
		cin >> u >> v;
		value=u;
		update(1,1,n);
	}
	get(1,1,n,oo,p);
	fori(i,1,n) p[i]=min(p[i]-1, int(i-1));

	fori(i,0,MAX_G-1) g[i]=oo;
	fori(i,1,K) {
		cin >> u >> v >> value;
		update(1,1,n);
	}
	get(1,1,n,oo,cost);

	ll ans=0;
	filla(f, 0);
	fori(i,1,n) {
		int k=p[i];
		fori(x,1,limit) f[i][x]=f[i-1][x];
		fori(x,0,limit-cost[i]) {
			int y=x+cost[i];
			f[i][y]=max(f[i][y], f[k][x] + a[i]);
			ans=max(ans, f[i][y]);
		}
	}
	cout << ans << endl;

	return 0;
}