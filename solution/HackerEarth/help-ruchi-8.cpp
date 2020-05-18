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

const int MAX_N = 33*int(1e3)+4;
const int MAX_A = int(1e6)+6;


bool solve(int n) {
	return n%2 == 1;
}


int main() {
#ifdef DEBUG
	freopen("help-ruchi-8.in", "r", stdin);
	freopen("help-ruchi-8.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read();
		if (solve(n)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}