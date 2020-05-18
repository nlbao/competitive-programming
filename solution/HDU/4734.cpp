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


const int MAX_N = 11;
const int MAX_K = 4620;


int crrTurn;
ll b[MAX_N];
string s;
int q[MAX_N][MAX_K], turn[MAX_N][MAX_K], g[MAX_N][MAX_K];


ll calF(int x) {
	stringstream ss;
	ss << x;
	ss >> s;
	ll ans=0, n=sz(s);
	fori(i,0,n-1) ans += ll(s[i]-'0') * (1LL<<(n-i-1));
	return ans;
}


int solve(int n, ll limit, bool less) {
	if (limit<0) return 0;
	if (n<1) return (limit>=0);
	if (limit==0) return 1;
	if (less) return g[n][limit];
	if (turn[n][limit] == crrTurn)
		return q[n][limit];
	int ans=0;
	int r=(less) ? 9 : b[n];
	fori(x,0,r) {
		ll tmp=1LL*limit - 1LL*x*(1LL<<(n-1));
		if (x<b[n]) ans += solve(n-1, tmp, 1);
		else ans += solve(n-1, tmp, less|0);
	}
	turn[n][limit] = crrTurn;
	q[n][limit] = ans;
	return ans;
}


ll solve_0(int b, ll limit) {
	ll ans=0;
	fori(x,0,b) if (calF(x)<=limit) ++ans;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("4734.in", "r", stdin);
	freopen("4734.out", "w", stdout);
#endif
	// ios_base::sync_with_stdio(0);	cin.tie(0);
	// cout.precision(9);
	// cout.setf(ios::fixed, ios::floatfield);

	filla(g, 0);
	fori(x,0,MAX_K-1) g[0][x]=1;
	fori(n,1,MAX_N-1) fori(x,0,MAX_K-1) {
		fori(k,0,9) {
			ll y=x - 1LL*k*(1LL<<(n-1));
			if (y<0) continue;
			g[n][x] += g[n-1][y];
		}
	}

	int nTest;
	scanf("%d", &nTest);
	crrTurn=0;
	filla(turn, 0);
	fori(testid,1,nTest) {
		int x, y;
		scanf("%d%d", &x, &y);
		stringstream ss;
		ss << y;
		ss >> s;
		int n=sz(s);
		fori(i,1,n) b[n-i+1]=s[i-1]-'0';
		++crrTurn;
		ll fa=calF(x);
		int ans=solve(n, fa, 0);
		printf("Case #%d: %d\n", testid, ans);
	}

	return 0;
}