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
#define getBit(x, i) ((x>>i)&1)
#define mmod(x) ((x)%MODULE)

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e3+3;
const int MAX_BIT = 32;
const ll MODULE = 1e6+3;


int n;
int a[MAX_N], g[2][MAX_N][MAX_BIT][2], f[2][MAX_N][MAX_BIT];
ll pow2[MAX_BIT];


int main() {
#ifdef DEBUG
	freopen("4810.in", "r", stdin);
	freopen("4810.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	pow2[0]=1;
	fori(i,1,MAX_BIT-1) pow2[i]=mmod(pow2[i-1]*2);

	while (cin >> n) {
		fori(i,1,n) cin >> a[i];
		sort(a+1, a+1+n);
		filla(g, 0);
		filla(f, 0);
		int t=0;
		fori(i,0,MAX_BIT-1) {
			g[0][0][i][0]=1;
			g[1][0][i][0]=1;
		}
		fori(turn,1,n) {
			int tt=t, y;
			t ^= 1;
			fori(k,1,n) fori(i,0,MAX_BIT-1) {
				f[t][k][i] = f[tt][k][i];
				fori(x,0,1) {
					if (k > turn) {
						g[t][k][i][x] = 0;
						continue;
					}
					y = getBit(a[turn], i) ^ x;
					g[t][k][i][x] = mmod(g[tt][k][i][x] + g[tt][k-1][i][y]);
					if (x==1) {
						f[t][k][i] = mmod(f[t][k][i] + mmod(pow2[i] * g[tt][k-1][i][y]));
					}
				}
			}
		}
		fori(k,1,n) {
			ll s=0;
			fori(i,0,MAX_BIT-1) s = mmod(s + f[t][k][i]);
			cout << s;
			if (k<n) cout << " ";
			else cout << endl;
		}
	}

	return 0;
}