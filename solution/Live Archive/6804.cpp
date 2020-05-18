#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N=5005;
const int MAX_M=20005;


int n, m;
ll ans, c2[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];


inline void solve(int u) {
	fori(i,1,n) ok[i]=0;
	ok[u]=1;
	foreach(it, e[u]) ok[*it]=1;
	int t=sz(e[u])+1;
	ll c=t-1, d=0;
	foreach(it, e[u]) {
		int v=*it;
		foreach(p, e[v])
			if (ok[*p]) ++c;
			else ++d;
	}
	c/=2;
	c+=d;
	if (t<n-1) ans += c2[n-t] - (m-c);
}


int main() {
#ifdef DEBUG
	freopen("6804.in", "r", stdin);
	freopen("6804.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	c2[0]=0;
	fori(i,1,MAX_N-1) c2[i]=i*(i-1)/2;

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) e[i].clear();
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		ans=0;
		fori(i,1,n) solve(i);
		ans /= 3;
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}