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


const int MAX_N = int(1e5)+5;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("even-odd-query.in", "r", stdin);
	freopen("even-odd-query.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	int q = read();
	for (int i = 0; i < q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		int res = a[x]&1;
		if (x < y && a[x+1] == 0)
			res = 1;
		if (res)
			printf("Odd\n");
		else
			printf("Even\n");
	}
	return 0;
}