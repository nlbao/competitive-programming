#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#ifdef DEBUG
	#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#else
	#define foreach(it, X) for(auto it = (X).begin(); (it) != (X).end(); (it)++)
#endif
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 5 * int(1e5) + 5;
const int MAX_BIT = 2*MAX_N;
const ll oo = ll(1e9);


struct Treap {
	int key, prior, cnt;
	Treap *l, *r;
	Treap(int _key = 0) {
		key = _key;
		prior = rand();
		cnt = 1;
		l = r = NULL;
	}
};
typedef Treap* pTreap;

inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}
inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
}

void merge(pTreap &p, pTreap u, pTreap v) {
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upNode(p);
}

void split(pTreap p, pTreap &u, pTreap &v, int key) {
	if (!p) u = v = NULL;
	else if (key < p->key)
		split(p->l, u, p->l, key), v = p;
	else
		split(p->r, p->r, v, key), u = p;
	upNode(u);
	upNode(v);
}

void insert(pTreap &p, int key) {
	pTreap u, v;
	split(p, u, v, key);
	merge(p, u, new Treap(key));
	merge(p, p, v);
}

int countLessThan(pTreap p, int value) {
	if (!p) return 0;
	if (value < p->key)
		return countLessThan(p->l, value);
	else
		return getCnt(p->l) + 1 + countLessThan(p->r, value);
}

void remove(pTreap &p) {
	if (!p) return;
	remove(p->l);
	remove(p->r);
	delete p;
	p = NULL;
}

/*------------BIT------------*/
pTreap root[MAX_BIT];
int bit_limit;

void update(int x, int y) {
	while (x <= bit_limit) {
		insert(root[x], y);
		x += x & (-x);
	}
}
// return number (u, v) which have u <= x && v <= y
int get(int x, int y) {
	int ans = 0;
	while (x > 0) {
		ans += countLessThan(root[x], y);
		x -= x & (-x);
	}
	return ans;
}


int n, H, V, nTurn;
ll ans;
vector<pair<pii, int> > e[MAX_N];
bool ok[MAX_N];
int x[MAX_N], y[MAX_N], turn[MAX_N], nChild[MAX_N];
ll sx[MAX_N], sy[MAX_N];
map<ll, int> idX, idY;


void dfs_0(int u) {
	turn[u] = nTurn;
	nChild[u] = 1;
	foreach(it, e[u]) {
		int v = it->second;
		if (ok[v] && turn[v] != nTurn) {
			dfs_0(v);
			nChild[u] += nChild[v];
		}
	}
}


void dfs(int u) {
	turn[u] = nTurn;
	foreach(it, e[u]) {
		int v = it->second;
		if (ok[v] && turn[v] == nTurn) {
			sx[v] = sx[u] + 1LL*it->first.first;
			sy[v] = sy[u] + 1LL*it->first.second;
			dfs(v);
		}
	}
}


void solve(int u) {
	// choose
	++nTurn;
	dfs_0(u);
	int k = -1, tmin = MAX_N;
	foreach(it, e[u]) {
		int v = it->second;
		int tmp = max(nChild[u], cnt - nChild[u]);
		if (ok[v] && k == -1 || tmp < tmin) {
			tmin = tmp;
			k = v;
		}
	}
	u = k;
	cout << u << endl;

	sx[u] = sy[u] = 0;
	dfs(u);

	// init
	int mX = 0, mY = 0, cnt = nChild[u];
	idX.clear(), idY.clear();
	for (int i = 0; i < cnt; ++i) {
		ll x = sx[i], y = sy[i];
		idX[x],		idY[y];
		idX[H-x],	idY[V-y];
	}
	foreach(it, idX) it->second = ++mX;
	foreach(it, idY) it->second = ++mY;

	// calculate
	bit_limit = mX;
	for (int i = 0; i <= mX; ++i) root[i] = NULL;
	for (int i = 0; i < n; ++i) {
		ll x = sx[i], y = sy[i];
		ans += get(idX[H-x], idY[V-y]);
		update(idX[x], idY[y]);
	}

	// clean
	for (int i = 1; i <= mX; ++i) remove(root[i]);

	// decomposition
	ok[u] = false;
	int k = -1, tmin = MAX_N;
	foreach(it, e[u]) {
		int v = it->second;
		if (!ok[v]) continue;
		if (k == -1 || max(nChild[u], cnt - nChild[u]) < tmin) {
			tmin = max(nChild[u], cnt - nChild[u]);
			k = v;
		}
	}
	if (k != -1) solve(k);
}


int main() {
#ifdef DEBUG
	freopen("taxicab-drivers-problem.in", "r", stdin);
	freopen("taxicab-drivers-problem.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin >> n >> H >> V;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		int dx = abs(x[u]-x[v]), dy = abs(y[u]-y[v]);
		e[u].push_back(make_pair(make_pair(dx, dy), v));
		e[v].push_back(make_pair(make_pair(dx, dy), u));
	}

	ans = 0;
	filla(ok, true);
	filla(turn, 0);
	nTurn = 0;
	solve(1);
	cout << ans << '\n';
	cout << (ll(n)*ll(n-1)/2LL) - ans << '\n';
	return 0;
}