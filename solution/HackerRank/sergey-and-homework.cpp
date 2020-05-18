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


const int MAX_N = 1e5+15;


int n;
ll K;
ll a[MAX_N], b[MAX_N], f[MAX_N];


void get(ll limit) {
	fori(i,1,n) {
		f[i] = a[i] - limit/b[i];
		f[i] = max(f[i], 0LL);
		f[i] = min(f[i], a[i]);
		while (f[i]<a[i] && (a[i]-f[i])*b[i] > limit) ++f[i];
		while (f[i]>0 && (a[i]-(f[i]-1))*b[i] <= limit) --f[i];
	}
}


ll cal(ll limit) {
	get(limit);
	ll ans=0;
	fori(i,1,n) ans+=f[i];
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("sergey-and-homework.in", "r", stdin);
	freopen("tmp.in", "r", stdin);
	freopen("sergey-and-homework.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> K;
	fori(i,1,n) cin >> a[i];
	fori(i,1,n) cin >> b[i];
	ll sa=0;
	fori(i,1,n) sa+=a[i];
	K=min(K, sa);
	ll l=0, r=1e18, ans=1e18;
	while (l<=r) {
		ll mid=(l+r)/2;
		ll t=cal(mid);
		if (t==K) {
			ans=mid;
			r=mid-1;
		}
		else if (t<K) r=mid-1;
		else l=mid+1;
	}
	get(ans);
	fori(i,1,n) cout << a[i]-f[i] << " ";

	return 0;
}