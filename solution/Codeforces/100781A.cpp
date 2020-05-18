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


const int MAX_N = 1e5+15;
const int oo = 1e9;


int n, m, nC, crrTurn, minLen, maxU;
int d[MAX_N], f[MAX_N], g[MAX_N], a[MAX_N], l[MAX_N], r[MAX_N], id[MAX_N];
int turn[MAX_N], p[MAX_N];
vector<int> e[MAX_N];


void findLongest(int u) {
	turn[u]=crrTurn;
	foreach(it, e[u]) {
		int v=*it;
		if (turn[v]==crrTurn) continue;
		d[v]=d[u]+1;
		findLongest(v);
	}
	if (maxU<0 || d[u]>d[maxU]) maxU=u;
}


void dfs_0(int u) {
	f[u]=0;
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]) continue;
		p[v]=u;
		dfs_0(v);
		f[u]=max(f[u], f[v]+1);
	}
}


void dfs_1(int u) {
	minLen = min(minLen, max(f[u], g[u]));
	int m=0;
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]!=u) continue;
		id[++m]=v;
		g[v]=g[u]+1;
	}
	l[0]=r[m+1]=0;
	fori(i,1,m) l[i]=max(l[i-1], f[id[i]]+2);
	ford(i,m,1) r[i]=max(r[i+1], f[id[i]]+2);
	fori(i,1,m) {
		int v=id[i];
		g[v]=max(g[v], max(l[i-1], r[i+1]));
	}
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]!=u) continue;
		dfs_1(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("100781A.in", "r", stdin);
	freopen("100781A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,m) {
		int x, y;
		cin >> x >> y;
		++x, ++y;
		e[x].pb(y);
		e[y].pb(x);
	}

	int preAns=0, ans=oo, nC=0;
	filla(p, 0);
	filla(turn, 0);
	crrTurn=0;
	fori(i,1,n) if (!p[i]) {
		++crrTurn;	maxU=-1;
		d[i]=0;
		findLongest(i);
		++crrTurn;
		d[maxU]=0;
		findLongest(maxU);
		preAns=max(preAns, d[maxU]);

		p[i]=-1;
		dfs_0(i);
		g[i]=0;
		minLen=oo;
		dfs_1(i);
		a[++nC]=minLen;
	}

	l[0]=r[nC+1]=0;
	f[0]=g[nC+1]=0;
	fori(i,1,nC) {
		l[i]=max(l[i-1], a[i]);
		f[i]=max(f[i-1], a[i] + l[i-1] + 2);
	}
	ford(i,nC,1) {
		r[i]=max(r[i+1], a[i]);
		g[i]=max(g[i+1], a[i] + r[i+1] + 2);
	}

	fori(i,1,nC) {
		int tmp = max(l[i-1], r[i+1]) + a[i] + 1;
		tmp = max(tmp, l[i-1] + r[i+1] + 2);
		tmp = max(tmp, max(f[i-1], g[i+1]));
		ans=min(ans, tmp);
	}

	ans=max(ans, preAns);
	cout << ans << endl;

	return 0;
}