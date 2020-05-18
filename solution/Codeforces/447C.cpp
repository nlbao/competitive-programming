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

const int MAX_N = int(1e5)+5;

int a[MAX_N], f[MAX_N], g[MAX_N];


int main() {
#ifdef DEBUG
	freopen("447C.in", "r", stdin);
	freopen("447C.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();

	int res = 1;
	// left
	f[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i-1]) f[i] = f[i-1] + 1;
		else f[i] = 1;
		// not change
		res = max(res, f[i]);
	}
	// right
	g[n-1] = 1;
	for (int i = n-2; i >= 0; --i)
		if (a[i] < a[i+1]) g[i] = g[i+1] + 1;
		else g[i] = 1;
	// change
	for (int i = 1; i < n; ++i)
		res = max(res, f[i-1] + 1);
	for (int i = n-2; i >= 0; --i)
		res = max(res, g[i+1] + 1);
	for (int i = 1; i < n-1; ++i)
		if (a[i-1] < a[i+1]-1)
			res = max(res, f[i-1] + g[i+1] + 1);
	printf("%d\n", res);
	return 0;
}