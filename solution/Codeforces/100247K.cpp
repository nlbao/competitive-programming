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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 2*int(1e5)+5;


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


int n;
pair<int, pii> a[MAX_N];
pTreap root[MAX_N];


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


void update(int x, int y) {
	while (x <= n) {
		insert(root[x], y);
		x += x & (-x);
	}
}


int get(int x, int y) {
	int ans = 0;
	while (x > 0) {
		ans += countLessThan(root[x], y);
		x -= x & (-x);
	}
	return ans;
}


void remove(pTreap &p) {
	if (!p) return;
	remove(p->l);
	remove(p->r);
	delete p;
	p = NULL;
}



int main() {
#ifdef DEBUG
	// freopen("100247K.in", "r", stdin);
	freopen("test.out", "r", stdin);
	freopen("100247K.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = make_pair(z, make_pair(x, y));
	}
	sort(a, a+n);

	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		root[i] = NULL;
	for (int i = 0; i < n; ++i) {
		int x = a[i].second.first, y = a[i].second.second;
		int k = get(x, y);
		ans += ll(i-k);
		update(x, y);
	}
	for (int i = 1; i <= n; ++i)
		remove(root[i]);
	cout << ans << endl;
	return 0;
}