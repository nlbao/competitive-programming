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


const int MAX_N = 111;


int n;
int d[MAX_N], p[MAX_N];
bool checked[MAX_N];


bool solve() {
	filla(checked, false);
	filla(p, 0);
	for (int turn = 0; turn < n; ++turn) {
		int u = -1;
		for (int i = 1; i <= n; ++i)
			if (!checked[i])
				if (u == -1 || d[i] > d[u])
					u = i;
		if (u == -1) break;

		if (d[u] == 0) break;

		checked[u] = true;
		if (p[u] == 0) p[u] = -1;

		for (int t = 0; t < d[u]; ++t) {
			int v = -1;
			for (int i = 1; i <= n; ++i)
				if (!checked[i] && p[i] == 0)
					if (v == -1 || d[i] > d[v])
						v = i;
			if (v == -1) return false;
			p[v] = u;
			--d[v];
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("monk-at-the-graph-factory.in", "r", stdin);
	freopen("monk-at-the-graph-factory.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i)
		d[i] = read();
	if (solve()) printf("Yes");
	else printf("No");
	return 0;
}