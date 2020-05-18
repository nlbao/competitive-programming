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

const int MAX_N = 1003;
const int MODULE = int(1e9);

int c[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("ncr-table.in", "r", stdin);
	freopen("ncr-table.out", "w", stdout);
#endif
	for (int i = 0; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%MODULE;
	}

	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n = read();
		for (int i = 0; i <= n; ++i)
			printf("%d ", c[n][i]);
		printf("\n");
	}
	return 0;
}