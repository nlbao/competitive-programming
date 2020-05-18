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


const int MAX_N = 1e4 + 4;


int turn[MAX_N];


int main() {
#ifdef DEBUG
	freopen("monk-in-the-real-estate.in", "r", stdin);
	freopen("monk-in-the-real-estate.out", "w", stdout);
#endif
	int nTest = read(), crrTurn = 0;
	filla(turn, 0);
	while (nTest--) {
		int n = read(), ans = 0;
		++crrTurn;
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (turn[x] < crrTurn) {
				turn[x] = crrTurn;
				++ans;
			}
			if (turn[y] < crrTurn) {
				turn[y] = crrTurn;
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}