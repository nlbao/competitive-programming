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


const int MAX_N = 5e5+5;


int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("591C.in", "r", stdin);
	freopen("591C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=read();
	fori(i,1,n) cin >> a[i];

	filla(b, 0);
	for (int i=1, j=1; i<=n; i=j) {
		while (j<=n && a[j]==1) ++j;
		if (j-i>1)
			fori(k,i,j-1) b[k]=1;
		++j;
	}
	b[0]=a[0];
	b[n]=a[n];

	int c=0;
	for (int i=2, j=i; i<n; i=j) {
		while (i<n && b[i]==1) ++i;
		if (i>=n) break;
		j=i;
		while (j<n && b[j]!=1) ++j;
		int t=1;
		fori(k,i,j-1) if (a[k]) ++t;
		c=max(c, t);
		if (t==0 && j==i+1 && b[i-1]==1 && b[j]==1) c=max(c, 1);
		// cout << i << " " << j << ": " << t << endl;
	}

	fori(i,3,n-1) if (a[i] && b[i-2]) b[i-1]=b[i]=1;

	cout << c << endl;
	fori(i,1,n) cout << b[i] << " ";

	return 0;
}