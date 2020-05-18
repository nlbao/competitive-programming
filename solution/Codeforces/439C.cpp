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

const int MAX_N = int(1e5+5);

vector<int> odd, even;
vector<int> res[MAX_N];


int pop(vector<int> &v) {
	int res = v.back();
	v.pop_back();
	return res;
}


int main() {
#ifdef DEBUG
	freopen("439C.in", "r", stdin);
	freopen("439C.out", "w", stdout);
#endif
	int n, k, p;
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i < n; ++i) {
		int x = read();
		if (x&1) odd.push_back(x);
		else even.push_back(x);
	}

	int x = even.size(), y = odd.size() - (k-p);
	if (y < 0 || (y&1) || x+(y>>1) < p) {
		printf("NO");
		return 0;
	}

	printf("YES\n");
	for (int i = 0; i < k-p; ++i)
		res[i].push_back(pop(odd));

	int m = k-p-1;
	for (int i = 0; i < p; ++i) {
		++m;
		if (!even.empty())
			res[m].push_back(pop(even));
		else for (int j = 0; j < 2; ++j)
			res[m].push_back(pop(odd));
	}
	while (!even.empty()) res[m].push_back(pop(even));
	while (!odd.empty()) res[m].push_back(pop(odd));

	for (int i = 0; i < k; ++i) {
		int sz = res[i].size();
		printf("%d ", sz);
		for (int j = 0; j < sz; ++j)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}