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

const int MAX_M = 404;
const int MAX_C = 404;


int n, m;
int a[MAX_M], id[MAX_M];
int p[MAX_M][MAX_C];
bool ok[MAX_C];


int main() {
#ifdef DEBUG
	freopen("CLETAB.in", "r", stdin);
	freopen("CLETAB.out", "w", stdout);
#endif
	int nTest = read();
	while(nTest--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i)
			read(a[i]);

		for (int i = 0; i < MAX_C; ++i) p[m][i] = MAX_M;
		for (int i = m-1; i >= 0; --i) {
			for (int j = 0; j < MAX_C; ++j)
				p[i][j] = p[i+1][j];
			p[i][a[i]] = i;
		}

		int res = 0, i = 0, c = 0;
		fill(ok, false);
		for (; i < min(n, m); ++i)
			if (!ok[a[i]]) {
				++res;
				id[c++] = a[i];
				ok[a[i]] = true;
			}
		for(; i < m; ++i) {
			if (ok[a[i]]) continue;
			++res;
			if (c < n) {
				id[c++] = a[i];
				ok[a[i]] = true;
				continue;
			}
			int t = 0;
			for (int j = 0; j < n; ++j)
				if (p[i][id[j]] > p[i][id[t]])
					t = j;
			ok[id[t]] = false;
			id[t] = a[i];
			ok[a[i]] = true;
		}
		printf("%d\n", res);
	}
	return 0;
}