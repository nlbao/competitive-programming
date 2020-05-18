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
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 5055;


ll a[MAX_N], s[MAX_N], f[2][MAX_N][2], g[MAX_N];
int q[MAX_N];


int main() {
#ifdef DEBUG
	freopen("COFFEE.in", "r", stdin);
	freopen("COFFEE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int n, K, D;
		ll M, ans=0;
		cin >> n >> K >> D >> M;
		s[0]=0;
		fori(i,1,n) {
			cin >> a[i];
			s[i]=s[i-1]+a[i];
		}

		int t=0;
		filla(f, 0);
		fori(i,1,n) f[t][i][0]=s[i];
		fori(turn,1,K) {
			int tt=t, l=1, r=0;
			t^=1;
			fori(i,1,n) {
				f[t][i][0]=f[t][i][1]=0;
				if (i-1>=turn) {
					if (i-1==turn) f[t][i][0]=f[t][i-1][1] + M*a[i];
					else f[t][i][0]=max(f[t][i-1][0] + a[i], f[t][i-1][1] + M*a[i]);
					while (l<=r && q[l]<i-D) ++l;
					if (l<=r) f[t][i][0]=max(f[t][i][0], g[q[l]] + M*s[i]);
				}
				if (i>=turn) {
					if (i==turn) f[t][i][1]=f[tt][i-1][1];
					else f[t][i][1]=max(f[tt][i-1][0], f[tt][i-1][1]);
					g[i]=f[t][i][1]-M*s[i];
					while (l<=r && g[q[r]]<=g[i]) --r;
					q[++r]=i;
				}
				if (turn==K && i>=turn) {
					ans=max(ans, f[t][i][1]);
					if (i-1>=turn) ans=max(ans, f[t][i][0]);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}