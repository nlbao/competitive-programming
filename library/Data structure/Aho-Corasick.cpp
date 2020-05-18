// Aho-Corasick
typedef struct Node* pNode;
struct Node {
	pNode nexts[MAX_A], link;
	int cnt, len;

	Node(int l, int c) {
		fori(i,0,MAX_A-1) nexts[i]=0;
		link = 0;	len = l;	cnt=c;
	}

	pNode add(int x, int val) {
		if (!nexts[x]) nexts[x] = new Node(len+1, val);
		else if (val) nexts[x]->cnt = 1;
		return nexts[x];
	}
};


void init(pNode root) {
	if (!root) return;
	queue<pNode> q;
	q.push(root);
	while (!q.empty()) {
		pNode p = q.front();	q.pop();
		if (p->link) p->cnt += p->link->cnt;
		fori(x,0,MAX_A-1) {
			pNode u = p, v = p->nexts[x];
			if (!v) continue;
			q.push(v);
			if (u != root) {
				u = p->link;
				while (u != root && !u->nexts[x]) u = u->link;
				if (u->nexts[x]) u = u->nexts[x];
			}
			v->link = u;
		}
	}
}