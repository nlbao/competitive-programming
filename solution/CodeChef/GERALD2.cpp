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
	int ld, rd;
	pii lf, rf;
	Node *lc, *rc;
	Node() {
		lc = rc = NULL;
		lf = rf = make_pair(-oo, -oo);
	}
};
typedef Node* pNode;


int n, nChain, crrID, crrPos, crrL, crrR;
int par[MAX_N], c[MAX_N], h[MAX_N], q[MAX_N];
int way[MAX_N], first[MAX_N], len[MAX_N], chainID[MAX_N], pos[MAX_N];
vector<int> e[MAX_N], invPos[MAX_N];
bool ok[MAX_N], white[MAX_N], isLeft;
pii a[MAX_N], lastValue[MAX_N];
pNode root[MAX_N];
set<pii> S[MAX_N];


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


inline pii getMax(int u) {
	if (S[u].empty()) return make_pair(-oo, -oo);
	return *(S[u].rbegin());
}


inline void subUpdate(pNode p) {
	pNode u = p->lc, v = p->rc;
	p->ld = u->ld, p->rd = v->rd;
	p->lf = u->lf;
	if (v->lf.first > -oo)
		p->lf = max(p->lf, make_pair(v->ld - u->ld + v->lf.first, v->lf.second));
	p->rf = v->rf;
	if (u->rf.first > -oo)
		p->rf = max(p->rf, make_pair(v->rd - u->rd + u->rf.first, u->rf.second));
}


void build(pNode &p, int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (p == NULL) p = new Node();
		int u = invPos[crrID][l];
		p->ld = p->rd = h[u];
		S[u].clear();
		S[u].insert(make_pair(0, u));
		for_each(it, e[u]) {
			int v = *it;
			if (par[v] != u || chainID[v] == chainID[u]) continue;
			lastValue[v] = root[chainID[v]]->lf;
			++lastValue[v].first;
			S[u].insert(lastValue[v]);
		}
		p->lf = p->rf = getMax(u);
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
		p->lf = p->rf = getMax(u);
		return;
	}
	int mid = (l+r)>>1;
	update(p->lc, l, mid);
	update(p->rc, mid+1, r);
	subUpdate(p);
}


pii get(pNode p, int l, int r) {
	if (l > r || l > crrR || r < crrL) return make_pair(-oo, -oo);
	if (crrL <= l && r <= crrR) {
		if (isLeft) {
			if (p->lf.first <= -oo) return make_pair(-oo, -oo);
			return make_pair(p->lf.first + p->ld - h[invPos[crrID][crrL]], p->lf.second);
		}
		else {
			if (p->rf.first <= -oo) return make_pair(-oo, -oo);
			return make_pair(p->rf.first + h[invPos[crrID][crrR]] - p->rd, p->rf.second);
		}
	}
	int mid = (l+r)>>1;
	return max(get(p->lc, l, mid), get(p->rc, mid+1, r));
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
	if (white[u]) S[u].insert(make_pair(0, u));
	else S[u].erase(make_pair(0, u));

	int pre = -1;
	pii value;
	while (u > 0) {
		int i = chainID[u];
		if (pre != -1) {
			if (value.first > -oo)
				value.first += h[pre] - h[u];
			if (lastValue[pre] == value) break;
			if (lastValue[pre].first > -oo)
				S[u].erase(lastValue[pre]);
			lastValue[pre] = value;
			if (value.first > -oo)
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
	int oldWhite = white[u];
	if (!oldWhite)
		changeColor(u);

	int sum = 0, v = u, pre = -1, oldU = u;
	pii ans = make_pair(-oo, -1), f;
	while (u > 0) {
		int i = chainID[u];
		if (pre != -1 && lastValue[pre].first > -oo) {
			S[u].erase(lastValue[pre]);
			crrID = i, crrPos = pos[u];
			update(root[i], 1, len[i]);
		}

		sum += h[v] - h[u];
		crrID = i, crrL = pos[u], crrR = len[i], isLeft = true;
		f = get(root[i], 1, len[i]);
		if (f.first > -oo) {
			f.first += sum;
			ans = max(ans, f);
		}
		crrID = i, crrL = 1, crrR = pos[u], isLeft = false;
		f = get(root[i], 1, len[i]);
		if (f.first > -oo) {
			f.first += sum;
			ans = max(ans, f);
		}

		if (pre != -1 && lastValue[pre].first > -oo) {
			S[u].insert(lastValue[pre]);
			crrID = i, crrPos = pos[u];
			update(root[i], 1, len[i]);
		}

		v = u;
		pre = first[i];
		u = par[pre];
	}

	if (oldWhite)
		changeColor(oldU);
	return ans.second;
}


int main() {
#ifdef DEBUG
	freopen("GERALD2.in", "r", stdin);
	freopen("GERALD2.out", "w", stdout);
#endif
	int nTest = read();
	while(nTest--) {
		n = read();
		int nQ = readln();
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			invPos[i].clear();
		}

		for (int i = 2; i <= n; ++i) {
			int x = read();
			e[x].push_back(i);
		}

		init_HLD(1);

		for (int i = 1; i <= n; ++i) {
			lastValue[i] = make_pair(-oo, -oo);
			white[i] = true;
		}
		for (int i = 1; i <= nChain; ++i)
			a[i] = make_pair(-h[first[i]], i);
		sort(a+1, a+1+nChain);
		for (int i = 1; i <= nChain; ++i) {
			int k = a[i].second;
			crrID = k;
			root[k] = NULL;
			build(root[k], 1, len[k]);
		}

		while (nQ--) {
			int u = read();
			printf("%d\n", query(u));
		}

		for (int i = 1; i <= nChain; ++i)
			remove(root[i]);
	}
	return 0;
}