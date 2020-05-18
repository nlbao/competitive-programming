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

const int MAX_N = 3*int(1e4) + 4;
const int MAX_A = int(1e6) + 6;

struct Node {
	int cnt;
	Node *pLeft, *pRight;
	Node (int cnt, Node* pLeft, Node* pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {}
};

int n, m, limit;
int a[MAX_N], last[MAX_A];
Node* root[MAX_N];


int getCnt(Node *p) {	return p ? p->cnt : 0;	}
Node* getLeft(Node *p) {	return p ? p->pLeft : NULL;	}
Node* getRight(Node *p) {	return p ? p->pRight : NULL;	}


Node* update(Node* p, int l, int r, int u) {
	if (l > r) return NULL;
	if (l > u || r < u) return p;
	if (l == r) return new Node(getCnt(p)+1, NULL, NULL);
	int mid = (l+r)>>1;
	return new Node(
		getCnt(p)+1,
		update(getLeft(p), l, mid, u),
		update(getRight(p), mid+1, r, u)
	);
}


int get(Node* a, Node* b, int l, int r) {
	if (l > r || l > limit) return 0;
	if (r <= limit)
		return getCnt(b) - getCnt(a);
	int mid = (l+r)>>1;
	return get(getLeft(a), getLeft(b), l, mid) + get(getRight(a), getRight(b), mid+1, r);
}


int main() {
#ifdef DEBUG
	freopen("DQUERY.in", "r", stdin);
	freopen("DQUERY.out", "w", stdout);
#endif
	n = read();
	m = n;
	root[0] = new Node(0, NULL, NULL);
	filla(last, 0);
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		root[i] = update(root[i-1], 1, m, last[a[i]]+1);
		last[a[i]] = i;
	}

	int nQ = read();
	while (nQ--) {
		int x, y;
		scanf("%d%d", &x, &y);
		limit = x;
		printf("%d\n", get(root[x-1], root[y], 1, m));
	}
	return 0;
}