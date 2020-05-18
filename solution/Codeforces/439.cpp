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
	freopen("439.in", "r", stdin);
	freopen("439.out", "w", stdout);
#endif
	int n, d, s = 0;
	int t[111];
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; ++i) {
		t[i] = read();
		s += t[i];
	}
	s += (n-1)*10;
	if (s > d) {
		printf("-1");
		return 0;
	}
	printf("%d\n", (n-1)*2 + (d-s)/5);
	return 0;
}