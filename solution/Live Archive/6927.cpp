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
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


const int MAX_N = 1011;
const int MAX_D = 12;
const int MAX_F = 1<<MAX_D;


int n;
vector<int> e[MAX_N], up[MAX_N], a;
int f[MAX_F], p[MAX_N];
bool ok[MAX_N], path[MAX_N][MAX_N], edge[MAX_N][MAX_N];


int dfs(int u) {
	ok[u]=0;
	int ans=0;
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		p[v]=u;
		ans += dfs(v);
	}
	a.clear();
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]==u) a.pb(v);
	}

	// paths from 1 child to u
	int m=a.size();
	fori(i,0,m-1) {
		int v=a[i];
		bool ck=0;
		foreach(x,up[v]) if (path[*x][u]) {
			++ans;
			ck=1;
			break;
		}
		if (ck) up[v].clear();
	}

	// create edges between children
	fori(i,0,m-1) fori(j,i+1,m-1) {
		edge[i][j]=edge[j][i]=0;
		foreach(x,up[a[i]]) {
			foreach(y,up[a[j]]) if (path[*x][*y]) {
				edge[i][j]=edge[j][i]=1;
				break;
			}
			if (edge[i][j]) break;
		}
	}

	// find maximum matching between children
	int nMask=(1<<m)-1;
	fori(mask,0,nMask) {
		f[mask]=0;
		if (__builtin_popcount(mask)<2) continue;
		fori(i,0,m-1) if (mask&(1<<i)) fori(j,i+1,m-1) if(mask&(1<<j)) {
			if (edge[i][j])
				f[mask]=max(f[mask], f[mask-(1<<i)-(1<<j)] + 1);
		}
	}
	ans += f[nMask];

	// find nodes are accessible from u
	up[u].clear();
	up[u].pb(u);
	fori(i,0,m-1) if (f[nMask-(1<<i)] == f[nMask]) {
		int v=a[i];
		foreach(it,up[v]) up[u].pb(*it);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6927.in", "r", stdin);
	freopen("6927.out", "w", stdout);
#endif
	int nTest;
	scanf("%d", &nTest);
	while (nTest--) {
		scanf("%d", &n);
		fori(i,1,n) {
			ok[i]=1;
			e[i].clear();
			fori(j,1,n) path[i][j]=0;
		}
		fori(i,1,n-1) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].pb(y);
			e[y].pb(x);
		}

		int m;
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			path[x][y]=path[y][x]=1;
		}
		p[1]=-1;
		printf("%d\n", dfs(1));
	}

	return 0;
}