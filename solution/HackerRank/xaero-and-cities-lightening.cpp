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
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 5e5+55;


int n, ans, a[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
	ok[u]=0;
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		dfs(v);
		if (!a[v]) if (!a[u]) {
			a[u]=1;
			++ans;
		}
	}
}


int main() {
#ifdef DEBUG
	freopen("xaero-and-cities-lightening.in", "r", stdin);
	freopen("xaero-and-cities-lightening.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) {
			cin >> a[i];
			e[i].clear();
		}
		fori(i,1,n-1) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		filla(ok, 1);
		ans=0;
		dfs(1);
		cout << ans << endl;
	}

	return 0;
}