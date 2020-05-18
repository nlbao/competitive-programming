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


const int MAX_N = 1e4+4;
const int MAX_V = 1e2+4;
const int BASE = 60;
const int MAX_LEN = sqr(MAX_V)/BASE+4;


int n;
int p[MAX_N], val[MAX_N], id[MAX_V][MAX_V];
vector<int> e[MAX_N];
ll f[MAX_N][MAX_LEN], tmp[MAX_LEN];


bool cmp(int u, int v) {
	return val[u]<val[v];
}


inline bool getBit(ll mask[], int x, int y) {
	int i=id[x][y]/BASE, j=id[x][y]%BASE;
	return (mask[i]>>j)&1LL;
}


inline void setBit(ll mask[], int x, int y) {
	int i=id[x][y]/BASE, j=id[x][y]%BASE;
	mask[i] |= (1LL<<j);
}


void dfs(int u) {
	sort(e[u].begin(), e[u].end(), cmp);
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]) continue;
		p[v]=u;
		dfs(v);
	}

	int valRoot=val[u], limit=valRoot-1;
	filla(tmp, 0);
	setBit(tmp, valRoot, valRoot);

	foreach(it, e[u]) {
		int v=*it;
		if (p[v]!=u || val[v]>=valRoot) continue;
		fori(x,1,limit) fori(y,x,limit) if (getBit(f[v], x, y)) {
			setBit(tmp, x, y);
			fori(k,1,x-1) if (getBit(tmp, k, x-1)) setBit(tmp, k, y);
		}
	}
	fori(x,1,limit) if (getBit(tmp, x, limit)) setBit(tmp, x, valRoot);

	limit=MAX_V-1;
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]!=u || val[v]<=valRoot) continue;
		fori(x,valRoot+1,limit) fori(y,x,limit) if (getBit(f[v], x, y)) {
			setBit(tmp, x, y);
			fori(k,1,x-1) if (getBit(tmp, k, x-1)) setBit(tmp, k, y);
		}
	}

	fori(x,1,valRoot) fori(y,valRoot,limit)
		if (getBit(tmp, x, y)) setBit(f[u], x, y);
}


int main() {
#ifdef DEBUG
	freopen("UZASTOPNI.in", "r", stdin);
	freopen("UZASTOPNI.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int c=0;
	filla(id, 0);
	fori(x,1,MAX_V-1) fori(y,x,MAX_V-1) id[x][y]=++c;

	cin >> n;
	fori(i,1,n) cin >> val[i];
	fori(i,1,n-1) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}
	filla(f, 0);
	filla(p, 0);
	p[1]=-1;
	dfs(1);
	int ans=0;
	fori(i,1,MAX_V-1) fori(j,i,MAX_V-1) if (getBit(f[1],i,j)) ++ans;
	cout << ans << endl;

	return 0;
}