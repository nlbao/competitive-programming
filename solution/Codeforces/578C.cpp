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


const int MAX_N = 2e5+5;
const double EPS = 1e-7;


int n;
ll a[MAX_N], s[MAX_N];


inline double cal(double x) {
	double minS=s[0], maxS=s[0];
	fori(i,1,n) {
		minS=min(minS, 1.0*s[i]-x*i);
		maxS=max(maxS, 1.0*s[i]-x*i);
	}
	return fabs(maxS-minS);
}


int main() {
#ifdef DEBUG
	freopen("578C.in", "r", stdin);
	freopen("578C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	s[0]=0;
	fori(i,1,n) s[i]=s[i-1]+a[i];

	double ans=cal(0);
	double l=-1e18, r=1e18;
	fori(turn,1,200) {
		double l1=l+(r-l)/3;
		double r1=r-(r-l)/3;
		double f1=cal(l1), f2=cal(r1);
		ans=min(ans, min(f1, f2));
		if (f1<f2+EPS) r=r1;
		else l=l1;
	}
	cout << ans << endl;

	return 0;
}