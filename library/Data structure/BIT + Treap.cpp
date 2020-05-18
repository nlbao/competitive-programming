struct Treap {
	int key, prior, cnt;
	Treap *l, *r;
	Treap(int _key = 0) {
		key = _key;
		prior = (rand()<<16)^rand();
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
pTreap root[MAX_N];

void update(int x, int y) {
	while (x <= n) {
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