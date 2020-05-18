// https://oi.abcdabcd987.com/summary-of-heavy-light-decomposition
// https://www.spoj.com/problems/QTREE


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


namespace HLD {
const int MAX_N = 2e5+55;

typedef int Matrix[MAX_N+1];

int n, posL, posR, value, treeSize;
int s[MAX_N*4];
vector<int> e[MAX_N];
Matrix depth, size, top, parent, hson, number;


void addEdge(int u, int v) {
	e[u].pb(v);
}


void update(int k, int l, int r) {
	if (l>posR || r<posL) return;
	if (l == r) {
		s[k] = value;
		return;
	}
	int mid = (l+r)>>1, kl = k<<1, kr = kl+1;
	update(kl, l, mid);
	update(kr, mid+1, r);
	s[k] = max(s[kl], s[kr]);
}


int get(int k, int l, int r) {
	if (l>posR || r<posL) return 0;
	if (posL <= l && r <= posR) return s[k];
	int mid = (l+r)>>1, kl = k<<1, kr = kl+1;
	return max(get(kl, l, mid), get(kr, mid+1, r));
}


inline void modify(int pos, int x) {	// change the cost of the edge at pos to x
	posL = posR = pos, value = x;
	update(1, 1, n);
}


inline int query(int l, int r) {
	posL = l, posR = r;
	return get(1, 1, n);
}


inline int getMax(int a, int b) {	// ask for the maximum edge cost on the path from node a to node b
	int ta = top[a], tb = top[b], res = 0;
	while (ta != tb) {
		if (depth[ta] < depth[tb])
			swap(ta, tb), swap(a, b);
		res = max(res, query(number[ta], number[a]));
		a = parent[ta], ta = top[a];
	}
	if (a == b) return res;
	if (depth[a] > depth[b]) swap(a, b);
	return max(res, query(number[hson[a]], number[b]));
}


void buildTree(int u, int tp) {
	number[u] = ++treeSize, top[u] = tp;
	if (hson[u]) buildTree(hson[u], tp);
	foreach(it, e[u]) {
		int v = *it;
		if (v != parent[u] && v != hson[u])
			buildTree(v, v);
	}
}


void dfs(int u) {
	size[u] = 1, hson[u] = 0;
	foreach(it, e[u]) {
		int v = *it;
		if (v == parent[u]) continue;
		parent[v] = u;
		depth[v] = depth[u]+1;
		dfs(v);
		size[u] += size[v];
		if (size[v] > size[hson[u]])
			hson[u] = v;
	}
}


void init(int nn) {
	n = nn;
	treeSize = 0;
	filla(s, 0);
	fori(i,0,n) e[i].clear();
}
};



const int MAX_N = 2e5+55;
int TestData, road[MAX_N][3];


void Solve()
{
	int n;
	scanf("\n%d", &n);
	HLD::init(n);

	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
		HLD::addEdge(road[i][0], road[i][1]);
		HLD::addEdge(road[i][1], road[i][0]);
	}
	HLD::dfs(1);
	HLD::buildTree(1, 1);

	for (int i = 1; i < n; ++i)
	{
		if (HLD::depth[road[i][0]] > HLD::depth[road[i][1]])
			swap(road[i][0], road[i][1]);
		HLD::modify(HLD::number[road[i][1]], road[i][2]);
	}
	for (int x, y; ; )
	{
		static char s[10];
		scanf("\n%s", s);
		if (s[0] == 'D') return;
		scanf("%d%d", &x, &y);
		if (s[0] == 'Q')
			printf("%d\n", HLD::getMax(x, y));
		else
			HLD::modify(HLD::number[road[x][1]], y);
	}
}


int main()
{
#ifdef DEBUG
	freopen("tmp.in", "r", stdin);
	freopen("tmp.out", "w", stdout);
#endif

	scanf("%d", &TestData);
	while (TestData--)
	{
		Solve();
	}
}
