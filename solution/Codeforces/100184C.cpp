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
	int cnt = 1 + int(d1 == d2);
	return make_pair(min(d1, d2), pii(cnt, pos));
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


bool ok(int x) {
	return 1 <= x && x <= n && posL[x] <= x && x <= posR[x];
}


inline void update(int x, int l, int r) {
	posL[x] = l, posR[x] = r;
}


inline void remove(int x) {
	posL[x] = n+1;
	posR[x] = -1;
}


int addNewPoint() {
	if (heap.empty()) return -1;
	set<Node>::iterator it = heap.begin();
	int l = it->l, r = it->r;
	int x = cal(l, r).second.second;
	heap.erase(it);

	if (x > l) {
		update(x-1, l, x-1);
		update(l, l, x-1);
		heap.insert(Node(l, x-1));
	}
	else remove(l);

	if (x < r) {
		update(x+1, x+1, r);
		update(r, x+1, r);
		heap.insert(Node(x+1, r));
	}
	else remove(r);

	remove(x);
	return x;
}


void removePoint(int x) {
	int l = x, r = x;
	if (x > 1 && ok(x-1)) l = posL[x-1];
	if (x < n && ok(x+1)) r = posR[x+1];
	update(l, l, r);
	update(r, l, r);
	if (x > l) {
		update(x-1, l, r);
		heap.erase(Node(l, x-1));
	}
	if (x < r) {
		update(x+1, l, r);
		heap.erase(Node(x+1, r));
	}
	heap.insert(Node(l, r));
}


int main() {
#ifdef DEBUG
	freopen("100184C.in", "r", stdin);
	freopen("100184C.out", "w", stdout);
#endif

	scanf("%d%d", &n, &nQ);
	heap.clear();
	heap.insert(Node(1, n));
	for (int i = 1; i <= n; ++i) {
		posL[i] = 1;
		posR[i] = n;
	}

	for (int i = 1; i <= nQ; ++i) {
		int types, k;
		scanf("%d", &types);
		if (types == 0) {
			ans[i] = addNewPoint();
			printf("%d\n", ans[i]);
		}
		else {
			scanf("%d", &k);
			removePoint(ans[k]);
		}
	}
	return 0;
}