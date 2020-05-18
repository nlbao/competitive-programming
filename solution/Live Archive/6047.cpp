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


const int MAX_N = 1033;
const ll BASE = 1e4+7;


int n, len[MAX_N];
string s;
ll h[MAX_N], g[MAX_N], p[MAX_N];


int main() {
#ifdef DEBUG
	freopen("6047.in", "r", stdin);
	freopen("6047.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=p[i-1]*BASE;

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) {
			cin >> s;
			len[i]=sz(s);
			h[i]=g[i]=0;
			fori(k,0,len[i]-1) h[i]=h[i]*BASE+s[k];
			ford(k,len[i]-1,0) g[i]=g[i]*BASE+s[k];
		}
		ll ans = 0;
		fori(i,1,n) fori(j,1,n) if (i!=j) {
			ll x = h[i] * p[len[j]] + h[j];
			ll y = g[i] + g[j] * p[len[i]];
			if (x == y) ++ans;
		}
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}