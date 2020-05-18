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
	int cnt;
	ll sum;
	Node *pLeft, *pRight;
	Node (int cnt, ll sum, Node* pLeft, Node* pRight):
		cnt(cnt), sum(sum), pLeft(pLeft), pRight(pRight) {}
};

int n, m, pos;
int a[MAX_N], b[MAX_N];
ll value, sum;
ll sumX[MAX_N], sumY[MAX_N];
Node *rootX[MAX_N], *rootY[MAX_N];
map<int, int> id, r_id;


int getCnt(Node *p) {	return p ? p->cnt : 0;	}
ll getSum(Node *p) {	return p ? p->sum : 0;	}
Node* getLeft(Node *p) {	return p ? p->pLeft : NULL;	}
Node* getRight(Node *p) {	return p ? p->pRight : NULL;	}


Node* update(Node* p, int l, int r) {
	if (l > r) return NULL;
	if (l > pos || r < pos) return p;
	if (l == r) return new Node(getCnt(p)+1, getSum(p)+value, NULL, NULL);
	int mid = (l+r)>>1;
	return new Node(
		getCnt(p)+1,
		getSum(p)+value,
		update(getLeft(p), l, mid),
		update(getRight(p), mid+1, r)
	);
}


int getKth(Node* a, Node* b, int l, int r, int k) {
	if (l > r) return -1;
	if (l == r) return l;
	int mid = (l+r)>>1;
	int cnt = getCnt(getLeft(b)) - getCnt(getLeft(a));
	if (k <= cnt) return getKth(getLeft(a), getLeft(b), l, mid, k);
	else return getKth(getRight(a), getRight(b), mid+1, r, k-cnt);
}


ll getS(Node* a, Node* b, int l, int r, int limit) {
	if (l > r || l > limit) return 0;
	if (r <= limit) return getSum(b) - getSum(a);
	int mid = (l+r)>>1;
	return getS(getLeft(a), getLeft(b), l, mid, limit) + getS(getRight(a), getRight(b), mid+1, r, limit);
}


int get(Node* a, Node* b, int l, int r, int k) {
	if (l > r) return -1;
	if (l == r) {
		sum += ll(k) * ll(r_id[l]);
		return l;
	}
	int mid = (l+r)>>1;
	int cnt = getCnt(getLeft(b)) - getCnt(getLeft(a));
	if (k <= cnt) return get(getLeft(a), getLeft(b), l, mid, k);
	else {
		sum += getSum(getLeft(b)) - getSum(getLeft(a));
		return get(getRight(a), getRight(b), mid+1, r, k-cnt);
	}
}


int main() {
#ifdef DEBUG
	freopen("signal-tower.in", "r", stdin);
	freopen("signal-tower.out", "w", stdout);
#endif
	n = read();
	int nQ = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) b[i] = read();
	sumX[0] = sumY[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int t = a[i] + b[i];
		b[i] = a[i] - b[i];
		a[i] = t;
		id[a[i]];	id[b[i]];
		sumX[i] = sumX[i-1] + ll(a[i]);
		sumY[i] = sumY[i-1] + ll(b[i]);
	}
	m = 0;
	for (map<int, int>::iterator it = id.begin(); it != id.end(); ++it) {
		it->second = ++m;
		r_id[m] = it->first;
	}

	rootX[0] = new Node(0, 0, NULL, NULL);
	rootY[0] = new Node(0, 0, NULL, NULL);
	for (int i = 1; i <= n; ++i) {
		pos = id[a[i]], value = a[i];
		rootX[i] = update(rootX[i-1], 1, m);
		pos = id[b[i]], value = b[i];
		rootY[i] = update(rootY[i-1], 1, m);
	}

	while (nQ--) {
		int l, r;
		scanf("%d%d", &l, &r);
		ll len = r-l+1, mid = (len+1)>>1;

		sum = 0;
		double median = get(rootX[l-1], rootX[r], 1, m, mid);
		double sx = (2*mid - len)*r_id[median] + (sumX[r] - sumX[l-1] - 2*sum);

		sum = 0;
		median = get(rootY[l-1], rootY[r], 1, m, mid);
		double sy = (2*mid - len)*r_id[median] + (sumY[r] - sumY[l-1] - 2*sum);

		printf("%.4lf\n", (sx + sy)/2.0);
	}
	return 0;
}