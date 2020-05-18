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


const int MAX_N = 1e5 + 55;


int n, nQ;
int posL[MAX_N], posR[MAX_N], ans[MAX_N];


inline pair<int, pii> cal(int l, int r) {
	int len = r-l+1;
	if (l == 1 && r == n) return make_pair(n+1, pii(0, n));
	if (l == 1) return make_pair(len+1, pii(1, 1));
	if (r == n) return make_pair(len+1, pii(1, n));
	int pos = (l+r+1) >> 1;
	int d1 = pos-l+2, d2 = r-pos+2;
	int d = min(d1, d2), cnt = 1 + int(d1 == d2);
	return make_pair(d, pii(cnt, pos));
}


struct Node {
	int l, r;
	Node(int x, int y) : l(x), r(y) {}
	bool operator < (const Node &o) const {
		pair<int, pii> x = cal(l, r);
		pair<int, pii> y = cal(o.l, o.r);
		x.first = -x.first, x.second.second = -x.second.second;
		y.first = -y.first, y.second.second = -y.second.second;
		return x < y;
	}
};


set<Node> heap;
set<int> pointLeft, pointRight;


int addNewPoint() {
	if (heap.empty()) return -1;
	set<Node>::iterator it = heap.begin();
	int l = it->l, r = it->r;
	int x = cal(l, r).second.second;
	heap.erase(it);
	pointLeft.erase(l);
	pointRight.erase(r);
	if (x > l) {
		heap.insert(Node(l, x-1));
		pointLeft.insert(l);
		pointRight.insert(x-1);
	}

	if (x < r) {
		heap.insert(Node(x+1, r));
		pointLeft.insert(x+1);
		pointRight.insert(r);
	}
	return x;
}


inline int findLeft(int x) {
	if (x == 1) return 1;
	set<int>::iterator it = pointRight.find(x-1);
	if (it == pointRight.end())
		return x;
	int l = 1, r = x-1, t = x;
	while (l <= r) {
		int mid = (l+r)>>1;
		it = pointLeft.lower_bound(mid);
		if (it == pointLeft.end()) r = mid-1;
		else if (*it >= x) r = mid-1;
		else {
			t = *it;
			l = mid+1;
		}
	}
	return t;
}


inline int findRight(int x) {
	if (x == n) return n;
	set<int>::iterator it = pointLeft.find(x+1);
	if (it == pointLeft.end())
		return x;
	it = pointRight.upper_bound(x);
	if (it == pointRight.end()) return x;
	return *it;
}


void removePoint(int x) {
	int l = findLeft(x);
	int r = findRight(x);
	if (x > l) {
		heap.erase(Node(l, x-1));
		pointRight.erase(x-1);
	}
	if (x < r) {
		heap.erase(Node(x+1, r));
		pointLeft.erase(x+1);
	}
	heap.insert(Node(l, r));
	pointLeft.insert(l);
	pointRight.insert(r);
}


int main() {
#ifdef DEBUG
	freopen("100184C.in", "r", stdin);
	freopen("100184C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &nQ);
	heap.clear();
	heap.insert(Node(1, n));
	pointLeft.clear();
	pointLeft.insert(1);
	pointRight.clear();
	pointRight.insert(n);

	for (int i = 1; i <= nQ; ++i) {
		int types;
		scanf("%d", &types);
		if (types == 0) {
			int x = addNewPoint();
			ans[i] = x;
			printf("%d\n", x);
		}
		else {
			int k;
			scanf("%d", &k);
			int x = ans[k];
			removePoint(x);
		}
	}
	return 0;
}