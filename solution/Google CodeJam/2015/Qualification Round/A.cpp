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

int smax;
char c[MAX_N];


int main() {
#ifdef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d %s", &smax, c);
		// printf("%d %s %c\n", smax, c, c[0]);
		int sum = 0, maxD = 0;
		for (int i = 0; i <= smax; ++i) {
			maxD = max(maxD, i-sum);
			sum += c[i]-'0';
		}
		printf("Case #%d: %d\n", testid, maxD);
	}
	return 0;
}