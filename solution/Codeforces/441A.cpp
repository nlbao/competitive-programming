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


int main() {
#ifdef DEBUG
	freopen("441A.in", "r", stdin);
	freopen("441A.out", "w", stdout);
#endif
	int n, v;
	scanf("%d%d", &n, &v);
	vector<int> res;
	res.clear();
	for (int i = 0; i < n; ++i) {
		int k = read(), minX = int(1e7);
		for (int j = 0; j < k; ++j)
			minX = min(minX, read());
		if (minX < v) res.push_back(i+1);
	}
	int sz = res.size();
	printf("%d\n", sz);
	for (int i = 0; i < sz; ++i)
		printf("%d ", res[i]);
	return 0;
}