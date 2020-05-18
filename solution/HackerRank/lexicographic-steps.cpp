#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 14;

int n, m;
ll f[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("lexicographic-steps.in", "r", stdin);
	freopen("lexicographic-steps.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &m, &n);
		for (int i = 0; i < MAX_N; ++i)
			for (int j = 0; j < MAX_N; ++j)
				f[i][j] = 0;
		f[n][m] = 1;
		for (int i = n; i >= 0; --i)
			for (int j = m; j >= 0; --j)
				f[i][j] += f[i][j+1] + f[i+1][j];

		ll k;
		scanf("%lld", &k);
		++k;
		int i = 0, j = 0;
		while (k > 0 && !(i >= n && j >= m)) {
			if (f[i][j+1] < k) {
				k -= f[i][j+1];
				printf("V");
				++i;
			}
			else {
				printf("H");
				++j;
			}
		}
		printf("\n");
	}
	return 0;
}