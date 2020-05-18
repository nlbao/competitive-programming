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


int n, finalAns;
int p[MAX_N], a[MAX_N];
vector<pii> e[MAX_N];
multiset<int, greater<int> > heap;


void dfs(int u) {
	foreach(it, e[u]) {
		int v=it->sc;
		if (p[v]) continue;
		p[v]=u;
		a[v]=it->fr;
		dfs(v);
	}

	heap.clear();
	foreach(it, e[u]) {
		int v=it->sc;
		if (p[v]!=u) continue;
		if (a[v]>0) heap.insert(a[v]);
	}
	if (heap.empty()) {
		finalAns+=a[u];
		return;
	}

	int f=0;
	while (f<a[u] && !heap.empty()) {
		int x=*heap.begin();
		heap.erase(heap.begin());
		++f;	--x;
		if (x>0) heap.insert(x);
	}
	finalAns += a[u]-f;

	while (sz(heap)>1) {
		int x=*heap.begin();	heap.erase(heap.begin());
		int y=*heap.begin();	heap.erase(heap.begin());
		finalAns -= 1;
		--x, --y;
		if (x>0) heap.insert(x);
		if (y>0) heap.insert(y);
	}
}


int main() {
#ifdef DEBUG
	freopen("6039.in", "r", stdin);
	freopen("6039.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) e[i].clear();
		fori(i,1,n-1) {
			int x, y, c;
			cin >> x >> y >> c;
			e[x].pb(mp(c, y));
			e[y].pb(mp(c, x));
		}
		finalAns=0;
		filla(p, 0);
		p[1]=-1;
		a[1]=0;
		dfs(1);
		cout << "Case #" << testid << ": " << finalAns << endl;
	}

	return 0;
}