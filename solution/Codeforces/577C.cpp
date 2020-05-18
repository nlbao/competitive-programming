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


const int MAX_N = 1e3+33;


int nP, p[MAX_N];
bool ok[MAX_N], isPrime[MAX_N];
vector<int> ans;


int main() {
#ifdef DEBUG
	freopen("577C.in", "r", stdin);
	freopen("577C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	cin >> n;
	filla(ok, 0);
	filla(isPrime, 1);
	nP=0;
	fori(i,2,n) {
		if (isPrime[i]) {
			p[++nP]=i;
			ok[i]=1;
			ans.pb(i);
			for (int j=i*i; j<=n; j+=i)
				isPrime[j]=0;
			continue;
		}
		int x=i;
		fori(k,1,nP) {
			int d=p[k], t=1;
			if (d>x) break;
			while ((x%d)==0) {
				t *= d;
				x /= d;
				if (ok[t]) continue;
				ok[t]=1;
				ans.pb(t);
			}
		}
	}

	sort(ans.begin(), ans.end());
	n=sz(ans);
	cout << n << endl;
	fori(i,0,n-1) cout << ans[i] << " ";

	return 0;
}