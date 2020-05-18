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


const int MAX_N = 2e5 + 5;


int n;
int a[MAX_N];


void solve() {
	for (int i = 0; i < n; ++i)
		a[i] += i;
	sort(a, a+n);
	for (int i = 0; i < n-1; ++i)
		if (a[i] >= a[i+1]) {
			printf(":(");
			return;
		}
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]-i);
}


int main() {
#ifdef DEBUG
	freopen("549G.in", "r", stdin);
	freopen("549G.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	solve();
	return 0;
}