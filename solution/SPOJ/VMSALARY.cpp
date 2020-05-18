#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;

struct Node {
	int cnt;
	Node *pLeft, *pRight;
	Node (int cnt, Node* pLeft, Node* pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {}
};
inline int getCnt(Node* p)	{	return p ? p->cnt : 0;	}
inline Node* getLeft(Node* p) {	return p ? p->pLeft : NULL;	}
inline Node* getRight(Node* p) {	return p ? p->pRight : NULL;	}


int n, nTime, nCost, value;
int cost[MAX_N], start[MAX_N], finish[MAX_N], a[MAX_N];
vector<int> e[MAX_N];
map<int, int> id;
Node* root[MAX_N];


Node* update(Node* p, int l, int r) {
	if (l > r) return NULL;
	if (l > value || r < value) return p;
	if (l == r) return new Node(getCnt(p)+1, NULL, NULL);
	int mid = (l+r)>>1;
	return new Node (
		getCnt(p)+1,
		update(getLeft(p), l, mid),
		update(getRight(p), mid+1, r)
	);
}


int countLessThan(Node* a, Node* b, int l, int r) {
	if (l > r || l >= value) return 0;
	if (!a && !b) return 0;
	if (r < value) return getCnt(b) - getCnt(a);
	int mid = (l+r)>>1;
	return	countLessThan(getLeft(a), getLeft(b), l, mid)
		+	countLessThan(getRight(a), getRight(b), mid+1, r);
}


void dfs(int u) {
	start[u] = ++nTime;
	a[nTime] = u;
	foreach(it, e[u])
		dfs(*it);
	finish[u] = nTime;
}


int main() {
#ifdef DEBUG
	freopen("VMSALARY.in", "r", stdin);
	freopen("VMSALARY.out", "w", stdout);
#endif
	scanf("%d%d", &n, &cost[1]);
	id[cost[1]];
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d%d", &p, &cost[i]);
		id[cost[i]];
		e[p].push_back(i);
	}
	nCost = 0;
	foreach(it, id)
		it->second = ++nCost;
	for (int i = 1; i <= n; ++i)
		cost[i] = id[cost[i]];

	nTime = 0;
	dfs(1);
	root[0] = new Node(0, NULL, NULL);
	for (int i = 1; i <= n; ++i) {
		value = cost[a[i]];
		root[i] = update(root[i-1], 1, nCost);
	}

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		int l = start[i], r = finish[i];
		value = cost[i];
		ll c = countLessThan(root[l-1], root[r], 1, nCost);
		ans += c*(c-1)/2LL;
	}
	cout << ans << endl;
	return 0;
}