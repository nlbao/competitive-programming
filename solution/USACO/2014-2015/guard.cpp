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


const int MAX_N = 21;
const int MAX_F = (1<<MAX_N)+4;
const ll oo = 1e9;


int n;
ll H, h[MAX_N], w[MAX_N], s[MAX_N];
ll f[MAX_F];


ll solve() {
	int nMask=(1<<n)-1;
	ll ans=-1;
	filla(f, -1);
	fori(i,1,n) f[1<<(i-1)]=s[i];
	fori(mask,0,nMask) if (f[mask]>=0) {
		ll fw=0, fh=0;
		fori(i,0,n-1) if (mask&(1<<i)) {
			fw+=w[i+1];
			fh+=h[i+1];
		}
		if (fh>=H) ans=max(ans, f[mask]);
		fori(i,0,n-1) if ((mask&(1<<i))==0) {
			int x=mask|(1<<i);
			f[x] = max(f[x], min(f[mask], s[i+1]-fw));
		}
	}
	return ans;
}


int main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> H;
	fori(i,1,n) cin >> h[i] >> w[i] >> s[i];

	ll ans=solve();
	if (ans<0) cout << "Mark is too tall\n";
	else cout << ans << endl;

	return 0;
}