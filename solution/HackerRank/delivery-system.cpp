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


const int MAX_N = 2e5+55;
const int oo = 1e9;


int n, m, nA, nC, nTime;
int num[MAX_N], low[MAX_N], deg[MAX_N], c[MAX_N], f[MAX_N], id[MAX_N];
bool ok[MAX_N], a[MAX_N], inAns[MAX_N];
vector<int> e[MAX_N], e2[MAX_N], b[MAX_N], ans;
stack<int> stk;


void dfs(int u) {
	num[u]=low[u]=++nTime;
	stk.push(u);
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		if (num[v]) low[u]=min(low[u], num[v]);
		else {
			dfs(v);
			low[u]=min(low[u], low[v]);
		}
	}
	if (low[u]==num[u]) {
		b[++nC].clear();
		int v=-1;
		while (v!=u) {
			v=stk.top();	stk.pop();
			c[v]=nC;
			ok[v]=0;
			if (a[v]) b[nC].pb(v);
		}
		sort(b[nC].begin(), b[nC].end());
	}
}


void dfs_1(int u) {
	ok[u]=0;
	f[u]=(a[u])?id[u]:oo;
	foreach(it, e2[u]) {
		int v=*it;
		if (ok[v]) dfs_1(v);
		f[u]=min(f[u], f[v]);
	}
}


void dfs_2(int u) {
	ok[u]=0;
	if (a[u]) {
		foreach(it, b[u]) ans.pb(*it);
		inAns[u]=1;
	}
	int t=oo;
	foreach(it, e2[u]) {
		int v=*it;
		if (!ok[v]) continue;
		t=min(t, f[v]);
	}
	foreach(it, e2[u]) {
		int v=*it;
		if (!ok[v] || f[v]!=t) continue;
		dfs_2(v);
		break;
	}
}


bool solve() {
	ans.clear();
	fori(i,1,nC) a[i]=!b[i].empty();
	int root=-1, nTime=0;
	queue<int> q;
	fori(i,1,nC) if (deg[i]==0) q.push(i);
	while (!q.empty()) {
		int u=q.front();	q.pop();
		id[u]=++nTime;
		if (root<0 && a[u]) root=u;
		foreach(it, e2[u]) {
			int v=*it;
			if ((--deg[v])==0) q.push(v);
		}
	}
	filla(ok, 1);
	dfs_1(root);
	filla(ok, 1);
	filla(inAns, 0);
	dfs_2(root);
	fori(i,1,nC) if (a[i] && !inAns[i]) return 0;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("delivery-system.in", "r", stdin);
	freopen("delivery-system.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m >> nA;
		fori(i,1,n) {
			e[i].clear();
			a[i]=deg[i]=0;
		}
		fori(i,1,nA) {
			int x;
			cin >> x;
			a[x]=1;
		}
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			++deg[y];
		}
		filla(ok, 1);
		filla(num, 0);
		nC=nTime=0;
		fori(i,1,n) if (deg[i]==0) dfs(i);
		fori(i,1,n) if (ok[i]) dfs(i);
		fori(i,1,nC) {
			e2[i].clear();
			deg[i]=0;
		}
		fori(u,1,n) foreach(it, e[u]) {
			int v=*it;
			if (c[u]==c[v]) continue;
			e2[c[u]].pb(c[v]);
			++deg[c[v]];
		}
		if (!solve()) cout << "-1\n";
		else {
			fori(i,1,nA) cout << ans[i-1] << " ";
			cout << endl;
		}
	}

	return 0;
}