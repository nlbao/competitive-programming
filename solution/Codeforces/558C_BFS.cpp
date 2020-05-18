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
const int MAX_A = 1e5 + 5;


int n, crrTurn;
int a[MAX_N];
int turn[MAX_A], c[MAX_A], f[MAX_A], d[MAX_A];
queue<int> q;


void bfs(int s, int frequence) {
	++crrTurn;
	while (!q.empty()) q.pop();
	d[s] = 0;
	q.push(s);
	turn[s] = crrTurn;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		c[u] += frequence;
		f[u] += frequence * d[u];
		for (int v = u, t = 0; v >= 1; v >>= 1, ++t)
			for (int x = v, k = 0; x < MAX_A && (x == u || turn[x] != crrTurn); x <<= 1, ++k)
				if (turn[x] != crrTurn) {
					turn[x] = crrTurn;
					d[x] = d[u] + t + k;
					q.push(x);
				}
	}
}


int main() {
#ifdef DEBUG
	freopen("558C.in", "r", stdin);
	freopen("558C.out", "w", stdout);
#endif
	filla(a, 0);
	int n = read();
	for (int i = 0; i < n; ++i) {
		int x = read();
		++a[x];
	}

	crrTurn = 0;
	filla(turn, 0);
	filla(f, 0);
	filla(c, 0);
	for (int i = 0; i < MAX_A; ++i)
		if (a[i] > 0)
			bfs(i, a[i]);

	int ans = 1e9;
	for (int i = 1; i < MAX_A; ++i)
		if (c[i] == n)
			ans = min(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}