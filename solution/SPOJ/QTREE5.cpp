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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5) + 5;
const int oo = int(1e9);


struct Node {
	int ld, rd, lf, rf;
	Node *lc, *rc;
	Node() {
		lc = rc = NULL;
		lf = rf = oo;
	}
};
typedef Node* pNode;


int n, nChain, crrID, crrPos, crrL, crrR;
int par[MAX_N], c[MAX_N], h[MAX_N], first[MAX_N], len[MAX_N], chainID[MAX_N], pos[MAX_N];
int lastValue[MAX_N];
vector<int> e[MAX_N], invPos[MAX_N];
bool ok[MAX_N], white[MAX_N], isLeft;
pii a[MAX_N];
pNode root[MAX_N];
multiset<int> S[MAX_N];


void dfs(int u) {
	ok[u] = false;
	c[u] = 1;
	for_each(it, e[u]) {
		int v = *it;
		if (ok[v]) {
			par[v] = u;
			h[v] = h[u]+1;
			dfs(v);
			c[u] += c[v];
		}
	}
}


void HLD(int u) {
	chainID[u] = nChain;
	pos[u] = ++len[nChain];
	invPos[nChain].push_back(u);
	int k = -1;
	for_each(it, e[u]) {
		int v = *it;
		if (par[v] == u && (k == -1 || c[v] > c[k]))
			k = v;
	}
	if (k > 0) HLD(k);
	for_each(it, e[u]) {
		int v = *it;
		if (v == k || par[v] != u) continue;
		first[++nChain] = v;
		len[nChain] = 0;
		invPos[nChain].push_back(-1);
		HLD(v);
	}
}


inline int getMin(int u) {
	if (S[u].empty()) return oo;
	return *(S[u].begin());
}


inline void subUpdate(pNode p) {
	pNode u = p->lc, v = p->rc;
	p->ld = u->ld, p->rd = v->rd;
	p->lf = u->lf;
	if (v->lf < oo)
		p->lf = min(p->lf, v->ld - u->ld + v->lf);
	p->rf = v->rf;
	if (u->rf < oo)
		p->rf = min(p->rf, v->rd - u->rd + u->rf);
}


void build(pNode &p, int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (p == NULL) p = new Node();
		int u = invPos[crrID][l];
		p->ld = p->rd = h[u];
		p->lf = p->rf = oo;
		return;
	}
	if (!p) p = new Node();
	int mid = (l+r)>>1;
	build(p->lc, l, mid);
	build(p->rc, mid+1, r);
	subUpdate(p);
}


void update(pNode p, int l, int r) {
	if (l > r || l > crrPos || r < crrPos) return;
	if (l == r) {
		int u = invPos[crrID][l];
		p->lf = p->rf = getMin(u);
		return;
	}
	int mid = (l+r)>>1;
	update(p->lc, l, mid);
	update(p->rc, mid+1, r);
	subUpdate(p);
}


int get(pNode p, int l, int r) {
	if (l > r || l > crrR || r < crrL) return oo;
	if (crrL <= l && r <= crrR) {
		if (isLeft) return p->lf + p->ld - h[invPos[crrID][crrL]];
		else return p->rf + h[invPos[crrID][crrR]] - p->rd;
	}
	int mid = (l+r)>>1;
	return min(get(p->lc, l, mid), get(p->rc, mid+1, r));
}


void remove(pNode &p) {
	if (!p) return;
	remove(p->lc);
	remove(p->rc);
	delete p;
	p = NULL;
}


void changeColor(int u) {
	white[u] ^= true;
	if (white[u]) S[u].insert(0);
	else S[u].erase(S[u].find(0));

	int pre = -1, value;
	while (u > 0) {
		int i = chainID[u];
		if (pre != -1) {
			if (value < oo)
				value += h[pre] - h[u];
			if (lastValue[pre] == value) break;
			if (lastValue[pre] < oo)
				S[u].erase(S[u].find(lastValue[pre]));
			lastValue[pre] = value;
			if (value < oo)
				S[u].insert(value);
		}

		crrID = i, crrPos = pos[u];
		update(root[i], 1, len[i]);

		pre = first[i];
		u = par[pre];
		value = root[i]->lf;
	}
}


int query(int u) {
	if (white[u]) return 0;
	int sum = 0, v = u, ans = oo;
	while (u > 0) {
		int i = chainID[u];
		sum += h[v] - h[u];
		crrID = i, crrL = pos[u], crrR = len[i], isLeft = true;
		ans = min(ans, sum + get(root[i], 1, len[i]));
		crrID = i, crrL = 1, crrR = pos[u], isLeft = false;
		ans = min(ans, sum + get(root[i], 1, len[i]));
		v = u;
		u = par[first[i]];
	}
	if (ans >= oo) return -1;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("QTREE5.in", "r", stdin);
	freopen("QTREE5.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d\n", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	filla(ok, true);
	par[1] = 0;
	h[1] = 1;
	dfs(1);

	nChain = 1;
	first[1] = 1;
	len[1] = 0;
	invPos[1].push_back(-1);
	HLD(1);

	filla(white, false);
	for (int i = 1; i <= n; ++i)
		lastValue[i] = oo;
	for (int i = 1; i <= nChain; ++i)
		a[i] = make_pair(-h[first[i]], i);
	sort(a+1, a+1+nChain);
	for (int i = 1; i <= nChain; ++i) {
		int k = a[i].second;
		crrID = k;
		root[k] = NULL;
		build(root[k], 1, len[k]);
	}

	int nQ = readln();
	while (nQ--) {
		int t, u;
		scanf("%d%d", &t, &u);
		if (t == 0) changeColor(u);
		else printf("%d\n", query(u));
	}

	for (int i = 1; i <= nChain; ++i)
		remove(root[i]);
	return 0;
}