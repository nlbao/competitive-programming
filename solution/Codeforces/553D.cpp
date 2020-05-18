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
const double EPS = 1e-9;


int n, m, k;
vector<int> e[MAX_N], ans;
int d[MAX_N], c[MAX_N], sz[MAX_N];
bool ok[MAX_N], inQ[MAX_N];


bool check(double limit) {
	// printf("limit = %.7lf\n", limit);

	int m = n-k;
	queue<int> q;
	filla(inQ, false);
	for (int i = 1; i <= n; ++i) c[i] = d[i];
	for (int i = 1; i <= n; ++i)
		if (ok[i] && 1.0*c[i]/sz[i] + EPS <= limit) {
			q.push(i);
			inQ[i] = true;
			--m;
		}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		foreach(it, e[u]) {
			int v = *it;
			if (!ok[v] || inQ[v]) continue;
			--c[v];
			if (1.0*c[v]/sz[v] + EPS <= limit) {
				q.push(v);
				inQ[v] = true;
				--m;
				if (m <= 0) return false;
			}
		}
	}
	if (m <= 0) return false;
	ans.clear();
	for (int i = 1; i <= n; ++i)
		if (ok[i] && !inQ[i])
			ans.push_back(i);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("553D.in", "r", stdin);
	freopen("553D.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &k);
	filla(ok, true);
	for (int i = 0; i < k; ++i)
		ok[read()] = false;

	filla(d, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
		if (ok[y]) ++d[x];
		if (ok[x]) ++d[y];
	}
	for (int i = 1; i <= n; ++i)
		sz[i] = e[i].size();

	double l = 0, r = 1, t = -1;
	while (l + EPS <= r) {
		double mid = (l+r)/2.0;
		if (check(mid)) {
			l = mid;
			t = mid;
		}
		else r = mid;
	}

	// printf("t = %.7lf\n", t);

	n = ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);

	return 0;
}