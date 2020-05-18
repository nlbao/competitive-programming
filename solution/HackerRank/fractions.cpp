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


const int MAX_N = 1011;
const int oo = 1e9+7;


int n;
int a[MAX_N];


int cal(int a, int val) {
	// find b: [a/b] == val
	if (val==0) return a+1;
	if (val>a) return oo;
	int b=a/val;
	while (b>1 && (a/b)>val) --b;
	while (b<=a && (a/b)<val) ++b;
	if ((a/b)!=val) return oo;
	while (b>1 && (a/(b-1))==val) --b;
	return b;
}


int solve(int val) {
	int s=0;
	fori(i,1,n) {
		int t=cal(a[i], val);
		if (t>=oo) return oo;
		s+=t;
	}
	return s;
}


int main() {
#ifdef DEBUG
	freopen("fractions.in", "r", stdin);
	freopen("fractions.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	int maxA=0;
	fori(i,1,n) {
		cin >> a[i];
		maxA=max(a[i], maxA);
	}

	int ans=oo;
	fori(x,0,maxA) ans=min(ans, solve(x));
	cout << ans << endl;

	return 0;
}