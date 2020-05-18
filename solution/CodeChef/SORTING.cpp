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

const int MAX_N = 5*int(1e5) + 5;

struct Node {
	int cnt;
	Node *pLeft, *pRight;
	Node (int cnt, Node* pLeft, Node* pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {}
};

int n;
int a[MAX_N], pos[MAX_N];
Node* root[MAX_N];
queue<pii> q;


int getCnt(Node *p) {	return p ? p->cnt : 0;	}
Node* getLeft(Node *p) {	return p ? p->pLeft : NULL;	}
Node* getRight(Node *p) {	return p ? p->pRight : NULL;	}


Node* update(Node* p, int l, int r, int u) {
	if (l > r) return NULL;
	if (l > u || r < u) return p;
	if (l == r) return new Node(1, NULL, NULL);
	int mid = (l+r)>>1;
	return new Node(getCnt(p)+1, update(getLeft(p), l, mid, u), update(getRight(p), mid+1, r, u));
}


int get(Node* a, Node* b, int l, int r, int k) {
	if (l > r) return -1;
	if (l == r) return l;
	int mid = (l+r)>>1;
	int cnt = getCnt(getLeft(b)) - getCnt(getLeft(a));
	if (k <= cnt) return get(getLeft(a), getLeft(b), l, mid, k);
	else return get(getRight(a), getRight(b), mid+1, r, k-cnt);
}


int main() {
#ifdef DEBUG
	freopen("SORTING.in", "r", stdin);
	freopen("SORTING.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		pos[a[i]] = i;
	}

	root[0] = new Node(0, NULL, NULL);
	for (int i = 1; i <= n; ++i)
		root[i] = update(root[i-1], 1, n, pos[i]);

	ll ans = 0;
	while (!q.empty()) q.pop();
	q.push(make_pair(1, n));
	while (!q.empty()) {
		pii u = q.front();
		q.pop();
		int l = u.first, r = u.second;
		ll len = r-l+1;
		if (len <= 2) {
			ans += len < 2 ? 0 : 2;
			continue;
		}
		int mid = (len+1)>>1;
		int i = get(root[l-1], root[r], 1, n, mid), p = a[i];
		ans += len;
		q.push(make_pair(l, p-1));
		q.push(make_pair(p+1, r));
	}
	printf("%lld\n", ans);
	return 0;
}