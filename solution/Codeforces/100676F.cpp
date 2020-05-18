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


const int MAX_N=1e5+5;


int n, m, c[33];
string s;
vector<int> e[MAX_N];
bool ok[MAX_N], hasQ;


void dfs(int u) {
	ok[u]=0;
	if (s[u-1]=='?') hasQ=1;
	else ++c[s[u-1]-'a'];
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		dfs(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("100676F.in", "r", stdin);
	freopen("100676F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		cin >> s;
		fori(i,1,n) e[i].clear();
		for (int i=1, j=n; i<j; ++i, --j) {
			e[i].pb(j);
			e[j].pb(i);
		}
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		ll ans=1, mod=1e9+7;
		filla(ok, 1);
		fori(i,1,n) if (ok[i]) {
			filla(c,0);
			hasQ=0;
			dfs(i);
			int d=0;
			fori(k,0,26) if (c[k]) ++d;
			if (d==0) ans=(ans*26)%mod;
			if (d>1) {
				ans=0;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}