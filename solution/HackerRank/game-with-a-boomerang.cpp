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


const int MAX_N = 1e8+88;


int f[MAX_N];


ll solve(ll n) {
	if (n==1) return 0;
	if (n&1) return (solve(n-1) + 1)%n;
	ll k=n>>1;
	ll t=solve(n-1);
	if (t<k-1) ++t;
	else t+=2;
	t%=n;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("game-with-a-boomerang.in", "r", stdin);
	freopen("game-with-a-boomerang.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);


	f[1]=0;
	fori(n,2,MAX_N-1) {
		if (n&1) f[n]=(f[n-1]+1)%n;
		else {
			int k=n>>1, t=f[n-1];
			if (t<k-1) ++t;
			else t+=2;
			f[n] = t%n;
		}
	}

	// fori(i,1,1000) {
		// if (f[i]==0)
		// cout << i << " " << f[i]+1 << endl;
		// cout << f[i]+1 << endl;
		// if (f[i]==0) cout << endl;
	// }
	cout << endl << "----------" << endl;
	// fori(i,1,1000) if (f[i]==0) cout << i << endl;
	return 0;

	int nTest=read();
	while (nTest--) {
		ll n;
		cin >> n;
		// cout << solve(n)+1 << endl;
		if (n<MAX_N) cout << f[n]+1 << endl;
		else cout << solve(n)+1 << endl;
	}

	return 0;
}