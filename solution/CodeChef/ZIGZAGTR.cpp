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


const int MAX_N = 1e5+5;
const ll MOD = 1e5;


ll f[MAX_N][4];
vector<ll> g;


inline ll mmod(ll x) {
	x%=MOD;
	if (x<0) x+=MOD;
	return x;
}


inline ll calf(int n) {
	ll ans=0;
	fori(i,0,3) ans+=f[n][i];
	return mmod(ans);
}


ll solve_0(int n, bool print=0) {
	int a[111], ans=0;
	fori(i,1,n) a[i]=i;
	do {
		if (n<3) {
			++ans;
			continue;
		}
		bool up = a[1]<a[2], ok=1;
		fori(i,3,n) {
			up=!up;
			if (up ^ (a[i-1]<a[i])) {
				ok=0;
				break;
			}
		}
		if (ok) {
			++ans;
			if (print) {fori(i,1,n) cout << a[i] << " ";	cout << endl;}
		}
	} while (next_permutation(a+1, a+1+n));
	return ans;
}


// ll solve(int n) {
// 	ll ans=0;

// }


void init() {
	g.clear();
	g.pb(0);
	map<ll, ll> a;
	a[-1]=0;	a[0]=-1;
	int k=0, e=1;
	fori(i,0,10-1) {
		int Am=0;
		a[k+e]=0;
		e=-e;
		fori(j,0,i) {
			Am += a[k];
			a[k] = Am;
			k += e;
		}
		if (i&1) g.pb(-a[i/2]);
		else g.pb(-a[-i/2]);
	}
	foreach(it, g) cout << *it << " ";	cout << endl;
}


int main() {
#ifdef DEBUG
	freopen("ZIGZAGTR.in", "r", stdin);
	freopen("ZIGZAGTR.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	// init();
	// return 0;

	// g[0]=g[1]=0;

	filla(f, 0);
	f[1][0]=1;
	// f[2][0]=f[2][1]=1;
	f[2][1]=f[2][2]=1;
	fori(i,3,MAX_N-1) {
		// f[i][0] = mmod(f[i-1][1] + mmod(f[i-1][1] * (i+1)/2));
		// f[i][1] = mmod(f[i-1][0] + mmod(f[i-1][0] * (i/2)));
		f[i][0] = mmod(mmod(f[i-1][1] * (i/2)));
		f[i][1] = mmod(mmod(f[i-1][0] * (1 + i/2)));
		f[i][2] = mmod(mmod(f[i-1][3] * (i+1)/2));
		f[i][3] = mmod(mmod(f[i-1][4] * (1 + (i+1)/2)));
	}

	solve_0(3, 1);

	fori(i,1,10) {
		ll t=solve_0(i);
		// cout << i << " " << calf(i) << endl;
		cout << i << ": " << t << " " << mmod(t) << endl;
	}

	return 0;

	// cout << solve_0(4) << endl;
	// cout << calf(4) << endl;
	// return 0;

	fori(i,1,10) {
		cout << i << ": " << calf(i) << " " << solve_0(i) << endl;
	}

	int nTest=read();
	while (nTest--) {
		int n;
		cin >> n;
		fori(i,1,n) {
			int x;
			cin >> x;
		}
		cout << mmod(f[n][0]+f[n][1]) << endl;
	}

	return 0;
}