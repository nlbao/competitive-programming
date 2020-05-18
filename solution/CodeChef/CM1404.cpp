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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

int f(int n) {
	if (n < 2) return 0;
	if (n == 2) return 1;
	int k = 1, s = 2;
	while (s + (k+1) <= n) {
		++k;
		s += k;
	}
	if (s < n) ++k;
	return k;
}


int main() {
#ifdef DEBUG
	freopen("CM1404.in", "r", stdin);
	freopen("CM1404.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		printf("%d\n", f(n));
	}
	return 0;
}