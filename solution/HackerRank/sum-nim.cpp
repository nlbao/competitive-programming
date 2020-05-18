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
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 44;


int n;
ll a[MAX_N], b[MAX_N], f[MAX_N];

typedef unordered_map<ll, ll> node;
node q[2];


#define getBit(x, i) ((x>>(i-1))&1LL)


void generate(int id, int len) {
	q[id].clear();
	int nMask=(1<<len)-1;
	fori(mask,0,nMask) {
		if (getBit(mask,len)==0) continue;
		ll x=0, c=0;
		for (int i=1; i<=len; ++i) {
			c+=b[i];
			if (getBit(mask,i)==1) {
				x^=c;
				c=0;
			}
		}
		node::iterator it=q[id].find(x);
		if (it!=q[id].end()) ++it->sc;
		else q[id][x]=1;
	}
}


int main() {
#ifdef DEBUG
	freopen("sum-nim.in", "r", stdin);
	freopen("sum-nim.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	if (n==1) {
		if (a[1]==0) cout << "1\n";
		else cout << "0\n";
		return 0;
	}

	ll ans=0;
	int mid=n/2;
	node::iterator p;
	fori(l,1,mid) {
		fori(k,1,l) b[k]=a[k];
		generate(0, l);
		fori(r,mid+1,n) {
			if (l<mid && r==mid+1) continue;
			if (l==mid && r>mid+1) continue;
			int len=n-r+1;
			fori(k,1,len) b[k]=a[r+k-1];
			generate(1,len);
			ll tmp=0, x, c;
			fori(i,l+1,r-1) tmp+=a[i];
			foreach(it, q[0]) {
				p=q[1].find(tmp ^ (it->fr));
				if (p==q[1].end()) continue;
				ans += (it->sc)*(p->sc);
			}
		}
	}

	fori(l,mid+1,n-1) {
		ll x=0;
		fori(i,1,l) x+=a[i];
		fori(i,l+1,n) b[i-l]=a[i];
		generate(0, n-l);
		node::iterator it=q[0].find(x);
		if (it!=q[0].end()) ans+=it->sc;
	}
	ford(r,mid,2) {
		ll x=0;
		fori(i,r,n) x+=a[i];
		fori(i,1,r-1) b[i]=a[i];
		generate(0, r-1);
		node::iterator it=q[0].find(x);
		if (it!=q[0].end()) ans+=it->sc;
	}
	cout << ans << endl;

	return 0;
}