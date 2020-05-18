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


const int MAX_N = 2e4+44;


int n, sum;
int a[MAX_N], g[MAX_N];
vector<int> e[MAX_N], b;


void dfs(int u) {
	foreach(it, e[u]) dfs(*it);
	b.clear();
	foreach(it, e[u]) b.pb(g[*it]);
	sort(b.begin(), b.end());
	g[u]=0;
	foreach(it, b) {
		int x=*it;
		if (x>g[u]) break;
		g[u]=x+1;
	}
	if (a[u]&1) sum ^= g[u];
}


int main() {
#ifdef DEBUG
	freopen("6803.in", "r", stdin);
	freopen("6803.out", "w", stdout);
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
		fori(i,1,n) {
			int x;
			cin >> x;
			e[x].pb(i);
		}
		sum=0;
		dfs(1);
		cout << "Case #" << testid << ": ";
		if (sum) cout << "first\n";
		else cout << "second\n";
	}

	return 0;
}