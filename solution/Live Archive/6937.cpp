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


const int MAX_N = 1e5+5e4+55;
const int MAX_K = 11;


int n, K;
pii a[MAX_N];
int b[MAX_N];
ll f[MAX_N][MAX_K];


ll solve() {
	if (K==0) return max(0, *max_element(b+1,b+1+n));
	if (K>=n) return 0;
	fori(x,0,K) f[n+1][x]=0;
	ford(i,n,1) {
		f[i][0]=max(1LL*b[i], f[i+1][0]);
		fori(x,1,K) {
			ll t=min(1LL*a[i].fr-a[i].sc, -a[i].sc+f[i+1][x-1]);
			f[i][x]=max(f[i+1][x], t);
		}
	}
	return f[1][K];
}


int main() {
#ifdef DEBUG
	freopen("6937.in", "r", stdin);
	freopen("6937.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> K;
		fori(i,1,n) {
			int v, c;
			cin >> v >> c;
			a[i]=mp(v,c);
		}
		sort(a+1,a+1+n);
		fori(i,1,n) b[i]=a[i].fr-a[i].sc;
		cout << solve() << endl;
	}

	return 0;
}