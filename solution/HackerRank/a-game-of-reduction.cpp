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


const int MAX_N = 1e6+6;
const int MAX_A = 4;
const ll MOD = 1e9+7;


int a[MAX_N], c[MAX_N][MAX_A];
int g[MAX_A][MAX_N][MAX_A];


#define num(x) int(x-'0')

inline int grundy(int x) {
	if (x<10) return a[x]=0;
	if (a[x]>-1) return a[x];

	set<int> h;
	stringstream ss;	string s;
	ss << x;
	ss >> s;
	int n=sz(s);

	fori(pos,0,n-2) {
		int y=0;
		fori(i,0,pos-1) y=y*10+num(s[i]);
		y=y*10 + (num(s[pos])+num(s[pos+1])) % 10;
		fori(i,pos+2,n-1) y=y*10+num(s[i]);
		h.insert(grundy(y));
	}

	int c=0;
	foreach(it, h) {
		if (*it>c) break;
		++c;
	}
	return c;
}


inline ll mmod(ll x) {
	x %= MOD;
	if (x<0) x+=MOD;
	return x;
}


inline ll mpow(ll a, ll n) {
	if (n<1) return 1;
	if (n==1) return mmod(a);
	ll t=mpow(a, n>>1);
	t=mmod(t*t);
	if (n&1) t *= mmod(a);
	return mmod(t);
}


ll solve(int need, int a[4]) {
	ll f[2][4];
	filla(f, 0);
	int t=0;
	f[t][0]=1;

	fori(i,0,3) {
		int tt=t;
		t^=1;
		fori(x,0,3) f[t][x]=0;
		fori(x,0,3) fori(y,0,3) {
			int z=x^y;
			f[t][z] = mmod(f[t][z] + ((z>3) ? 0 : f[tt][x] * g[i][a[i]][y]));
		}
	}
	if (need) return f[t][need];
	return mmod(f[t][need]-1);
}


int main() {
#ifdef DEBUG
	freopen("a-game-of-reduction.in", "r", stdin);
	freopen("a-game-of-reduction.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);


	filla(a, -1);
	fori(x,0,3) c[0][x]=0;
	fori(i,1,MAX_N-1) {
		fori(x,0,3) c[i][x]=c[i-1][x];
		a[i]=grundy(i);
		++c[i][a[i]];
	}

	// cal G
	filla(g, 0);
	fori(val,0,3) {
		g[val][0][0] = 1;
		fori(i,1,MAX_N-1) {
			fori(x,0,3) {
				int t = x ^ val;
				g[val][i][x] = mmod(g[val][i-1][x] + ((t>3) ? 0 : g[val][i-1][t]));
			}
		}
	}

	int nTest=read();
	while (nTest--) {
		int n, m, tmp = 0, x;
		cin >> n >> m;
		int b[4];
		fori(i,0,3) b[i]=c[n][i];
		fori(i,1,m) {
			cin >> x;
			x=a[x];
			--b[x];
			tmp ^= x;
		}
		ll ans = solve(tmp, b);
		cout << ans << endl;
	}

	return 0;
}