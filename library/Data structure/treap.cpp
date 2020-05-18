////////////////////////////////////////////////////////////////////////////////

// http://translate.yandex.net/tr-url/ru-en.en/e-maxx.ru/algo/treap

////////////////////////////////////////////////////////////////////////////////


struct item {
	int key, prior;
	item * l, * r;
	item() { }
	item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};

typedef item* pitem;


void split (pitem t, int key, pitem & l, pitem & r) {
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l), r = t;
	else
		split (t->r, key, t->r, r), l = t;
}


void insert (pitem & t, pitem it) {
	if (!t) t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r), t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
}


void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r), t = l;
	else
		merge (r->l, l, r->l), t = r;
}


void erase (pitem & t, int key) {
	if (t->key == key)
		merge (t, t->l, t->r);
	else
		erase (key < t->key ? t->l : t->r, key);
}


pitem union (pitem l, pitem r) {
	if (!l || !r) return l ? l : r;
	if (l->prior < r->prior) swap (l, r);
	pitem lt, rt;
	split (r, l->key, lt, rt);
	l->l = union (l->l, lt);
	l->r = union (l->r, rt);
	return l;
}


////////////////////////////////////////////////////////////////////////////////
// Support sizes of the subtrees
int cnt (pitem t) {
	return t ? t->cnt : 0;
}

// it is enough to add the function calls upd_cnt() at the end of each of
// the functions insert, delete, split, merge, to keep the correct value cnt.
void upd_cnt (pitem t) {
	if (t)
		t->cnt = 1 + cnt(t->l) + cnt (t->r);
}
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// Implicit Cartesian trees

struct item {
	int prior, value, cnt;
	bool rev;
	pitem l, r;
};

typedef struct item* pitem;


int cnt (pitem it) { return it ? it->cnt : 0;	}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l) it->l->rev ^= true;
		if (it->r) it->r->rev ^= true;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r), t = l;
	else
		merge (r->l, l, r->l), t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t) return void( l = r = 0 );
	push (t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add), r = t;
	else
		split (t->r t->r, r, key, add + 1 + cnt(t->l)), l = t;
	upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
	pitem t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void output (pitem t) {
	if (!t) return;
	push (t);
	output (t->l);
	printf ("%d ", t->value);
	output (t->r);
}



////////////////////////////////////////////////////////////////////////////////
// Build a Casterian tree based on existed key-prior pairs
// ref: http://wcipeg.com/wiki/Cartesian_tree

// input sequence A with length N indexed from 1
// label the root node 1, with left child = right child = 0 (nonexistent)
root ← 1
left[1] ← 0
right[1] ← 0
// the root's label is the first item in the sequence
label[1] ← A[1]
for i ∈ [2..N]
    last ← i-1               // node of A[i-1]
    // create new node with label A[i]
    label[i] ← A[i]
    right[i] ← 0
    while label[last] > A[i] and last ≠ root
        last ← parent[last]
    if label[last] > A[i]    // A[i] is the smallest element yet; make it new root
        parent[root] ← i
        left[i] ← root
        root ← i
    else if right[last] = 0       // just insert it
        right[last] ← i
        parent[i] ← last
        left[i] ← 0
    else                     // reconfigure links
        parent[right[last]] ← i
        left[i] ← right[last]
        right[last] ← i
        parent[i] ← last