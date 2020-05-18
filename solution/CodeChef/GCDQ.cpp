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


const int MAX_N = int(1e5) + 5;


int n, nQ;
int a[MAX_N], l[MAX_N], r[MAX_N];


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}


int main() {
#ifdef DEBUG
	freopen("GCDQ.in", "r", stdin);
	freopen("GCDQ.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%d%d", &n, &nQ);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		l[0] = r[n+1] = 0;
		for (int i = 1; i <= n; ++i)
			l[i] = gcd(a[i], l[i-1]);
		for (int i = n; i >= 1; --i)
			r[i] = gcd(a[i], r[i+1]);
		while (nQ--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", gcd(l[x-1], r[y+1]));
		}
	}
	return 0;
}