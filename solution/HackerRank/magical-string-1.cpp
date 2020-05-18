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


const int MAX_N = 5e6+10;


int a[MAX_N], f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("magical-string-1.in", "r", stdin);
	freopen("magical-string-1.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	a[1]=1; a[2]=a[3]=2;
	for (int i=4, j=3; i<MAX_N-4; ++j) {
		if (a[j]==1) {
			a[i]=3-a[i-1];
			++i;
		}
		else {
			a[i]=a[i+1]=3-a[i-1];
			i+=2;
		}
	}
	f[0]=0;
	fori(i,1,MAX_N-1) f[i]=f[i-1]+int(a[i]==1);

	int nQ=read();
	while (nQ--) {
		int t, n;
		cin >> t >> n;
		if (t==1) {
			cout << f[n] << endl;
		}
		else {
			cout << n-f[n] << endl;
		}
	}

	return 0;
}