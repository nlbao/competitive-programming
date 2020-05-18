#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


int main() {
#ifdef DEBUG
	freopen("6681.in", "r", stdin);
	freopen("6681.out", "w", stdout);
#endif
	while (scanf("%d", &n)) {
		scanf("%d%d%d", &p, &c, &h);
		for (int i = 1; i <= n; ++i) b[i] = read();
		for (int i = 1; i <= p; ++i) l[i] = read();
		fill(f, 0);
		fill(last, 0);
		fill(hasOtherColorAfterLast, false);
		for (int i = p, nColor = 0; i >= 1; --i) {
			++f[l[i]];
			if (f[l[i]] == 1) {
				++nColor;
				last[l[i]] = i;
				hasOtherColorAfterLast[l[i]] = nColor > (1 + (f[h] > 0));
			}
		}
		fill(fa, 0);
		for (int i = n; i >= 1; --i) {
			++fa[b[i]];
		}
		// solve
		res.clear();
		for (int i = 1; i <= n; ++i) {
			--fa[b[i]];
			++fa[h];
			// if (solve())
			--fa[h];
			++fa[b[i]];
		}
		int sz = res.size();
		printf("%d\n", sz);
		for (int i = 0; i < sz; ++i)
			printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}