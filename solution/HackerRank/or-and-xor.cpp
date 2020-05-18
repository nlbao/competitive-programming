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


const int MAX_N = 2e5+15;
const int MAX_P = 21;

int n;
int a[MAX_N], s[MAX_N][MAX_P];
ll k1, k2;


pll getSum(int l, int r) {
	ll s1=0, s2=0, len=r-l+1;
	fori(x,0,MAX_P-1) {
		ll c1=s[r][x]-s[l-1][x];
		ll c0=len-c1;
		s1 += (c1*c0 + c1*(c1-1)/2) * (1LL<<x);
		s2 += (c1*c0) * (1LL<<x);
	}
	return mp(s1, s2);
}


int main() {
#ifdef DEBUG
	freopen("or-and-xor.in", "r", stdin);
	freopen("or-and-xor.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> k1 >> k2;
	fori(i,1,n) cin >> a[i];
	filla(s, 0);
	fori(i,1,n) {
		fori(x,0,MAX_P-1) s[i][x] = s[i-1][x] + ((a[i]>>x)&1);
	}

	ll ans=0;
	int l=1;
	fori(i,2,n) {
		while (l<i) {
			pll p = getSum(l, i);
			ll s1=p.fr, s2=p.sc;
			if (!(s1>k1 && s2>k2)) break;
			++l;
		}
		ans += l-1;
	}
	cout << ans << endl;

	return 0;
}