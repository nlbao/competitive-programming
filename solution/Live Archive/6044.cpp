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


const int MAX_N = 1e5+55;


int n, m, nTime, nC;
int p[MAX_N], num[MAX_N], low[MAX_N], c[MAX_N], cnt[MAX_N];
vector<int> e[MAX_N], e2[MAX_N];
stack<int> stk;
bool ok[MAX_N];


void dfs(int u) {
	num[u]=low[u]=++nTime;
	stk.push(u);
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v] || v==p[u]) continue;
		if (p[v]) low[u]=min(low[u], num[v]);
		else {
			p[v]=u;
			dfs(v);
			low[u]=min(low[u], low[v]);
		}
	}
	if (low[u]==num[u]) {
		cnt[++nC]=0;
		int v=-1;
		while (v!=u) {
			v=stk.top();	stk.pop();
			c[v]=nC;
			++cnt[nC];
			ok[v]=0;
		}
	}
}


int dfs_2(int u) {
	int ans=1;
	foreach(it, e2[u]) {
		int v=*it;
		if (p[v]) continue;
		p[v]=u;
		ans+=dfs_2(v);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6044.in", "r", stdin);
	freopen("6044.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) {
			e[i].clear();
			e2[i].clear();
		}
		fori(i,1,m) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		filla(ok, 1);
		filla(p, 0);
		nTime=nC=0;
		fori(i,1,n) if (ok[i]) {
			while (!stk.empty()) stk.pop();
			p[i]=-1;
			dfs(i);
		}

		fori(i,1,n) ok[i]=(cnt[c[i]]==1);
		fori(u,1,n) if (ok[u]) {
			foreach(it, e[u]) {
				int v=*it;
				if (ok[v]) e2[u].pb(v);
			}
		}

		ll ans=0;
		filla(p, 0);
		fori(i,1,n) if (ok[i]) {
			p[i]=-1;
			ll t = dfs_2(i);
			ans += t*(t-1)/2;
		}
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}