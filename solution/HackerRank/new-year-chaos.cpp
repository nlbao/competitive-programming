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


const int MAX_N = 1e5+55;


int n;
int a[MAX_N], f[MAX_N];


void update(int i) {
	while (i<=n) {
		f[i]+=1;
		i+=lowbit(i);
	}
}


int get(int i) {
	int ans=0;
	while (i>0) {
		ans+=f[i];
		i-=lowbit(i);
	}
	return ans;
}


ll solve() {
	ll ans=0;
	filla(f, 0);
	for (int i=1; i<=n; ++i) {
		int x=a[i];
		int c=get(x-1);
		if (c<x-3) return -1;
		int d=i-1-c;
		ans += d;
		update(x);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("new-year-chaos.in", "r", stdin);
	freopen("new-year-chaos.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		fori(i,1,n) cin >> a[i];
		ll ans=solve();
		if (ans<0) cout << "Too chaotic" << endl;
		else cout << ans << endl;
	}

	return 0;
}