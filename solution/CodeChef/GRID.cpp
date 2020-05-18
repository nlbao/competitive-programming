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

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e3) + 3;

char a[MAX_N][MAX_N];
bool row[MAX_N], col[MAX_N];


int main() {
#ifdef DEBUG
	freopen("GRID.in", "r", stdin);
	freopen("GRID.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n, ans = 0;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s\n", a[i]);

		for (int i = 0; i < n; ++i) col[i] = true;
		for (int i = n-1; i >= 0; --i) {
			row[n] = true;
			for (int j = n-1; j >= 0; --j) {
				col[j] = col[j] && (a[i][j] == '.');
				row[j] = row[j+1] && (a[i][j] == '.');
				if (col[j] && row[j]) ++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}