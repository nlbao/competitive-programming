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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 55;
const ld EPS = 1e-9;

vector< vector<ld> > a;


inline ld xabs(ld x) {
	return x < 0 ? -x : x;
}


ld determinant(vector< vector<ld> > &a, int n) {
	ld det = 1.0;
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i; j < n; j++)
			if (xabs(a[j][i]) > xabs(a[k][i]))
				k = j;
		if (xabs(a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap(a[i], a[k]);
		if (i != k) det *= -1;
		det *= a[i][i];
		for (int j = i + 1; j < n; j++)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; j++)
			if (j != i && xabs(a[j][i]) > EPS)
				for (int k = i + 1; k < n; k++)
					a[j][k] -= a[i][k] * a[j][i];
	}
	return det;
}


int main() {
#ifdef DEBUG
	freopen("10766.in", "r", stdin);
	freopen("10766.out", "w", stdout);
#endif
	int n, m, k;
	while(scanf("%d%d%d", &n, &m, &k) != EOF) {
		// read the graph and create the n*n matrix:
		// + if i == j then a[i][i] = degree(i).
		// + if i != j then a[i][j] = -x where x is the number of edge between i and j.
		a.clear();
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			a[i].resize(n, -1);
			a[i][i] = n-1;
		}
		for (int i = 0; i < m; ++i) {
			int x = read(), y = read();
			if (x == y) continue;
			--x;	--y;
			if (fabs(a[x][y]+1) < EPS) {
				a[x][y] = a[y][x] = 0;
				--a[x][x];	--a[y][y];
			}
		}
		// calculate the determinant of the (n-1)*(n-1) matrix (remove last row and last column).
		ll ans = roundl(determinant(a, n-1));
		printf("%lld\n", ans);
	}
	return 0;
}