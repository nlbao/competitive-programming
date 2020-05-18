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
#include <bitset>

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


const int MAX_N = 2003;

char a[MAX_N][MAX_N];
bitset<MAX_N> e[MAX_N];


int main() {
#ifdef DEBUG
	freopen("RRFRNDS.in", "r", stdin);
	freopen("RRFRNDS.out", "w", stdout);
#endif
	int n = read();
	scanf("\n");
	for (int i = 0; i < n; ++i) {
		e[i].reset();
		scanf("%s\n", a[i]);
		for (int j = 0; j < n; ++j)
			if (a[i][j] == '1')
				e[i].set(j);
	}

	int res = 0;
	for (int u = 0; u < n; ++u) {
		for (int v = u+1; v < n; ++v)
			if (a[u][v] == '0')
				if ((e[u] & e[v]).any())
					res += 2;
	}
	printf("%d\n", res);
	return 0;
}