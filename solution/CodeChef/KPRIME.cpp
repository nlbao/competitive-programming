#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+4;
const int MAX_K = 6;

bool ok[MAX_N];
int f[MAX_N];
int c[MAX_N][MAX_K];


int main() {
#ifdef DEBUG
	freopen("KPRIME.in", "r", stdin);
	freopen("KPRIME.out", "w", stdout);
#endif
	fill(f, 0);
	fill(ok, true);
	for (int i = 2; i < MAX_N; ++i) if (ok[i]) {
		f[i] = 1;
		for (int j = i+i; j < MAX_N; j += i) {
			ok[j] = false;
			++f[j];
		}
	}
	for (int i = 0; i < MAX_K; ++i)
		c[0][i] = c[1][i] = 0;
	for (int i = 2; i < MAX_N; ++i) {
		for (int j = 0; j < MAX_K; ++j)
			c[i][j] = c[i-1][j];
		++c[i][f[i]];
	}

	int nTest = read();
	while (nTest--) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		printf("%d\n", c[b][k] - c[a-1][k]);
	}
	return 0;
}