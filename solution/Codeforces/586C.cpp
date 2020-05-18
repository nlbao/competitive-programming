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


const int MAX_N = 4044;


int n;
ll v[MAX_N], d[MAX_N], p[MAX_N];
bool ok[MAX_N];
vector<int> a;


int main() {
#ifdef DEBUG
	freopen("586C.in", "r", stdin);
	freopen("586C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		cin >> v[i] >> d[i] >> p[i];
		ok[i]=1;
	}

	int ans=0;
	fori(i,1,n) if (ok[i]) {
		++ans;
		a.pb(i);
		ll x=v[i], y=0;
		fori(k,i+1,n) if (ok[k]) {
			p[k]-=x+y;
			if (p[k]<0) {
				ok[k]=0;
				y+=d[k];
			}
			if (x>0) --x;
		}
	}
	cout << ans << endl;
	fori(i,0,ans-1) cout << a[i] << " ";

	return 0;
}