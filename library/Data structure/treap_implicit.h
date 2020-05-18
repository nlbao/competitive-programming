typedef struct Node* pNode;
struct Node {	// Implicit Treap, 0-base indexed
	int val, prior, cnt;
	bool rev;	// 1 = need to be reversed, 0 = no
	pNode l, r, par;
	Node(int x=0) {
		val = x;	cnt = 1;
		prior = (rand()<<16) ^ rand();
		rev = 0;
		l = r = par = 0;
	}
};

inline int getCnt(pNode p) {	return p ? p->cnt : 0;	}
inline void upNode(pNode &p) {
	if (!p) return;
	p->cnt = getCnt(p->l) + getCnt(p->r) + 1;
	if (p->l) p->l->par = p;
	if (p->r) p->r->par = p;
}

inline void push(pNode p) {
	if (!p || !p->rev) return;
	p->rev = 0;
	swap(p->l, p->r);
	if (p->l) p->l->rev ^= 1;
	if (p->r) p->r->rev ^= 1;
}

void merge(pNode &p, pNode u, pNode v) {
	push(u);	push(v);
	if (!u || !v) p = u ? u : v;
	else if (u->prior > v->prior) merge(u->r, u->r, v), p = u;
	else                          merge(v->l, u, v->l), p = v;
	upNode(p);
}

void split(pNode p, pNode &u, pNode &v, int key, int add = 0) {
	if (!p) return void(u = v = 0);
	push(p);
	int crrKey = add + getCnt(p->l);
	if (key <= crrKey) split(p->l, u, p->l, key, add), v = p;
	else               split(p->r, p->r, v, key, crrKey + 1), u = p;
	upNode(p);
}

void insert(pNode &p, int i, int val) {	// 0-based
	pNode t1, t2, newNode = new Node(val);
	split(p, t1, t2, i);
	merge(p, t1, newNode);
	merge(p, p, t2);
}

void reverse(pNode p, int l, int r) {
	pNode t1, t2, t3;
	split(p, t1, t2, l);		// t1 = [0, l-1]
	split(t2, t2, t3, r-l+1);	// t2 = [l, r]
	t2->rev ^= 1;				// reverse t2
	merge(p, t1, t2);
	merge(p, p, t3);
}

int findPos(pNode p) {	// 0-based
	int c = getCnt(p->l);
	for (; p->par; p = p->par)
		if (p == p->par->r)
			c += getCnt(p->par->l) + 1;
	return c;
}