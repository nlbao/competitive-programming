#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 111;
const int oo = 1e9;


int a[MAX_N][MAX_N], f[MAX_N][MAX_N][MAX_N], g[MAX_N][MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("6848.in", "r", stdin);
	freopen("6848.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int n, m;
		cin >> n >> m;
		fori(i,1,n) fori(j,1,m) cin >> a[i][j];
		int limit=min(n, m);
		fori(i,0,n) {
			fori(k,0,limit) f[i][0][k]=0, g[i][0][k]=oo;
			g[i][0][0]=0;
		}
		fori(i,0,m) {
			fori(k,0,limit) f[0][i][k]=0, g[0][i][k]=oo;
			g[0][i][0]=0;
		}
		fori(i,1,n) fori(j,1,m) {
			f[i][j][0]=g[i][j][0]=0;
			fori(k,1,limit) {
				f[i][j][k]=max(f[i][j-1][k], f[i-1][j][k]);
				f[i][j][k]=max(f[i][j][k], f[i-1][j-1][k-1]+a[i][j]);
				g[i][j][k]=min(g[i][j-1][k], g[i-1][j][k]);
				g[i][j][k]=min(g[i][j][k], g[i-1][j-1][k-1]+a[i][j]);
			}
		}
		int ans=0;
		fori(k,1,limit) if ((k<<1)<=limit) ans=max(ans, f[n][m][k]-g[n][m][k<<1]);
		cout << ans << endl;
	}

	return 0;
}