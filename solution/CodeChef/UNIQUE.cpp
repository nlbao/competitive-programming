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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;

int n, u, v, value;
char s[MAX_N];
int key[MAX_N], c[MAX_N], sa[MAX_N], sb[MAX_N], rank[MAX_N], lcp[MAX_N];
bool mark[MAX_N];
int f[4*MAX_N], g[MAX_N], pos[MAX_N], length[MAX_N], p[MAX_N];
pii a[MAX_N];


void build_sa() {
	s[n++] = 1;
	fill(c, 0);
	for (int i = 0; i < n; ++i) ++c[key[i] = s[i]];
	for (int i = 1; i < MAX_N; ++i) c[i] += c[i-1];
	for (int i = n-1; i >= 0; --i) sa[--c[key[i]]] = i;
	mark[0] = true;
	for (int i = 1; i < n; ++i)
		mark[i] = key[sa[i-1]] != key[sa[i]];

	for (int k = 1; k <= n; k <<= 1) {
		int nKey = 0;
		for (int i = 0; i < n; ++i) {
			if (mark[i]) ++nKey;
			key[sa[i]] = nKey;
			sb[i] = (sa[i] - k + n)%n;
		}
		fill(c, 0);
		for (int i = 0; i < n; ++i) ++c[key[i]];
		for (int i = 1; i <= nKey; ++i) c[i] += c[i-1];
		for (int i = n-1; i >= 0; --i) sa[--c[key[sb[i]]]] = sb[i];
		for (int i = 1; i < n; ++i)
			mark[i] = mark[i] || (key[(sa[i-1]+k)%n] != key[(sa[i]+k)%n]);
	}
}


void build_lcp() {
	for (int i = 0; i < n; ++i) rank[sa[i]] = i;
	lcp[0] = 1;
	for (int i = 0, q = 0; i < n-1; ++i) {
		int j = sa[rank[i]-1];
		while (s[i+q] == s[j+q]) ++q;
		lcp[rank[i]] = q;
		q = max(q-1, 0);
	}
}


void update(int k, int l, int r) {
	if (l > r) return;
	if (u > r || v < l) return;
	if (f[k] > -1) return;
	if (u <= l && r <= v) {
		f[k] = value;
		// cout << "!!! " << l << ", " << r << ": " << value << endl;
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	update(left, l, mid);
	update(right, mid+1, r);
}


int get(int k, int l, int r) {
	if (l > r || l > u || r < u) return -1;
	if (l == r) return f[k];
	int mid = (l+r)>>1, t = -1;
	if (u <= mid) t = get(k<<1, l, mid);
	else t = get((k<<1)+1, mid+1, r);
	if (t == -1) t = f[k];
	return t;
}


int main() {
#ifdef DEBUG
	freopen("UNIQUE.in", "r", stdin);
	freopen("UNIQUE.out", "w", stdout);
#endif
	scanf("%s\n", s);
	n = strlen(s);
	int len = n;
	build_sa();
	build_lcp();

	p[n-1] = lcp[n-1] + 1;
	for (int i = n-2; i >= 0; --i)
		p[i] = max(lcp[i+1], lcp[i]) + 1;
	for (int i = 1; i < n; ++i)
		a[i-1] = make_pair(p[i], i);
	sort(a, a+n-1);

	// for (int i = 0; i < n; ++i) cout << sa[i] << " ";	cout << endl;
	// for (int i = 0; i < n; ++i) cout << lcp[i] << " ";	cout << endl;
	// for (int i = 0; i < n; ++i) cout << p[i] << " ";	cout << endl;

	fill(f, -1);
	// for (int i = n-2; i >= 0; --i) {
	for (int i = 0; i < n-1; ++i) {
		int x = sa[a[i].second];
		if (x + a[i].first - 1 < len) {
			u = x + 1;
			v = x + a[i].first;
			value = x;
			// cout << "			update: " << u << " " << v << " : " << value << endl;
			update(1, 1, len);
		}
	}
	for (int i = 0; i < len; ++i) {
		u = i+1;
		pos[i] = get(1, 1, len);
		length[i] = (pos[i] < 0) ? len+1 : p[rank[pos[i]]];
		// cout << i << " " << pos[i] << " " << length[i] << endl;
	}

	fill(g, -1);
	for (int i = 1; i < n; ++i)
		g[sa[i] + p[i] - 1] = sa[i];
	for (int i = 0, t = -1; i < len; ++i) {
		t = max(t, g[i]);
		// cout << "t: " << i << " " << t << endl;
		if (t < 0) continue;
		int l = i-t+1;
		if (l < length[i] || (l == length[i] && rank[t] < rank[pos[i]])) {
			pos[i] = t;
			length[i] = l;
		}
	}

	for (int i = 0; i < len; ++i)
		printf("%d %d\n", pos[i]+1, length[i]);
	return 0;
}