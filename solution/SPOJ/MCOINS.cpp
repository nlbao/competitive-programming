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

const int MAX_N = int(1e6) + 6;

bool win[MAX_N];


int main() {
#ifdef DEBUG
	freopen("MCOINS.in", "r", stdin);
	freopen("MCOINS.out", "w", stdout);
#endif
	int k, l, m;
	scanf("%d%d%d", &k, &l, &m);
	win[0] = false;
	for (int i = 1; i < MAX_N; ++i)
		win[i] = (!win[i-1]) || (i >= k && !win[i-k]) || (i >= l && !win[i-l]);

	for (int i = 0; i < m; ++i) {
		int n = read();
		if (win[n]) printf("A");
		else printf("B");
	}
	return 0;
}