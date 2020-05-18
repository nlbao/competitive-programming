#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 2*int(1e5) + 5;

struct Node {
	int cnt;
	int pLeft, pRight;
	Node(int cnt, int pLeft, int pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {}
};


int n, nQ, minValue, maxValue, nNode;
int a[MAX_N];
map<int, int> id;
int root[MAX_N];
vector<Node> nodes;


inline int getCnt(int p) {		return p ? nodes[p].cnt : 0;	}
inline int getLeft(int p) {		return p ? nodes[p].pLeft : 0;	}
inline int getRight(int p) {	return p ? nodes[p].pRight : 0; }

inline int newNode(int cnt, int l, int r) {
	++nNode;
	nodes.push_back(Node(cnt, l, r));
	return nNode-1;
}


int update(int p, int l, int r, int pos) {
	if (l > r) return 0;
	if (l > pos || r < pos) return p;
	if (l == r) return newNode(getCnt(p) + 1, 0, 0);
	int mid = (l+r)>>1;
	return newNode(
		getCnt(p) + 1,
		update(getLeft(p), l, mid, pos),
		update(getRight(p), mid+1, r, pos)
	);
}


int get(int a, int b, int l, int r) {
	if (l > r || minValue > maxValue) return 0;
	if (l > maxValue || r < minValue) return 0;
	if (minValue <= l && r <= maxValue)
		return getCnt(b) - getCnt(a);
	int mid = (l+r)>>1;
	return get(getLeft(a), getLeft(b), l, mid) + get(getRight(a), getRight(b), mid+1, r);
}



int main() {
#ifdef DEBUG
	freopen("CHEFINV.in", "r", stdin);
	freopen("CHEFINV.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		id[a[i]];
	}
	int m = 0;
	tr(id, it) it->second = ++m;
	for (int i = 1; i <= n; ++i)
		a[i] = id[a[i]];

	ll ans = 0;
	nNode = 0;
	root[0] = newNode(0, 0, 0);
	for (int i = 1; i <= n; ++i) {
		minValue = a[i]+1,	maxValue = m;
		ans += get(root[0], root[i-1], 1, m);
		root[i] = update(root[i-1], 1, m, a[i]);
	}

	while(nQ--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v) {
			printf("%lld\n", ans);
			continue;
		}
		if (u > v) swap(u, v);
		ll res = ans;
		minValue = 1,	maxValue = a[u]-1;
		res -= get(root[u], root[v], 1, m);
		minValue = a[u]+1,	maxValue = m;
		res += get(root[u], root[v], 1, m);
		if (v > u+1) {
			minValue = 1,	maxValue = a[v]-1;
			res += get(root[u], root[v-1], 1, m);
			minValue = a[v]+1,	maxValue = m;
			res -= get(root[u], root[v-1], 1, m);
		}
		printf("%lld\n", res);
	}
	return 0;
}