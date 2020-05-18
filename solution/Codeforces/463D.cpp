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
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 1011;
const int MAX_K = 7;

int n, k;
int pos[MAX_N][MAX_K], minPos[MAX_N];
int id[MAX_N], f[MAX_N];


bool cmp(int x, int y) {
	return minPos[x] < minPos[y];
}


bool ok(int x, int y) {
	for (int i = 0; i < k; ++i)
		if (pos[x][i] > pos[y][i])
			return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("463D.in", "r", stdin);
	freopen("463D.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n; ++i) minPos[i] = n+2;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			int x = read();
			pos[x][i] = j;
			minPos[x] = min(minPos[x], j);
		}
	}

	for (int i = 0; i < n; ++i) id[i] = i+1;
	sort(id, id+n, cmp);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int u = id[i];
		f[u] = 1;
		for (int j = 0; j < i; ++j) {
			int v = id[j];
			if (ok(v, u))
				f[u] = max(f[u], f[v]+1);
		}
		ans = max(ans, f[u]);
	}
	printf("%d\n", ans);
	return 0;
}