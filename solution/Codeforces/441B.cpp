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

const int MAX_N = 3333;
const int MAX_C = MAX_N;

int c[MAX_C];


int main() {
#ifdef DEBUG
	freopen("441B.in", "r", stdin);
	freopen("441B.out", "w", stdout);
#endif
	int n, v;
	scanf("%d%d", &n, &v);
	fill(c, 0);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		c[a] += b;
	}

	int res = 0;
	for (int i = 0; i < MAX_C; ++i) {
		int x = v;
		if (i && c[i-1]) {
			int t = min(c[i-1], x);
			res += t;
			x -= t;
		}
		int t = min(c[i], x);
		res += t;
		c[i] -= t;
	}
	printf("%d\n", res);
	return 0;
}