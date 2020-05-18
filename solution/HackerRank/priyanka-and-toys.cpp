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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;

int a[MAX_N], f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("priyanka-and-toys.in", "r", stdin);
	freopen("priyanka-and-toys.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	sort(a, a+n);
	f[0] = 1;
	for (int i = 1; i < n; ++i) {
		f[i] = f[i-1] + 1;
		for (int j = i-1; j >= 0 && a[j]+4 >= a[i]; --j)
			f[i] = min(f[i], 1 + (j > 0 ? f[j-1] : 0));
	}
	printf("%d\n", f[n-1]);
	return 0;
}