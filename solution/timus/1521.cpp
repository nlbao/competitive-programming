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
inline void upCnt(pTreap p) {	if (p) p->cnt = 1 + getCnt(p->l) + getCnt(p->r);	}


int limit;
pTreap root = NULL;


void merge(pTreap &p, pTreap u, pTreap v) {
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upCnt(p);
}


void split(pTreap p, int key, pTreap &u, pTreap &v) {
	if (!p) u = v = NULL;
	else if (key < p->key)
		split(p->l, key, u, p->l), v = p;
	else
		split(p->r, key, p->r, v), u = p;
	upCnt(u);
	upCnt(v);
}


void insert(pTreap &p, pTreap node) {
	if (!p) p = node;
	else if (node->prior > p->prior)
		split(p, node->key, node->l, node->r), p = node;
	else
		insert(node->key < p->key ? p->l : p->r, node);
	upCnt(p);
}


void remove(pTreap &p, int key) {
	if (!p) return;
	if (p->key == key) {
		pTreap q = p;
		merge(p, p->l, p->r);
		delete q;
	}
	else remove(key < p->key ? p->l : p->r, key);
	upCnt(p);
}


int findKth(pTreap p, int k) {
	if (!p) return -1;
	int sz = 1 + getCnt(p->l);
	if (k == sz) return p->key;
	else if (k < sz) return findKth(p->l, k);
	else return findKth(p->r, k-sz);
}


int main() {
#ifdef DEBUG
	freopen("1521.in", "r", stdin);
	freopen("1521.out", "w", stdout);
#endif
	srand(time(NULL));
	root = NULL;

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		insert(root, new Treap(i));

	int m = n;
	for (int i = 1, x = k; i <= m; ++i) {
		int ans = findKth(root, x);
		printf("%d\n", ans);
		remove(root, ans);
		if (i < m) {
			--n;
			x = (x+k-1)%n;
			if (x == 0) x = n;
		}
	}
	return 0;
}