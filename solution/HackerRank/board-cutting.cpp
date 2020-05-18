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


const int MAX_N = 1e6+6;
const ll MOD = 1e9+7;

#define mmod(x) ((x)%MOD)

int n, m;
pii a[2*MAX_N];


int main() {
#ifdef DEBUG
	freopen("board-cutting.in", "r", stdin);
	freopen("board-cutting.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int m, n, c=0;
		cin >> m >> n;
		fori(i,1,m-1) a[++c]=mp(read(), 0);
		fori(i,1,n-1) a[++c]=mp(read(), 1);
		sort(a+1,a+1+c);
		m=n=1;
		ll ans=0;
		ford(i,c,1) {
			if (a[i].sc==0) ans += mmod(1LL*a[i].fr*n), m++;
			else ans += mmod(1LL*a[i].fr*m), n++;
			ans=mmod(ans);
		}
		cout << ans << endl;
	}

	return 0;
}