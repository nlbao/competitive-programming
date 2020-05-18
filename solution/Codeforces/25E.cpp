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

const int MAX_N = int(1e5)+5;
const ll BASE = 10007;


char s[3][MAX_N];
int len[3], f[3][3];
ll h[3][MAX_N], p[MAX_N];


ll getH(int id, int i, int j) {
	if (i == 0) return h[id][j];
	return h[id][j] - h[id][i-1] * p[j-i+1];
}


int calF(int x, int y) {
	int ans = len[y];
	for (int i = len[x]-1; i >= 0; --i) {
		int j = min(i + len[y] - 1, len[x] - 1);
		if (getH(x, i, j) == getH(y, 0, j - i))
			ans = len[y] - (j-i+1);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("25E.in", "r", stdin);
	freopen("25E.out", "w", stdout);
#endif
	for (int id = 0; id < 3; ++id) {
		scanf("%s\n", s[id]);
		len[id] = strlen(s[id]);
		h[id][0] = s[id][0];
		for (int i = 1; i < len[id]; ++i)
			h[id][i] = h[id][i-1]*BASE + s[id][i];
	}

	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			f[i][j] = calF(i, j);

	int ans = len[0] + len[1] + len[2];
	for (int x = 0; x < 3; ++x)
		for (int y = 0; y < 3; ++y)
			for (int z = 0; z < 3; ++z)
				if (x != y && x != z && y != z) {
					int t = len[x] + f[x][y] + f[y][z];
					if (f[x][z] == 0) t -= f[y][z];
					ans = min(ans, t);
				}
	printf("%d\n", ans);
	return 0;
}