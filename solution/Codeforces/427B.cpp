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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 2*(1e5 + 5);

bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("427B.in", "r", stdin);
	freopen("427B.out", "w", stdout);
#endif
	int n, t, c;
	scanf("%d%d%d", &n, &t, &c);

	fill(ok, true);
	for (int i = 0; i < n; ++i) {
		int x = read();
		if (x <= t) continue;
		for (int j = i; j >= 0 && j > i-c; --j)
			if (!ok[j]) break;
			else ok[j] = false;
	}

	int res = 0;
	for (int i = 0; i <= n-c; ++i)
		res += ok[i];
	printf("%d\n", res);

	return 0;
}