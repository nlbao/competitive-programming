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


const int MAX_N = 1e6 + 6;
const int oo = 1e9;


int n, m, s, t;
vector<int> e[MAX_N], inv[MAX_N];
queue<int> q;
bool inQ[MAX_N];
int d[MAX_N];


inline void push(int u) {
	if (inQ[u]) return;
	q.push(u);
	inQ[u] = true;
}


int main() {
#ifdef DEBUG
	freopen("346D.in", "r", stdin);
	freopen("346D.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		inv[y].push_back(x);
	}
	scanf("%d%d", &s, &t);

	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	filla(inQ, false);
	d[t] = 0;
	foreach(it, inv[t]) push(*it);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inQ[u] = false;
		int maxD = 0, minD = oo, oldD = d[u];
		foreach(it, e[u]) {
			maxD = max(maxD, d[*it]);
			minD = min(minD, d[*it]);
		}
		d[u] = min(d[u], min(maxD, minD+1));
		if (d[u] < oldD)
			foreach(it, inv[u])
				push(*it);
	}

	if (d[s] >= oo) printf("-1");
	else printf("%d\n", d[s]);
	return 0;
}