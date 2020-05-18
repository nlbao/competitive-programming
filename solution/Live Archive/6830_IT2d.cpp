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


const int MAX_N = 555;
const int oo = 1e9;


struct Rectangle {
	int x1, y1, x2, y2;
};


struct Node {
	int f, g, newValue;
	pii id;
	bool isEmpty;
	Node *child[4];
	Node (int g, int x, int y) : g(g), id(pii(x, y)) {
		isEmpty = false;
		f = newValue = oo;
		for (int i = 0; i < 4; ++i)
			child[i] = NULL;
	}
};

typedef pair<int, pii> AnsPair;


int cnt;
int m, n, nQ, ux, vx, uy, vy, value;
int cost[MAX_N][MAX_N], row[MAX_N][MAX_N], col[MAX_N][MAX_N];
Rectangle rec[MAX_N][MAX_N];
Node *root;


void init() {
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) {
			rec[i][j].x1 = max(1, i - row[i][j]);
			rec[i][j].y1 = max(1, j - col[i][j]);
			rec[i][j].x2 = min(m, i + row[i][j]);
			rec[i][j].y2 = min(n, j + col[i][j]);
		}
}


void remove(Node* &p) {
	if (!p) return;
	for (int i = 0; i < 4; ++i)
		remove(p->child[i]);
	delete p;
	p = NULL;
}


void build(Node* &p, int lx, int rx, int ly, int ry) {
	if (lx > rx || ly > ry) return;
	if (!p) p = new Node(cost[lx][ly], lx, ly);
	if (lx == rx && ly == ry) return;
	int midx = (lx+rx)>>1;
	int midy = (ly+ry)>>1;
	build(p->child[0], lx, midx, ly, midy);
	build(p->child[1], lx, midx, midy+1, ry);
	build(p->child[2], midx+1, rx, ly, midy);
	build(p->child[3], midx+1, rx, midy+1, ry);
	for (int i = 0; i < 4; ++i) {
		Node *t = p->child[i];
		if (t) p->g = min(p->g, t->g);
	}
}


inline void pushDown(Node* p) {
	if (!p || p->newValue >= oo) return;
	for (int i = 0; i < 4; ++i) {
		Node *t = p->child[i];
		if (t && !(t->isEmpty)) {
			t->f = min(t->f, p->newValue + t->g);
			t->newValue = min(t->newValue, p->newValue);
		}
	}
	p->newValue = oo;
}


void update(Node* &p, int lx, int rx, int ly, int ry) {
	if (lx > rx || ly > ry || !p || p->isEmpty) return;
	if (lx > vx || rx < ux || ly > vy || ry < uy) return;
	if (ux <= lx && rx <= vx && uy <= ly && ry <= vy) {
		if (value == oo) {	// remove, lx = rx, ly = ry
			p->f = p->g = p->newValue = oo;
			p->id = pii(-1, -1);
			p->isEmpty = true;
		}
		else {
			p->f = min(p->f, p->g + value);
			p->newValue = min(p->newValue, value);
		}
		return;
	}
	if (lx == rx && ly == ry) {
		if (!(p->isEmpty)) {
			p->f = min(p->f, p->g + value);
			p->newValue = min(p->newValue, value);
		}
		return;
	}

	pushDown(p);
	int midx = (lx+rx)>>1;
	int midy = (ly+ry)>>1;
	update(p->child[0], lx, midx, ly, midy);
	update(p->child[1], lx, midx, midy+1, ry);
	update(p->child[2], midx+1, rx, ly, midy);
	update(p->child[3], midx+1, rx, midy+1, ry);
	p->f = p->g = p->newValue = oo;
	p->id = pii(lx, ly);
	p->isEmpty = true;
	for (int i = 0; i < 4; ++i) {
		Node *t = p->child[i];
		if (t && !(t->isEmpty)) {
			p->isEmpty = false;
			if (t->g < p->g) {
				p->g = t->g;
			}
			if (t->f < p->f) {
				p->f = t->f;
				p->id = t->id;
			}
		}
	}
}


inline void newUpdate(int lx, int rx, int ly, int ry, int newValue) {
	ux = lx, vx = rx, uy = ly, vy = ry;
	value = newValue;
	update(root, 1, m, 1, n);
}


int solve(int sx, int sy, int tx, int ty) {
	if (sx == tx && sy == ty) return 0;

	// if (root) remove(root);
	build(root, 1, m, 1, n);
	newUpdate(sx, sx, sy, sy, 0);

	while (true) {
		int d = root->f;
		int x = root->id.first, y = root->id.second;
		if (x < 0 || y < 0) return -1;
		if (d >= oo) return -1;
		if (x == tx && y == ty) return d;
		if (abs(x-tx) <= row[x][y] && abs(y-ty) <= col[x][y])
			return d;
		newUpdate(x, x, y, y, oo);
		newUpdate(rec[x][y].x1, rec[x][y].x2, rec[x][y].y1, rec[x][y].y2, d);
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("6830.in", "r", stdin);
	freopen("test.in", "r", stdin);
	freopen("6830.out", "w", stdout);
#endif
	root = NULL;
	while (scanf("%d%d%d", &m, &n, &nQ) == 3) {
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &cost[i][j]);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &row[i][j]);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				scanf("%d", &col[i][j]);

		init();
		if (root) remove(root);
		for (int i = 0, x1, y1, x2, y2; i < nQ; ++i) {
			scanf("%d%d", &x2, &y2);
			if (i > 0) printf("%d ", solve(x1, y1, x2, y2));
			x1 = x2, y1 = y2;
		}
		printf("\n");
	}
	return 0;
}