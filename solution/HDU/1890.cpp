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
const int oo = 1e9;


struct Treap {
	int prior, cnt;
	pii value, minValue;
	bool rev;
	Treap *l, *r;

	Treap(pii _value = make_pair(oo, oo)) {
		prior = rand()<<16 ^ rand();
		value = minValue = _value;
		cnt = 1;
		rev = false;
		l = r = NULL;
	}
};
typedef Treap* pTreap;


inline int getCnt(pTreap p) {	return p ? p->cnt : 0;	}
inline pii getMin(pTreap p) {	return p ? p->minValue : make_pair(oo, oo);	}
inline void upNode(pTreap p) {
	if (!p) return;
	p->cnt = 1 + getCnt(p->l) + getCnt(p->r);
	p->minValue = min(p->value, min(getMin(p->l), getMin(p->r)));
}

inline void push(pTreap p) {
	if (p && p->rev) {
		p->rev = false;
		swap(p->l, p->r);
		if (p->l) p->l->rev ^= true;
		if (p->r) p->r->rev ^= true;
	}
}


void merge(pTreap &p, pTreap u, pTreap v) {
	push(u);
	push(v);
	if (!u || !v)
		p = u ? u : v;
	else if (u->prior > v->prior)
		merge(u->r, u->r, v), p = u;
	else
		merge(v->l, u, v->l), p = v;
	upNode(p);
}


void split(pTreap p, pTreap &u, pTreap &v, int key, int add = 0) {
	push(p);
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
	pTreap u, v, q = new Treap(make_pair(value, key));
	split(p, u, v, key);
	merge(p, u, q);
	merge(p, p, v);
}


void erase(pTreap &p) {
	if (!p) return;
	erase(p->l);
	erase(p->r);
	delete p;
	p = NULL;
}


int findXPos(pTreap p, pii x, int add = 0) {
	if (!p) return -oo;
	push(p);
	int pKey = add + getCnt(p->l);
	if (getMin(p->l) == x)
		return findXPos(p->l, x, add);
	else if (p->value == x)
		return pKey;
	else
		return findXPos(p->r, x, pKey+1);
}


int findMinPos(pTreap p, int start) {
	pTreap u, v;
	split(p, u, v, start);
	if (!v) return -oo;
	pii x = v->minValue;
	int ans = findXPos(v, x) + start;
	merge(p, u, v);
	return ans;
}


void reverse(pTreap p, int l, int r) {
	if (l >= r) return;
	pTreap t1, t2, t3;
	split(p, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge(p, t1, t2);
	merge(p, p, t3);
}


int main() {
#ifdef DEBUG
	freopen("1890.in", "r", stdin);
	freopen("1890.out", "w", stdout);
#endif
	srand(time(NULL));
	pTreap root = NULL;
	while(1) {
		int n = read();
		if (n < 1) break;

		for (int i = 1; i <= n; ++i)
			insert(root, i-1, read());

		for (int i = 1; i <= n; ++i) {
			int x = findMinPos(root, i-1);
			printf("%d", x+1);
			if (i < n) printf(" ");
			reverse(root, i-1, x);
		}
		printf("\n");
		erase(root);
	}
	return 0;
}
