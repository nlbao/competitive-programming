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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N=1e3+4;
const ll MODULE=1e9+7;


ll f[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("6801.in", "r", stdin);
	freopen("6801.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int n, k;
		cin >> n >> k;
		int m=0;
		fori(i,1,n) {
			int x;
			cin >> x;
			if (x) ++m;
		}
		filla(f, 0);
		f[0][0]=1;
		fori(i,1,k)
			fori(j,0,n)
				f[i][j] = (j*f[i-1][j-1] + ll(n-j)*f[i-1][j+1])%MODULE;
		cout << "Case #" << testid << ": " << f[k][m] << endl;
	}

	return 0;
}