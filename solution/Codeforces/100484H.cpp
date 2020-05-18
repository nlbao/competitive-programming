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


const int MAX_N = 1e4+44;
const int PADDING = 1e4+14;
const int MAX_A = 2*PADDING + 44;
const int MAX_F = 4*MAX_A;


int n, K, maxA, u, v;
pii a[MAX_N];
int f[MAX_F];


inline void pushDown(int k, int l, int r) {
	if (l>=r) return;
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	if (f[k]==r-l+1) {
		f[kl]=mid-l+1;
		f[kr]=r-mid;
	}
}


void update(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return;
	if (u<=l && r<=v) {
		f[k]=r-l+1;
		return;
	}
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	update(kl,l,mid);
	update(kr,mid+1,r);
	f[k]=f[kl]+f[kr];
}


int get(int k, int l, int r) {
	pushDown(k,l,r);
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return f[k];
	int mid=(l+r)>>1, kl=k<<1, kr=kl+1;
	return get(kl,l,mid) + get(kr,mid+1,r);
}


int find(int pos, int val) {
	int l=1, r=pos;
	while (l<=r) {
		int mid=(l+r)>>1;
		u=mid, v=pos;
		int t=(v-u+1)-get(1,1,maxA);
		if (t==val) return mid;
		else if (t<val) r=mid-1;
		else l=mid+1;
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("100484H.in", "r", stdin);
	freopen("100484H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int m=0;
	maxA=MAX_A-4;
	filla(f, 0);
	cin >> K >> n;
	fori(i,1,n) {
		cin >> u >> v;
		if (u>v) swap(u, v);
		u += PADDING, v += PADDING;
		if (v-u+1<=K) {
			update(1,1,maxA);
		}
		else a[++m]=mp(v, u);
	}
	sort(a+1,a+1+m);
	fori(i,1,m) {
		int l=a[i].sc, r=a[i].fr;
		u=l, v=r;
		int t=get(1,1,maxA);
		if (t>=K) continue;
		int p = find(r, K-t);
		u=p;
		update(1,1,maxA);
	}

	vector<int> ans;
	fori(i,1,maxA) {
		u = v = i;
		if (get(1,1,maxA)) ans.pb(i);
	}
	m=ans.size();
	cout << m << endl;
	fori(i,0,m-1) cout << ans[i]-PADDING << endl;

	return 0;
}