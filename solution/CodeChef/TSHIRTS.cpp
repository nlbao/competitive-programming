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

const int MAX_N = 14;
const int MAX_T = 104;
const int MAX_LEN = 4*MAX_T;
const int MAX_P = 1<<MAX_N;
const int MODULE = int(1e9) + 7;


char s[MAX_N];
bool ok[MAX_N][MAX_T];
int f[MAX_T][MAX_P];
stringstream parser;

int mmod(int x) {
	return x%MODULE;
}

int main() {
#ifdef DEBUG
	freopen("TSHIRTS.in", "r", stdin);
	freopen("TSHIRTS.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, maxT = 0;
		scanf("%d\n", &n);
		fill(ok, false);
		for (int x = 0; x < n; ++x) {
			scanf("%[0-9 ]\n", s);
			parser << string(s);
			int t;
			while (parser >> t) {
				ok[x][t] = true;
				maxT = max(maxT, t);
			}
			parser.clear();
		}

		int m = (1<<n);
		fill(f, 0);
		f[0][0] = 1;
		for (int i = 1; i <= maxT; ++i) {
			for (int mask = m-2; mask >= 0; --mask) if (f[i-1][mask] > 0)
				for (int x = 0; x < n; ++x) {
					int dst = mask | (1<<x);
					if (dst != mask && ok[x][i])
						f[i][dst] = mmod(f[i][dst] + f[i-1][mask]);
				}
			for (int mask = 0; mask < m; ++mask)
				f[i][mask] = mmod(f[i][mask] + f[i-1][mask]);
		}
		printf("%d\n", f[maxT][m-1]);
	}
	return 0;
}