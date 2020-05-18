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


const int N = 1296000;

bool ok[N+4];


int main() {
#ifdef DEBUG
	freopen("biggest.in", "r", stdin);
	freopen("biggest.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(6);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		ll r, n, h, m, s;
		cin >> r >> n >> h >> m >> s;
		ll d = h*3600 + m*60 + s;
		if (d==0) {
			cout << 360.0 << endl;
			continue;
		}
		filla(ok, 1);
		int x=0, c=0;
		while (ok[x] && c<n) {
			ok[x]=0;
			++c;
			x+=d;
			while (x>=N) x-=N;
		}
		ll ans=0;
		for (int i=0, j; i < N; i=j) {
			j=i+1;
			while (j<N && ok[j]) ++j;
			ans=max(ans, ll(j-i));
		}
		double area=M_PI*r*r;
		cout << area*1.0*ans/N << endl;
	}

	return 0;
}