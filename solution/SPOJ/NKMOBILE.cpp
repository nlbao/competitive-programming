#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1044;


struct RangeTree {
	int m, n;
	int f[MAX_N][MAX_N];

	void init(int mm, int nn) {
		m = mm, n = nn;
		filla(f, 0);
	}

	void update(int x, int y, int value) {
		for (; x <= m; x += x&(-x))
			for (int i = y; i <= n; i += i&(-i))
				f[x][i] += value;
	}

	int get(int x, int y) {
		int ans = 0;
		for (; x > 0; x -= x&(-x))
			for (int i = y; i > 0; i -= i&(-i))
				ans += f[x][i];
		return ans;
	}

	int getRect(int x1, int y1, int x2, int y2) {
		return get(x2, y2) - get(x1-1, y2) - get(x2, y1-1) + get(x1-1, y1-1);
	}
};


RangeTree tree;


int main() {
#ifdef DEBUG
	freopen("NKMOBILE.in", "r", stdin);
	freopen("NKMOBILE.out", "w", stdout);
#endif
	int n = read();
	n = read();
	tree.init(n, n);
	while (true) {
		int t = read();
		if (t == 3) break;
		if (t == 1) {
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			tree.update(x+1, y+1, a);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			printf("%d\n", tree.getRect(x1+1, y1+1, x2+1, y2+1));
		}
	}
	return 0;
}