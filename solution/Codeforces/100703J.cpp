#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;
const int MAX_Q = 2e5 + 5;
const int oo = 1e9 + 9;

int n, m, nQ;
int t[MAX_N], p[MAX_N], del[MAX_N];
int g[MAX_Q], f[MAX_Q];
bool ok[MAX_N];
vector<int> e[MAX_N];
pii q[MAX_Q];
ll ans[MAX_Q];


int find(int limit) {
	int l = 0, r = nQ-1, ans = oo;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (q[mid].first > limit) {
			ans = f[mid];
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


int getRoot(int u) {
	if (p[u] < 0) return u;
	return p[u] = getRoot(p[u]);
}


inline void update(int u) {
	if (!ok[u]) return;
	int r = getRoot(u);
	foreach(it, e[u]) {
		int v = *it;
		if (!ok[v]) continue;
		v = getRoot(v);
		if (r != v) {
			p[r] += p[v];
			p[v] = r;
		}
	}
}



int main() {
#ifdef DEBUG
	freopen("100703J.in", "r", stdin);
	freopen("100703J.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &nQ);
	t[1] = oo;
	for (int i = 2; i <= n; ++i)
		t[i] = read();

	for (int i = 0; i < nQ; ++i) {
		g[i] = read();
		q[i] = pii(g[i], i);
	}
	sort(q, q+nQ);
	f[nQ-1] = q[nQ-1].second;
	for (int i = nQ-2; i >= 0; --i)
		f[i] = min(f[i+1], q[i].second);
	for (int i = 1; i <= n; ++i)
		del[i] = find(t[i]);

	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}

	m = 0;
	filla(ok, true);
	for (int i = 1; i <= n; ++i) {
		if (del[i] < nQ) {
			ok[i] = false;
			q[m++] = pii(del[i], i);
		}
		p[i] = -1;
	}
	sort(q, q+m);
	for (int i = 1; i <= n; ++i)
		update(i);

	--m;
	for (int i = nQ-1; i >= 0; --i) {
		int r = getRoot(1);
		ans[i] = ll(-p[r]) * g[i];
		while (m >= 0 && q[m].first >= i) {
			int u = q[m].second;
			ok[u] = true;
			update(u);
			--m;
		}
	}

	for (int i = 0; i < nQ; ++i)
		printf("%lld ", ans[i]);
	return 0;
}