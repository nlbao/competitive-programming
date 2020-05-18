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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const ll MOD = 1e9+7;


int n;
map<int, vector<int> > q;


inline ll mmod(ll x) {
	return x%MOD;
}


int main() {
#ifdef DEBUG
	freopen("ZGSEQ.in", "r", stdin);
	freopen("ZGSEQ.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		q.clear();
		fori(i,1,n) {
			int x;
			cin >> x;
			if (!has(q, x)) q[x] = vector<int>();
			q[x].pb(i);
		}
		ll ans=0;
		foreach(it, q) {
			int x=it->fr;
			int l=has(q, x-1) ? sz(q[x-1])-1 : -1;
			int r=has(q, x+1) ? sz(q[x+1])-1 : -1;
			ll s=0, oldS=0;
			bool ok=0;
			int preP = MAX_N;
			ford(i,sz(q[x])-1,0) {
				int p=q[x][i];
				ll t=1, c=0;
				ans=mmod(ans+1);
				while (l>=0 && q[x-1][l]>p) {
					if (ok) {
						++c;
						t = mmod(t+s);
						ans = mmod(ans+s);
					}
					--l;
				}
				while (r>=0 && q[x+1][r]>p) {
					if (ok) {
						++c;
						t = mmod(t+s);
						ans = mmod(ans+s);
					}
					--r;
				}
				if (p==preP-1) ans=mmod(ans+oldS);
				else if (preP<=n) oldS=mmod(oldS + c*s);
				preP=p;
				s=mmod(s+t);
				// cout << x << ": " << p << " : " << s << " " << t << " " << ans << ", " << oldS << endl;
				ok=1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}