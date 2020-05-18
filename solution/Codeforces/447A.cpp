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


const int MAX_N = 333;

bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("447A.in", "r", stdin);
	freopen("447A.out", "w", stdout);
#endif
	fill(ok, true);
	int p, n;
	scanf("%d%d", &p, &n);
	for (int i = 0; i < n; ++i) {
		int x = read();
		x %= p;
		if (!ok[x]) {
			printf("%d\n", i+1);
			return 0;
		}
		ok[x] = false;
	}
	printf("-1");
	return 0;
}