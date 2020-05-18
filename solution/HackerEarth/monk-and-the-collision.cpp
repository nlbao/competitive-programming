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


const int MAX_X = 15;


bool ok[MAX_X];


int main() {
#ifdef DEBUG
	freopen("monk-and-the-collision.in", "r", stdin);
	freopen("monk-and-the-collision.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read(), ans = 0;
		filla(ok, true);
		for (int i = 0; i < n; ++i) {
			int x = read() % 10;
			if (ok[x]) ok[x] = false;
			else ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}