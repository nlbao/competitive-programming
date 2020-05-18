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
#include <stack>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 2*int(1e5) + 5;
const int oo = int(1e9);


struct Node {
	int lsum[2], rsum[2];
	bool lwhite, rwhite, full;
	Node *lc, *rc;
	Node() {
		lc = rc = NULL;
		filla(lsum, 0);
		filla(rsum, 0);
		lwhite = rwhite = full = false;
	}
	Node(const Node &other) {
		for (int i = 0; i < 2; ++i) {
			lsum[i] = other.lsum[i];
			rsum[i] = other.rsum[i];
		}
		lwhite = other.lwhite;
		rwhite = other.rwhite;
		full = other.full;
		lc = rc = NULL;
	}
};
typedef Node* pNode;


int n, nChain, crrID, crrPos, crrL, crrR, crrValue, crrColor;
int par[MAX_N], c[MAX_N], h[MAX_N], q[MAX_N];
int way[MAX_N], first[MAX_N], len[MAX_N], chainID[MAX_N], pos[MAX_N];
vector<int> e[MAX_N], invPos[MAX_N];
bool ok[MAX_N], white[MAX_N];
pii a[MAX_N];
pNode root[MAX_N];


void init_HLD(int u) {
	for (int i = 1; i <= n; ++i) {
		ok[i] = true;
		c[i] = 0;
	}
	int l = 1, r = 1;
	q[1] = u;
	par[u] = 0;
	h[u] = 1;
	ok[u] = false;
	while (l <= r) {
		u = q[l++];
		for_each(it, e[u]) {
			int v = *it;
			if (ok[v]) {
				par[v] = u;
				h[v] = h[u]+1;
				q[++r] = v;
				ok[v] = false;
			}
		}
	}

	for (int i = 1; i <= n; ++i) ok[i] = true;
	for (int i = r; i > 0; --i) {
		int u = q[i];
		++c[u];
		c[par[u]] += c[u];
		way[u] = 0;
		for_each(it, e[u]) {
			int v = *it;
			if (par[v] == u && (way[u] == 0 || c[v] > c[way[u]]))
				way[u] = v;
		}
		ok[way[u]] = false;
	}

	nChain = 0;
	for (int u = 1; u <= n; ++u) if (ok[u]) {
		chainID[u] = ++nChain;
		first[nChain] = u;
		pos[u] = len[nChain] = 1;
		invPos[nChain].push_back(-1);
		invPos[nChain].push_back(u);
		for (int v = way[u]; v > 0; v = way[v]) {
			chainID[v] = nChain;
			pos[v] = ++len[nChain];
			invPos[nChain].push_back(v);
		}
	}
}


inline void subUpdate(pNode p, pNode u, pNode v) {
	p->lwhite = u->lwhite;
	p->rwhite = v->rwhite;
	for (int i = 0; i < 2; ++i) {
		p->lsum[i] = u->lsum[i];
		p->rsum[i] = v->rsum[i];
	}
	p->lsum[!p->lwhite] = 0;
	p->rsum[!p->rwhite] = 0;
	if (u->full && v->lwhite == u->rwhite)
		p->lsum[v->lwhite] += v->lsum[v->lwhite];
	if (v->full && u->rwhite == v->lwhite)
		p->rsum[u->rwhite] += u->rsum[u->rwhite];
	p->full = (u->full) && (v->full) && (u->rwhite == v->lwhite);
}


void build(pNode &p, int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (p == NULL) p = new Node();
		int u = invPos[crrID][l];
		p->lsum[white[u]] = p->rsum[white[u]] = 1;
		p->lsum[!white[u]] = p->rsum[!white[u]] = 0;
		for_each(it, e[u]) {
			int v = *it;
			if (par[v] != u || chainID[v] == chainID[u]) continue;
			for (int i = 0; i < 2; ++i) {
				p->lsum[i] += root[chainID[v]]->lsum[i];
				p->rsum[i] += root[chainID[v]]->lsum[i];
			}
		}
		p->full = true;
		return;
	}
	if (!p) p = new Node();
	int mid = (l+r)>>1;
	build(p->lc, l, mid);
	build(p->rc, mid+1, r);
	subUpdate(p, p->lc, p->rc);
}


