#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define forr(i,a,b) for (__typeof(b) i=(a); i!=(b)+((a)<(b)?1:-1); i+=((a)<(b)?1:-1))
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


const int MAX_N=1e5+5;


int n;
int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100676E.in", "r", stdin);
	freopen("100676E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	forr(testid,1,nTest) {
		cin >> n;
		forr(i,1,n) cin >> a[i];
		sort(a+1,a+1+n);
		int j=1, ans=0, limit=32;
		forr(i,1,n) {
			while (j<i && a[i]-a[j]>=limit) ++j;
			ans += i-j;
		}
		cout << ans << endl;
	}

	return 0;
}