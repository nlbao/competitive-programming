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

const int MAX_N = int(1e5) + 5;

int a[MAX_N];
int r[MAX_N];


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


int main() {
#ifdef DEBUG
	freopen("SUBGCD.in", "r", stdin);
	freopen("SUBGCD.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		int d = a[1];
		for (int i = 2; i <= n; ++i)
			d = gcd(d, a[i]);
		if (n > 1 && d == 1) printf("%d\n", n);
		else printf("-1\n");
	}
	return 0;
}