void update(pNode p, int l, int r) {
	if (l > r || l > crrPos || r < crrPos) return;
	if (l == r) {
		int u = invPos[crrID][l];
		p->lsum[crrColor] += crrValue;
		p->rsum[crrColor] += crrValue;
		p->lwhite = p->rwhite = white[u];
		return;
	}
	int mid = (l+r)>>1;
	update(p->lc, l, mid);
	update(p->rc, mid+1, r);
	subUpdate(p, p->lc, p->rc);
}


pNode get(pNode p, int l, int r) {
	if (l > r || l > crrR || r < crrL || crrL > crrR) return new Node();
	if (crrL <= l && r <= crrR)
		return new Node(*p);
	int mid = (l+r)>>1;
	if (crrR <= mid) return get(p->lc, l, mid);
	if (crrL > mid) return get(p->rc, mid+1, r);
	pNode ans = new Node();
	pNode u = get(p->lc, l, mid);
	pNode v = get(p->rc, mid+1, r);
	subUpdate(ans, u, v);
	delete u;
	delete v;
	return ans;
}


void remove(pNode &p) {
	if (!p) return;
	remove(p->lc);
	remove(p->rc);
	delete p;
	p = NULL;
}


void changeColor(int u) {
	int pre = -1;
	int oldSum[2], newSum[2];
	oldSum[white[u]] = 1, oldSum[!white[u]] = 0;
	newSum[white[u]] = 0, newSum[!white[u]] = 1;
	white[u] ^= true;
	while (u > 0) {
		int i = chainID[u];
		int tSum[2];
		for (int k = 0; k < 2; ++k)
			tSum[k] = root[i]->lsum[k];
		for (int k = 0; k < 2; ++k) {
			if (oldSum[k] != 0) {
				crrID = i, crrPos = pos[u], crrColor = k, crrValue = - oldSum[k];
				update(root[i], 1, len[i]);
			}
			if (newSum[k] != 0) {
				crrID = i, crrPos = pos[u], crrColor = k, crrValue = + newSum[k];
				update(root[i], 1, len[i]);
			}
		}
		for (int k = 0; k < 2; ++k) {
			oldSum[k] = tSum[k];
			newSum[k] = root[i]->lsum[k];
		}
		pre = first[i];
		u = par[pre];
	}
}


int query(int u) {
	int pre = -1, ans = 0, value = 0;
	bool preWhite = white[u];
	pNode pLeft, pRight;
	while (u > 0) {
		if (white[u] != preWhite) break;
		int i = chainID[u];
		crrID = i, crrL = 1, crrR = pos[u];
		pLeft = get(root[i], 1, len[i]);
		crrID = i, crrL = pos[u]+1, crrR = len[i];
		pRight = get(root[i], 1, len[i]);
		if (pRight->lwhite == preWhite)
			ans += pRight->lsum[preWhite];
		if (pLeft->rwhite == preWhite)
			ans += pLeft->rsum[preWhite];
		else
			break;
		if (pre > -1)
			ans -= value;
		if (pos[u] >= 1)
			if (pLeft->lwhite != preWhite || !pLeft->full)
				break;
		pre = first[i];
		u = par[pre];
		value = root[i]->lsum[preWhite];
	}
	delete pLeft;
	delete pRight;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("QTREE6.in", "r", stdin);
	freopen("test.in", "r", stdin);
	freopen("QTREE6.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		e[i].clear();
		invPos[i].clear();
	}

	for (int i = 1; i < n; ++i) {
		int x = read(), y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}

	init_HLD(1);

	for (int i = 1; i <= n; ++i)
		white[i] = false;
	for (int i = 1; i <= nChain; ++i)
		a[i] = make_pair(-h[first[i]], i);
	sort(a+1, a+1+nChain);
	for (int i = 1; i <= nChain; ++i) {
		int k = a[i].second;
		crrID = k;
		root[k] = NULL;
		build(root[k], 1, len[k]);
	}

	int nQ = read();
	while (nQ--) {
		int t = read(), u = read();
		if (t == 0) printf("%d\n", query(u));
		else changeColor(u);
	}

	for (int i = 1; i <= nChain; ++i)
		remove(root[i]);
	return 0;
}