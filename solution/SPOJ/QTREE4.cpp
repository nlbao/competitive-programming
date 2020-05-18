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
const int oo = 2*int(1e9);


struct Node {
	int ld, rd, lf, rf, f;
	Node *lc, *rc;
	Node() {
		lc = rc = NULL;
		lf = rf = f = -oo;
	}
};
typedef Node* pNode;


int n, nChain, crrID, crrPos;
vector<pii> e[MAX_N];
int par[MAX_N], c[MAX_N], h[MAX_N], d[MAX_N], first[MAX_N], len[MAX_N], chainId[MAX_N];
int pos[MAX_N], lastValue[MAX_N];
vector<int> invPos[MAX_N];
bool ok[MAX_N], white[MAX_N];
pii a[MAX_N];
pNode root[MAX_N];
multiset<int> S[MAX_N], ans;


void dfs(int u) {
	ok[u] = false;
	c[u] = 1;
	for_each(it, e[u]) {
		int v = it->second;
		if (ok[v]) {
			par[v] = u;
			h[v] = h[u]+1;
			d[v] = d[u] + it->first;
			dfs(v);
			c[u] += c[v];
		}
	}
}


void HLD(int u) {
	chainId[u] = nChain;
	pos[u] = ++len[nChain];
	invPos[nChain].push_back(u);
	int k = -1;
	for_each(it, e[u]) {
		int v = it->second;
		if (par[v] == u && (k == -1 || c[v] > c[k]))
			k = v;
	}
	if (k > 0) HLD(k);
	for_each(it, e[u]) {
		int v = it->second;
		if (v == k || par[v] != u) continue;
		first[++nChain] = v;
		len[nChain] = 0;
		invPos[nChain].push_back(-1);
		HLD(v);
	}
}


inline void getMax(int u, int &f1, int &f2) {
	f1 = f2 = -oo;
	if (S[u].empty()) return;
	multiset<int>::reverse_iterator it = S[u].rbegin();
	f1 = *it;
	++it;
	if (it != S[u].rend())
		f2 = *it;
}


inline void subUpdate(pNode p) {
	pNode u = p->lc, v = p->rc;
	p->ld = u->ld, p->rd = v->rd;
	p->lf = u->lf;
	if (v->lf > -oo)
		p->lf = max(p->lf, v->ld - u->ld + v->lf);
	p->rf = v->rf;
	if (u->rf > -oo)
		p->rf = max(p->rf, v->rd - u->rd + u->rf);
	p->f = max(u->f, v->f);
	if (u->rf > -oo && v->lf > -oo)
		p->f = max(p->f, u->rf + v->lf + v->ld - u->rd);
}


void build(pNode &p, int l, int r) {
	if (l > r) return;
	if (l == r) {
		if (p == NULL) p = new Node();
		int u = invPos[crrID][l], f1, f2;
		p->ld = p->rd = d[u];
		S[u].insert(0);
		for_each(it, e[u]) {
			int v = it->second;
			if (par[v] != u || chainId[v] == chainId[u]) continue;
			lastValue[v] = root[chainId[v]]->lf;
			if (lastValue[v] > -oo) {
				lastValue[v] += it->first;
				S[u].insert(lastValue[v]);
			}
		}
		getMax(u, f1, f2);
		p->lf = p->rf = p->f = f1;
		if (f2 > -oo)
			p->f = max(p->f, f1+f2);
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
		int u = invPos[crrID][l], f1, f2;
		getMax(u, f1, f2);
		p->lf = p->rf = f1;
		if (white[u]) p->f = max(f1, f2 > -oo ? f1+f2 : -oo);
		else p->f = f2 > -oo ? f1+f2 : -oo;
		return;
	}
	int mid = (l+r)>>1;
	update(p->lc, l, mid);
	update(p->rc, mid+1, r);
	subUpdate(p);
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
		int i = chainId[u];
		if (pre > 0) {
			if (value > -oo)
				value += d[pre] - d[u];
			if (lastValue[pre] == value) break;
			if (lastValue[pre] > -oo)
				S[u].erase(S[u].find(lastValue[pre]));
			lastValue[pre] = value;
			if (value > -oo)
				S[u].insert(value);
		}

		crrID = i, crrPos = pos[u];
		int lastF = root[i]->f;
		update(root[i], 1, len[i]);
		int newF = root[i]->f;
		if (newF != lastF) {
			ans.erase(ans.find(lastF));
			ans.insert(newF);
		}

		pre = first[i];
		u = par[pre];
		value = root[i]->lf;
	}
}


int main() {
#ifdef DEBUG
	freopen("QTREE4.in", "r", stdin);
	freopen("QTREE4.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d\n", &x, &y, &z);
		e[x].push_back(make_pair(z, y));
		e[y].push_back(make_pair(z, x));
	}

	filla(ok, true);
	par[1] = 0;
	h[1] = 1;
	d[1] = 0;
	dfs(1);

	nChain = 1;
	first[1] = 1;
	len[1] = 0;
	invPos[1].push_back(-1);
	HLD(1);

	filla(white, true);
	for (int i = 1; i <= nChain; ++i)
		a[i] = make_pair(-h[first[i]], i);
	sort(a+1, a+1+nChain);
	for (int i = 1; i <= nChain; ++i) {
		int k = a[i].second;
		crrID = k;
		root[k] = NULL;
		build(root[k], 1, len[k]);
		ans.insert(root[k]->f);
	}

	int nQ = readln();
	while (nQ--) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'A') {
			scanf("\n");
			int f = -oo;
			if (!ans.empty())
				f = *(ans.rbegin());
			if (f > -oo) printf("%d\n", f);
			else printf("They have disappeared.\n");
		}
		else {
			int u = readln();
			changeColor(u);
		}
	}

	for (int i = 1; i <= nChain; ++i)
		remove(root[i]);
	return 0;
}