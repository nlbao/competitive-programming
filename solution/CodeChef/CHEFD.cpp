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
const int ID[6] = {-1, -1, 0, 1, -1, 2};
const int PRIME[3] = {2, 3, 5};


int n, m;
int a[MAX_N], last[MAX_N], f[3][MAX_N];
vector<int> start[3][MAX_N], finish[3][MAX_N];


void update(int k, int i, int value) {
	if (i > m) return;
	f[k][i] += value;
	update(k, i + (i & (-i)), value);
}


int get(int k, int i) {
	if (i < 1) return 0;
	return f[k][i] + get(k, i - (i & (-i)));
}


int main() {
#ifdef DEBUG
	freopen("CHEFD.in", "r", stdin);
	freopen("CHEFD.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		last[i] = 0;
	}
	m = read();
	for (int i = 1; i <= m; ++i) {
		int t = read();
		if (t == 1) {
			int l, r, p;
			scanf("%d%d%d", &l, &r, &p);
			start[ID[p]][l].push_back(i);
			finish[ID[p]][r].push_back(i);
		}
		else {
			int x, d;
			scanf("%d%d", &x, &d);
			a[x] = d;
			last[x] = i;
		}
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j <= m; ++j)
			f[i][j] = 0;

	for (int x = 1; x <= n; ++x) {
		for (int k = 0; k < 3; ++k) {
			for (int i = 0, sz = (int)start[k][x].size(); i < sz; ++i)
				update(k, start[k][x][i], 1);

			int c = get(k, m) - get(k, last[x]);
			while (c > 0 && a[x] % PRIME[k] == 0) {
				a[x] /= PRIME[k];
				--c;
			}

			for (int i = 0, sz = (int)finish[k][x].size(); i < sz; ++i)
				update(k, finish[k][x][i], -1);
		}
		printf("%d ", a[x]);
	}
	return 0;
}