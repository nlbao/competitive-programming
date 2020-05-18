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


bool oddWin(int k, int e, int o) {
	if (k == 0) return (o&1);
	int a = k/2;
	if (a >= o) return false;
	if (a < e) return true;
	return ((k-e)%2 != o%2);
}


bool evenWin(int k, int e, int o) {
	if (k == 0) return !(o&1);
	if (!(k&1)) {
		if (e > 0 && !oddWin(k-1, e-1, o))
			return true;
		if (o > 0 && !oddWin(k-1, e, o-1))
			return true;
		return false;
	}
	int a = k/2, b = k-a;
	if (b >= o) return true;
	if (a < e) return true;
	return ((k-e)%2 == o%2);
}


bool isStannisWin(int k, int e, int o) {
	if (k == 0) return (o&1);
	if (e > 0 && !evenWin(k-1, e-1, o))
		return true;
	if (o > 0 && !evenWin(k-1, e, o-1))
		return true;
	return false;
}


int main() {
#ifdef DEBUG
	freopen("549C.in", "r", stdin);
	freopen("549C.out", "w", stdout);
#endif
	int n, k, e = 0, o = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x = read();
		if (x&1) ++o;
		else ++e;
	}
	if (isStannisWin(n-k, e, o)) printf("Stannis");
	else printf("Daenerys");
	return 0;
}