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

bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("RRCOPY.in", "r", stdin);
	freopen("RRCOPY.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n = read(), c = 0;
		fill(ok, true);
		for (int i = 0; i < n; ++i) {
			int x = read();
			if (ok[x]) {
				++c;
				ok[x] = false;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}