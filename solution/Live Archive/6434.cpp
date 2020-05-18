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

const int MAX_N = 111;
const int oo = int(1e9)+9;

int m, n;
int a[MAX_N], f[MAX_N][MAX_N];


int solve() {
	sort(a, a+n);
	f[0][1] = 0;
	for (int i = 1; i < n; ++i) {
		f[i][1] = a[i] - a[0];
		for (int j = 2; j <= min(m, i+1); ++j) {
			f[i][j] = f[i-1][j-1];
			for (int k = j-2; k < i-1; ++k)
				f[i][j] = min(f[i][j], f[k][j-1] + a[i]-a[k+1]);
		}
	}
	return f[n-1][m];
}


int main() {
#ifdef DEBUG
	freopen("6434.in", "r", stdin);
	freopen("6434.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			a[i] = read();
		printf("Case #%d: %d\n", test_id+1, solve());
	}
	return 0;
}