#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e3 + 33;


int n;
string s;
int a[MAX_N], f[MAX_N], win[3][3];


int main() {
#ifdef DEBUG
	freopen("100712B.in", "r", stdin);
	freopen("100712B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(win, 0);
	win[0][1]=win[1][2]=win[2][0]=1;
	win[1][0]=win[2][1]=win[0][2]=-1;

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		cin >> s;
		fori(i,1,n) a[i]=s[i-1]=='R' ? 0 : s[i-1]=='S' ? 1 : 2;
		f[n+1]=0;
		ford(i,n,1) f[i]=f[i+1]+win[1][a[i]];
		ll ans=0, c0=0;
		if (f[1]>0) ++ans;
		int c1=0;
		fori(j,1,n) {
			c1+=win[2][a[j]];
			if (c1+f[j+1]>0) ++ans;
		}
		fori(i,1,n) {
			c0+=win[0][a[i]];
			if (c0+f[i+1]>0) ++ans;
			int c1=0;
			fori(j,i+1,n) {
				c1+=win[2][a[j]];
				if (c0+c1+f[j+1]>0) ++ans;
			}
		}
		cout << ans << endl;
	}

	return 0;
}