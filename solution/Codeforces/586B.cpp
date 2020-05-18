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


const int MAX_N = 111;


int a[2][MAX_N], b[MAX_N], l[MAX_N], r[MAX_N], f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("586B.in", "r", stdin);
	freopen("586B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	cin >> n;
	filla(a, 0);
	fori(x,0,1) fori(i,1,n-1) cin >> a[x][i];
	fori(i,1,n) cin >> b[i];
	filla(l, 0);
	filla(r, 0);
	fori(i,1,n) l[i]=l[i-1]+a[0][i-1];
	ford(i,n,1) r[i]=r[i+1]+a[1][i];
	fori(i,1,n) f[i]=l[i]+b[i]+r[i];
	int ans=1e9;
	fori(i,1,n) fori(j,1,n) if (i!=j) ans=min(ans, f[i]+f[j]);
	cout << ans << endl;

	return 0;
}