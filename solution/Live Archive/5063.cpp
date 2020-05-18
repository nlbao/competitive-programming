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


ll solve(int len, int x) {
	ll ans=0;
	filla(f, 0);
	g[0][0]=1;
	fori(i,1,len) {
		g[i][0]=1;
		fori(j,1,min(a[x], i)) {
			f[i][j]=(f[i-1][j] + (f[i-1][j-1] + g[i-1][j-1] * (p10[i-1] * x)%MOD)) % MOD;
			g[i][j]=(g[i-1][j] + g[i-1][j-1]) % MOD;
		}
	}
	fori(i,1,min(a[x],len)) {
		ll t=f[len][i] * c[sumA-i][len-i];
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("5063.in", "r", stdin);
	freopen("5063.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(c, 0);
	c[0][0]=1;
	fori(i,1,MAX_N-1) {
		c[i][0]=c[i][i]=1;
		fori(j,1,i-1) c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}

	int nTest=read();
	while (nTest--) {
		sumA=0;
		fori(i,1,9) {
			cin >> a[i];
			sumA+=a[i];
		}
		ll ans=0;
		fori(len,1,sumA) fori(i,1,9) ans=(ans+solve(len, i))%MOD;
		cout << ans << endl;
	}

	return 0;
}