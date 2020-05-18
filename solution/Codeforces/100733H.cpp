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
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6+6;


int n;
string s;
int a[MAX_N], c[33][33], w[33][33];


ll cost(int x, int y) {
	if (x==y) return 0;
	return w[x][y];
}


int main() {
#ifdef DEBUG
	freopen("100733H.in", "r", stdin);
	freopen("100733H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,25) fori(j,0,25) {
		cin >> c[i][j];
		w[i][j]=c[i][j];
	}
	fori(i,0,25) w[i][i]=0;
	fori(k,0,25) fori(i,0,25) fori(j,0,25)
		w[i][j]=min(w[i][j], w[i][k]+w[k][j]);
	cin >> s;
	n=sz(s);
	fori(i,1,n) a[i]=s[i-1]-'a';
	ll ans=0;
	for (int i=1, j=n; i<j; ++i, --j) {
		if (a[i]==a[j]) continue;
		ll t=1e9;
		fori(x,0,25) t=min(t, cost(a[i], x)+cost(a[j], x));
		ans+=t;
	}
	cout << ans << endl;

	return 0;
}