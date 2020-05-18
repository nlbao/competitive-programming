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


int n, nTime;
vector<int> e[MAX_N];
pii f[MAX_N];
bool ok[MAX_N], use[4*MAX_N];
int p[MAX_N];


void dfs(int u) {
	ok[u]=0;
	if (f[u].sc < 1) f[u].sc=++nTime;
	int first=-1, last=-1;
	foreach(it, e[u]) {
		int v=*it;
		if (!ok[v]) continue;
		p[v]=u;
		f[v].fr=f[u].fr;
		if (use[f[u].fr]) {
			f[v].fr=f[u].sc;
			use[f[u].sc]=1;
		}
		else {
			f[v].fr=f[u].fr;
			use[f[u].fr]=1;
		}
		if (first<0) first=v;
		last=v;
	}
	if (first>-1 && first==last && !use[f[u].sc]) {
		f[last].sc=f[u].sc;
		use[f[u].sc]=1;
	}
	foreach(it, e[u]) {
		int v=*it;
		if (p[v]!=u) continue;
		dfs(v);
	}
}


int main() {
#ifdef DEBUG
	freopen("6957.in", "r", stdin);
	freopen("6957.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	while (cin >> n) {
		fori(i,1,n) {
			e[i].clear();
			ok[i]=1;
			f[i]=mp(0, 0);
		}
		fori(i,1,n-1) {
			int x, y;
			cin >> x >> y;
			e[x].pb(y);
			e[y].pb(x);
		}
		nTime=1;
		f[1].fr=1;
		p[1]=-1;
		filla(use, 0);
		dfs(1);
		fori(i,1,n) cout << f[i].fr << " " << f[i].sc << endl;
	}

	return 0;
}