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

const int MAX_N = int(1e5)+5;

struct Treap {
	int prior, cnt;
	int f, first, last, value;
	Treap *l, *r;
	Treap(int _value = 0) {
		value = first = last = _value;
		prior = rand();
		cnt = 1;
		f = 1;
		l = r = NULL;
	}
};

typedef Treap* pTreap;

pTreap root;


inline int getCnt(pTreap p) {	return p ? p->cnt : 0; }
inline int getF(pTreap p) {	return p ? p->f : 0;	}

inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
	p->first = p->last = p->value;
	p->f = 1;
	if (p->l) {
		p->f += p->l->f - 1 + int(p->l->last != p->value);
		p->first = p->l->first;
	}
	if (p->r) {
		p->f += p->r->f - 1 + int(p->r->first != p->value);
		p->last = p->r->last;
	}
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


void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	if (!p) u = v = NULL;
	else {
		int pKey = getCnt(p->l) + add;
		if (key <= pKey)
			split(p->l, u, p->l, key, add), v = p;
		else
			split(p->r, p->r, v, key, pKey+1), u = p;
	}
	upNode(u);
	upNode(v);
}


void insert(pTreap &p, int key, int value) {
	pTreap node = new Treap(value), u, v;
	split(p, u, v, key);
	merge(p, u, node);
	merge(p, p, v);
}


void erase(pTreap &p) {
	if (!p) return;
	erase(p->l);
	erase(p->r);
	delete p;
	p = NULL;
}


void move(pTreap &p, int l, int r) {
	pTreap t1, t2, t3;
	split(p, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	merge(p, t2, t1);
	merge(p, p, t3);
}


int cal(pTreap p, int l, int r) {
	pTreap t1, t2, t3;
	split(p, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	int ans = getF(t2);
	merge(p, t1, t2);
	merge(p, p, t3);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("CHEFC.in", "r", stdin);
	freopen("CHEFC.out", "w", stdout);
#endif
	srand(time(NULL));
	root = NULL;

	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 0; i < n; ++i) {
			int x = read();
			insert(root, i, x);
		}

		int m = read();
		for (int i = 0; i < m; ++i) {
			int t, l, r;
			scanf("%d%d%d", &t, &l, &r);
			--l, --r;
			if (t == 1) printf("%d\n", cal(root, l, r));
			else move(root, l, r);
		}
		erase(root);
	}
	return 0;
}