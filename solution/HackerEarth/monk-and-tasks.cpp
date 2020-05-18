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
const int MAX_BIT = 61;


int n, crrTurn;
ll a[MAX_N];
int turn[MAX_BIT][MAX_N];


inline int bitCount(ll x) {
	int ans = 0;
	while (x > 0) {
		if (x&1) ++ans;
		x >>= 1;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("monk-and-tasks.in", "r", stdin);
	freopen("monk-and-tasks.out", "w", stdout);
#endif
	filla(turn, 0);
	int nTest = read();
	while (nTest--) {
		n = read();
		++crrTurn;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
			int x = bitCount(a[i]);
			turn[x][i] = crrTurn;
		}
		for (int x = 0; x < MAX_BIT; ++x)
			for (int i = 0; i < n; ++i)
				if (turn[x][i] == crrTurn)
					printf("%d ", a[i]);
		printf("\n");
	}
	return 0;
}