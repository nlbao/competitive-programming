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


const int MAX_N = 1e5+5;
const int MAX_K = 1e6+6;
const ll MODULE = 1e6+3;


#define mmod(x) ((x)%MODULE)


pii ans;
int n, crrTurn, crrCut, colorTurn;
vector<int> e[MAX_N];
ll d[MAX_N], K;
int value[MAX_N], nChild[MAX_N], g[MAX_N], p[MAX_N], q[MAX_N];
int turn[MAX_N], color[MAX_K], pos[MAX_K], inv[MAX_K];
bool isCut[MAX_N];


ll mpow(ll a, ll n) {
	if (n<1) return 1;
	if (n==1) return mmod(a);
	ll t=mpow(a,n>>1);
	t=mmod(t*t);
	if (n&1) return mmod(t*a);
	return t;
}


inline void updateAns(int x, int y) {
	if (x>y) swap(x, y);
	ans = min(ans, mp(x, y));
}


int bfs(int u) {
	++crrTurn;
	int l=1, r=1, maxD=1, ans=u;
	q[1]=u;	d[u]=1;
	while (l<=r) {
		u=q[l++];
		if (d[u]>maxD) {
			maxD=d[u];
			ans=u;
		}
		foreach(it, e[u]) {
			int v=*it;
			if (isCut[v] || turn[v]==crrTurn) continue;
			p[v]=u;
			d[v]=d[u]+1;
			q[++r]=v;
			turn[v]=crrTurn;
		}
	}
	return ans;
}


void dfs_1(int u) {
	turn[u]=crrTurn;
	int y = mmod(K * inv[mmod(d[u] * value[crrCut])]);
	if (color[y]==colorTurn)
		updateAns(u, pos[y]);
	foreach(it, e[u]) {
		int v=*it;
		if (isCut[v] || turn[v]==crrTurn) continue;
		d[v] = mmod(d[u] * value[v]);
		dfs_1(v);
	}
}


void dfs_2(int u) {
	turn[u]=crrTurn;
	int y=d[u];
	if (color[y]!=colorTurn || u<pos[y])
		pos[y]=u;
	color[y]=colorTurn;
	foreach(it, e[u]) {
		int v=*it;
		if (isCut[v] || turn[v]==crrTurn) continue;
		d[v] = mmod(d[u] * value[v]);
		dfs_2(v);
	}
}


void solve(int u) {
	int x=bfs(u);
	for (int i=0, len=d[u]; i < len/2; ++i)
		x=p[x];
	crrCut=x;
	isCut[x]=1;
	color[1] = ++colorTurn;
	pos[1] = x;
	foreach(it, e[x]) {
		int v=*it;
		if (isCut[v]) continue;
		++crrTurn;
		d[v]=value[v];
		dfs_1(v);
		++crrTurn;
		dfs_2(v);
	}
	foreach(it, e[x]) {
		int v=*it;
		if (isCut[v]) continue;
		solve(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("4812.in", "r", stdin);
	freopen("4812.out", "w", stdout);
#endif
	fori(i,0,MAX_K-1) inv[i]=mpow(i, MODULE-2);

	while (scanf("%d", &n) == 1) {
		int tmp;
		scanf("%d", &tmp);
		K=tmp;
		fori(i,1,n) {
			scanf("%d", &value[i]);
			e[i].clear();
		}
		fori(i,1,n-1) {
			int x, y;
			scanf("%d%d", &x, &y);
			e[x].pb(y);
			e[y].pb(x);
		}

		ans=mp(MAX_N, MAX_N);
		fori(i,1,n) isCut[i]=0;
		filla(color, 0);
		crrTurn=colorTurn=0;
		solve(1);
		if (ans.fr >= MAX_N) printf("No solution\n");
		else printf("%d %d\n", ans.fr, ans.sc);
	}

	return 0;
}