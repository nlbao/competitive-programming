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


const int MAX_N = 1e5+5;
const int MAX_F = 4*MAX_N;


int n, nQ, u, v;
ll value;
ll f[MAX_F], add[MAX_F];


void build(int k, int l, int r) {
	f[k]=add[k]=0;
	if (l==r) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	build(kl,l,mid);
	build(kr,mid+1,r);
}


inline void pushDown(int k, int l, int r) {
	if (l>=r || !add[k]) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	add[kl]+=add[k],	f[kl]+=add[k]*(mid-l+1);
	add[kr]+=add[k],	f[kr]+=add[k]*(r-mid);
	add[k]=0;
}


void update(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return;
	if (u<=l && r<=v) {
		add[k]+=value;
		f[k]+=value*(r-l+1);
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	update(kl,l,mid);
	update(kr,mid+1,r);
	f[k]=f[kl]+f[kr];
}


ll get(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return f[k];
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	return get(kl,l,mid) + get(kr,mid+1,r);
}


int main() {
#ifdef DEBUG
	freopen("HORRIBLE.in", "r", stdin);
	freopen("HORRIBLE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> nQ;
		build(1,1,n);
		while (nQ--) {
			int t;
			cin >> t >> u >> v;
			if (t==0) {
				cin >> value;
				update(1,1,n);
			}
			else cout << get(1,1,n) << endl;
		}
	}

	return 0;
}