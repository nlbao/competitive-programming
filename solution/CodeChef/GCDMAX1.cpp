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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 5e5+15;
const int MAX_A = 1e6+15;


int n, K, gcd, len;
int f[MAX_A], c[MAX_A], a[MAX_N], h[MAX_A];
multiset<int> p[MAX_A];
set<int> listX;


void update(int n, int val) {
	while (n>1) {
		int x = f[n], t = h[n];
		n /= t;
		if (val>0) {
			++c[x];
			p[x].insert(t);
			listX.insert(x);
		}
		else {
			--c[x];
			p[x].erase(p[x].find(t));
			if (p[x].empty()) listX.erase(x);
		}
	}
	len += val;
	gcd = 1;
	foreach(it, listX) {
		int x=*it;
		if (c[x]==len) gcd *= *p[x].begin();
	}
}


int main() {
#ifdef DEBUG
	freopen("GCDMAX1.in", "r", stdin);
	freopen("GCDMAX1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(f, 0);
	fori(i,2,MAX_A-1) if (f[i]==0) {
		f[i]=i;
		h[i]=i;
		ll t=i*i, p=i;
		for (ll j=i+i; j<MAX_A; j+=i) {
			f[j]=i;
			while ((j%t)==0) {
				p = t;
				t *= i;
			}
			h[j]=p;
		}
	}

	cin >> n >> K;
	fori(i,1,n) cin >> a[i];

	gcd=1;
	len=0;
	filla(c, 0);
	int ans=0, j=1;
	fori(i,1,n) {
		update(a[i], 1);
		while (j<=i && gcd<K) {
			update(a[j], -1);
			++j;
		}
		ans=max(1LL*ans, i-j+1);
	}
	cout << ans << endl;

	return 0;
}