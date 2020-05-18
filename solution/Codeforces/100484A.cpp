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


const int MAX_N = 1e4+4;
const int MAX_K = 1e2+4;

int n, MOD;
bool f[MAX_K], g[MAX_K];


inline int mmod(int x) {
	x%=MOD;
	if (x<0) x+=MOD;
	return x;
}


int main() {
#ifdef DEBUG
	freopen("100484A.in", "r", stdin);
	freopen("100484A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> MOD;
	filla(f, 0);
	fori(i,1,n) {
		int x;
		cin >> x;
		x=mmod(x);
		if (i==1) {
			f[x]=1;
			continue;
		}
		filla(g, 0);
		fori(y,0,MOD-1) if (f[y]) {
			g[mmod(x+y)]=1;
			g[mmod(y-x)]=1;
		}
		fori(y,0,MOD-1) f[y]=g[y];
	}
	if (f[0]) cout << "Divisible\n";
	else cout << "Not divisible\n";

	return 0;
}