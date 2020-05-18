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


const int MAX_N = 1e5+15;
const int MAX_LOG = 19;
const int MAX_F = 4*MAX_N;


int n, nQ, nA, crrTurn, logN, nTime, nResident, pos, limit;
ll finalAns;
int start[MAX_N], finish[MAX_N], h[MAX_N], a[MAX_N], q[MAX_N], rev_start[MAX_N];
int inQ[MAX_N], inA[MAX_N], p[MAX_N][MAX_LOG], stk[MAX_N];
ll d[MAX_N], c[MAX_N], w[MAX_N];
bool ok[MAX_N];
vector<pii> e[MAX_N];


void dfs(int u) {
	ok[u]=0;
	start[u]=++nTime;
	rev_start[start[u]]=u;
	fori(i,1,logN) {
		if (h[u]-(1<<i)<1) p[u][i]=-1;
		else p[u][i]=p[p[u][i-1]][i-1];
	}
	foreach(it, e[u]) {
		int v=it->sc;
		if (!ok[v]) continue;
		p[v][0]=u;
		h[v]=h[u]+1;
		d[v]=d[u]+it->fr;
		dfs(v);
	}
	finish[u]=nTime;
}


inline int lca(int u, int v) {
	if (h[u]<h[v]) swap(u, v);
	if (h[u]>h[v])
		ford(i,logN,0) if (h[u]-(1<<i)>=h[v]) u=p[u][i];
	if (u==v) return u;
	ford(i,logN,0) if (p[u][i]!=p[v][i]) {
		u=p[u][i];
		v=p[v][i];
	}
	return p[u][0];
}


bool cmp(int i, int j) {	return start[i]<start[j];	}

inline bool isAncestor(int r, int u) {	return start[r]<=start[u] && finish[u]<=finish[r];	}


void dfs_2(int u) {
	c[u]=(inQ[u]==crrTurn)?w[u]:0;
	ll tmp=2*d[u];
	foreach(it, e[u]) {
		int v=it->sc;
		dfs_2(v);
		finalAns -= 1LL*c[u]*c[v]*tmp;
		c[u]+=c[v];
	}
}


ll solve() {
	finalAns=0;
	nA=nQ;
	fori(i,1,nQ) {
		int u=q[i];
		a[i]=u;
		inA[u]=crrTurn;
		finalAns += ll(nResident-w[u]) * w[u] * d[u];
	}

	sort(q+1, q+1+nQ, cmp);
	fori(i,1,nQ-1) {
		int u=lca(q[i], q[i+1]);
		if (inA[u]==crrTurn) continue;
		inA[u]=crrTurn;
		a[++nA]=u;
	}`

	// build new tree
	sort(a+1, a+1+nA, cmp);
	int root=-1, top=0;
	fori(i,1,nA) {
		int u=a[i];
		e[u].clear();
		while (top>0 && finish[stk[top]] < finish[u]) --top;
		int l=1, r=top, t=-1;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (finish[stk[mid]]>=finish[u]) {
				t=stk[mid];
				l=mid+1;
			}
			else r=mid-1;
		}
		if (t<0) root=u;
		else e[t].pb(mp(0, u));
		stk[++top]=u;
	}

	// dfs_2 - get result
	dfs_2(root);
	return finalAns;
}


int main() {
#ifdef DEBUG
	freopen("wccity.in", "r", stdin);
	freopen("wccity.out", "w", stdout);
#endif
	int T;
	scanf("%d%d", &n, &T);
	fori(i,1,n-1) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		e[x].pb(mp(c, y));
		e[y].pb(mp(c, x));
	}

	logN=nTime=0;
	while ((1LL<<(logN+1))<=n) ++logN;
	filla(ok, 1);
	p[1][0]=-1;
	h[1]=1;
	d[1]=0;
	dfs(1);

	fori(i,1,n) e[i].clear();
	filla(inQ, 0);
	filla(inA, 0);
	crrTurn=0;

	while (T--) {
		scanf("%d", &nResident);
		nQ=0;
		++crrTurn;
		fori(i,1,nResident) {
			int x;
			scanf("%d", &x);
			if (inQ[x]==crrTurn) ++w[x];
			else {
				inQ[x]=crrTurn;
				q[++nQ]=x;
				w[x]=1;
			}
		}
		printf("%lld\n", solve());
	}

	return 0;
}