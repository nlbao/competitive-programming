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


const int MAX_N = 555;


int n, m;
bool a[MAX_N][MAX_N];


inline void addEdge(int u, int v) {
	++m;
	a[u][v] = a[v][u] = true;
}


void createEdge(int s, int k) {
	int t = n + k+1, c = k-1;
	for (int i = n+1; i <= t; ++i)
		for (int j = i+1; j <= t; ++j) {
			if (c > 0 && !a[i][s] && !a[j][s]) {
				addEdge(i, s);
				addEdge(j, s);
				c -= 2;
			}
			else addEdge(i, j);
		}
	n = t;
}


bool solve(int k) {
	if (k%2 == 0) return false;
	printf("YES\n");
	if (k == 1) {
		printf("2 1\n1 2");
		return true;
	}

	n = 2, m = 0;
	int s = 1, t = 2;
	filla(a, false);
	addEdge(s, t);
	createEdge(s, k);
	createEdge(t, k);

	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
			if (a[i][j])
				printf("%d %d\n", i, j);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("550D.in", "r", stdin);
	freopen("550D.out", "w", stdout);
#endif
	int k = read();
	if (!solve(k)) printf("NO");
	return 0;
}