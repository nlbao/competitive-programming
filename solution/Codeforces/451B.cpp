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
	freopen("451B.in", "r", stdin);
	freopen("451B.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) a[i] = read();
	f[0] = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] < a[i-1]) f[i] = f[i-1];
		else f[i] = i;
	g[n-1] = n-1;
	for (int i = n-2; i >= 0; --i)
		if (a[i] < a[i+1]) g[i] = g[i+1];
		else g[i] = i;
	for (int i = 0; i < n; ++i) {
		if (f[i] > 1 && a[f[i]-1] < a[f[i]-2]) break;
		if (f[i] > 0 && a[f[i]-1] > a[i]) continue;
		if (i < n-1 && (a[f[i]] > a[i+1] || g[i+1] < n-1)) continue;
		printf("yes\n");
		printf("%d %d\n", f[i]+1, i+1);
		return 0;
	}
	printf("no\n");
	return 0;
}