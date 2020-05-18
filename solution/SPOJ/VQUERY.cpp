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

const int MAX_N = int(1e5) + 5;

struct Node {
	int maxValue;
	Node *pLeft, *pRight;
	Node(int v, Node* pLeft, Node* pRight): maxValue(v), pLeft(pLeft), pRight(pRight) {}
};

inline int getMax(Node* p) {	return p ? p->maxValue : 0;	}
inline Node* getLeft(Node* p) {	return p ? p->pLeft : NULL;	}
inline Node* getRight(Node* p) {	return p ? p->pRight : NULL;	}


int u, v, value;
int w[MAX_N], a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N], r[MAX_N];
Node *root[MAX_N];


Node * buildTree(int l, int r) {
	if (l > r) return NULL;
	if (l == r) return new Node(w[l], NULL, NULL);
	int mid = (l+r)>>1;
	Node *q = new Node(
		0,
		buildTree(l, mid),
		buildTree(mid+1, r)
	);
	q->maxValue = max(getMax(getLeft(q)), getMax(getRight(q)));
	return q;
}


Node* update(Node* p, int l, int r) {
	if (l > r) return NULL;
	if (l > u || r < u) return p;
	if (l == r) return new Node(value, NULL, NULL);
	int mid = (l+r)>>1;
	Node *q = new Node(
		0,
		update(getLeft(p), l, mid),
		update(getRight(p), mid+1, r)
	);
	q->maxValue = max(getMax(getLeft(q)), getMax(getRight(q)));
	return q;
}


int get(Node* p, int l, int r) {
	if (l > r || l > v || r < u) return 0;
	if (u <= l && r <= v) return getMax(p);
	int mid = (l+r)>>1;
	return max(get(getLeft(p), l, mid), get(getRight(p), mid+1, r));
}


int main() {
#ifdef DEBUG
	freopen("VQUERY.in", "r", stdin);
	freopen("VQUERY.out", "w", stdout);
#endif
	ll n = read();
	for (int i = 1; i <= n; ++i) w[i] = read();
	int rq = read(), q = read();
	for (int i = 0; i < q; ++i)
		scanf("%d%d%d%d%d", &r[i], &a[i], &b[i], &c[i], &d[i]);

	ll L = 0, P = 0;
	root[0] = buildTree(1, n);
	while (rq--) {
		for (int i = 0; i < q; ++i) {
			if (r[i] == 1) {
				u = 1 + ((L*ll(a[i]) + ll(c[i])) % n);
				value = 1 + ((L*ll(b[i]) + ll(d[i])) % ll(1e9));
				root[P+1] = update(root[P], 1, n);
				++P;
			}
			else if (r[i] == 2) {
				u = 1 + ((L*ll(a[i]) + ll(c[i])) % n);
				v = 1 + ((L*ll(b[i]) + ll(d[i])) % n);
				if (u > v) swap(u, v);
				L = get(root[P], 1, n);
				printf("%d\n", int(L));
			}
			else {
				int x = (L*ll(a[i]) + ll(c[i])) % (P+1);
				root[++P] = root[x];
			}
		}
	}
	return 0;
}