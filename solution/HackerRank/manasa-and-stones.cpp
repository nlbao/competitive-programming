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


const int MAX_N = 1000006;

bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("manasa-and-stones.in", "r", stdin);
	freopen("manasa-and-stones.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		int n, a, b, maxValue = 0;
		scanf("%d%d%d", &n, &a, &b);
		fill(ok, false);
		for (int i = 0; i < n; ++i) {
			int j = n-1-i;
			int x = i*a + j*b;
			maxValue = max(maxValue, x);
			ok[x] = true;
		}
		for (int i = 0; i <= maxValue; ++i)
			if (ok[i])
				printf("%d ", i);
		printf("\n");
	}
	return 0;
}