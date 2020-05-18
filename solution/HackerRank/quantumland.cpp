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


const int MAX_N = 1e5+55;


int n, nTime, nC;
double a[MAX_N];
int num[MAX_N], low[MAX_N], e[MAX_N], deg[MAX_N];
bool ok[MAX_N];
stack<int> stk;
vector<int> c[MAX_N];


void dfs(int u) {
	num[u]=low[u]=++nTime;
	stk.push(u);
	int v=e[u];
	if (ok[v]) {
		if (num[v]) low[u]=min(low[u], num[v]);
		else {
			dfs(v);
			low[u]=min(low[u], low[v]);
		}
	}
	if (low[u]==num[u]) {
		++nC;
		int v=-1;
		while (v!=u) {
			v=stk.top();	stk.pop();
			c[nC].pb(v);
			ok[v]=0;
		}
	}
}


double solve() {
	filla(ok, 1);
	filla(num, 0);
	nC=nTime=0;
	fori(i,1,n) if (deg[i]==0) dfs(i);
	fori(i,1,n) if (ok[i]) dfs(i);
	double ans=0;
	fori(i,1,nC) if (sz(c[i])>1) {
		double t=1;
		foreach(it, c[i]) t*=a[*it];
		ans+=t;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("quantumland.in", "r", stdin);
	freopen("quantumland.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	filla(deg, 0);
	fori(i,1,n) {
		cin >> e[i] >> a[i];
		++deg[e[i]];
		a[i] /= 100;
	}
	cout << solve() << endl;

	return 0;
}