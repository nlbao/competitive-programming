#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e3) + 3;
const int LIMIT = int(1e5);
const int MAX_P = LIMIT + 2;
const int oo = int(1e9);

const int dx[5] = {-1, +1, 0, +1, -1};
const int dy[5] = {-1, -1, 0, +1, +1};


int n, k, nP;
bool ok[MAX_P];
int p[MAX_P], f[MAX_P];
int a[MAX_N][MAX_N];


void init() {
	nP = 0;
	filla(ok, true);
	ok[0] = ok[1] = false;
	f[0] = f[1] = oo;
	for (ll i = 2; i < MAX_P; ++i) {
		if (ok[i]) {
			p[nP++] = i;
			for (ll j = i*i; j < MAX_P; j += i)
				ok[j] = false;
		}
		f[i] = oo;
	}
	for (int i = 0; i < nP; ++i) f[p[i]] = 0;
	for (int i = LIMIT-k; i >= 0; --i)
		f[i] = min(f[i], f[i+k]+1);
}


bool solve() {
	int minSum = oo, ansX = -1, ansY = -1;
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < n; ++j) {
			int sum = 0;
			for (int t = 0; t < 5; ++t) {
				int x = i + dx[t], y = j + dy[t];
				int d = f[a[x][y]];
				if (d >= oo) {
					sum = oo+1;
					break;
				}
				sum += d;
			}
			if (sum < minSum) {
				minSum = sum;
				ansX = i;
				ansY = j;
			}
		}
	if (ansX == -1) return false;
	printf("yes\n");
	printf("%d\n%d %d\n", minSum, ansX, ansY);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("ikshu-and-his-new-year-matrix.in", "r", stdin);
	freopen("ikshu-and-his-new-year-matrix.out", "w", stdout);
#endif
	n = read();
	k = read();
	init();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = read();
	if (!solve()) printf("no\n");
	return 0;
}