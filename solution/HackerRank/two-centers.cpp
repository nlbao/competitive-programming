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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 5055;


int n, best, maxDist;
int p[MAX_N], d[MAX_N], f[MAX_N], h[MAX_N];
vector<int> e[MAX_N];
bool ok[MAX_N], visited[MAX_N];
pii a[MAX_N];


void dfs_0(int u) {
	ok[u]=0;
	foreach(it, e[u]) {
		int v=*it;
		if (ok[v]) {
			p[v]=u;
			h[v]=h[u]+1;
			dfs_0(v);
		}
	}
}


void dfs_1(int u) {
	visited[u]=1;
	if (d[u]>d[best]) best=u;
	foreach(it, e[u]) {
		int v=*it;
		if (ok[v] && !visited[v]) {
			d[v]=d[u]+1;
			dfs_1(v);
		}
	}
}


int solve(int u) {
	fori(i,1,n) ok[i]=visited[i];

	filla(visited, 0);
	best=u;	d[u]=0;
	dfs_1(u);
	filla(visited, 0);
	u=best;	d[u]=0;
	dfs_1(u);

	return (d[best]+1)/2;
}


void find(int u) {
	ok[u]=1;
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) {
			d[v]=d[u]+1;
			if (d[v]<=maxDist) find(v);
		}
	}
}


void remove(int u) {
	visited[u]=1;
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]==u && !visited[v] && !ok[v]) remove(v);
	}
}


bool checkRoot(int u) {
	filla(ok, 0);
	filla(visited, 0);
	d[u]=0;
	find(u);
	int c=0, x=-1;
	fori(u,1,n) if (!ok[u]) {
		++c;
		if (c>1) return 0;
		if (solve(u) > maxDist) return 0;
	}
	return 1;
}


bool check(int limit) {
	maxDist=limit;
	fori(i,1,n) if (checkRoot(i)) return 1;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("two-centers.in", "r", stdin);
	freopen("two-centers.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n-1) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}
	filla(ok, 1);
	p[1]=-1;
	dfs_0(1);

	int l=0, r=n, ans=n;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (check(mid)) {
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout << ans << endl;

	return 0;
}