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


const int MAX_N = 66;
const int oo = 1e9;


int n, sum;
int a[MAX_N], b[MAX_N];


int solve(int start, int val) {
	filla(b, 0);
	b[start]=val;
	int ss=sum-val;
	fori(i,start+1,n) if (ss>0) {
		b[i]=b[i-1]+1;
		ss-=b[i];
		if (ss<=0) break;
	}
	if (ss!=0) return oo;
	fori(i,2,n) if (b[i]!=b[i-1]+1) return oo;
	int ans=0;
	fori(i,1,n) ans+=abs(a[i]-b[i]);
	return ans/2;
}


int main() {
#ifdef DEBUG
	freopen("PCHIPS.in", "r", stdin);
	freopen("PCHIPS.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		sum=0;
		fori(i,1,n) {
			cin >> a[i];
			sum+=a[i];
		}
		if (sum==0) {
			if (n==1) cout << 0 << endl;
			else cout << -1 << endl;
			continue;
		}
		int ans = oo;
		fori(val,0,sum) ans = min(ans, solve(1, val));
		if (ans>=oo) ans=-1;
		cout << ans << endl;
	}

	return 0;
}