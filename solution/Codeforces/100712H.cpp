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


int n, m, nTime, nC, nBridge;
int num[MAX_N], low[MAX_N], p[MAX_N], d[MAX_N], c[MAX_N];
bool ok[MAX_N];
stack<int> stk;
vector<pii> e[MAX_N];
vector<int> e2[MAX_N];


void findBridges(int u) {
	num[u]=low[u]=++nTime;
	stk.push(u);
	foreach(it,e[u]) {
		int v=it->sc, id=it->fr;
		if (!ok[id]) continue;
		ok[id]=0;
		if (p[v])
			low[u]=min(low[u], num[v]);
		else {
			p[v]=u;
			findBridges(v);
			low[u]=min(low[u], low[v]);
		}
	}
	bool isBridge=(p[u]>0 && low[u]>=num[u]);
	if (isBridge) ++nBridge;
	if (p[u]<0 || isBridge) {
		++nC;
		int v=-1;
		while (v!=u) {
			v=stk.top();	stk.pop();
			c[v]=nC;
		}
	}
}


int dfs(int u) {
	int ans=u;
	foreach(it,e2[u]) {
		int v=*it;
		if (p[v]) continue;
		p[v]=u;
		d[v]=d[u]+1;
		int k=dfs(v);
		if (d[k]>d[ans]) ans=k;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100712H.in", "r", stdin);
	freopen("100712H.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) e[i].clear();
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(mp(i, y));
			e[y].pb(mp(i, x));
		}

		nTime=nC=nBridge=0;
		while (!stk.empty()) stk.pop();
		fori(i,1,m) ok[i]=1;
		fori(i,1,n) p[i]=0;
		p[1]=-1;
		findBridges(1);

		int ans=nBridge;
		fori(i,1,nC) e2[i].clear();
		fori(u,1,n) {
			foreach(it,e[u]) {
				int v=it->sc;
				if (c[v]==c[u]) continue;
				e2[c[u]].pb(c[v]);
			}
		}
		fori(i,1,nC) p[i]=0;
		p[1]=-1;	d[1]=0;
		int u=dfs(1);
		fori(i,1,nC) p[i]=0;
		p[u]=-1;	d[u]=0;
		int v=dfs(u), len=d[v];
		ans=min(ans, nBridge-len);
		cout << ans << endl;
	}

	return 0;
}