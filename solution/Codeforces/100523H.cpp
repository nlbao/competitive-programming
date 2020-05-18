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
const ld EPS = 1e-6;


inline ld xabs(ld x) {
	return x < 0 ? -x : x;
}


int main() {
#ifdef DEBUG
	freopen("100523H.in", "r", stdin);
	freopen("100523H.out", "w", stdout);
#endif
	int n = readln();
	ld a = 0.5, b = 0.5;
	ld sa = 0, sb = 0;
	for (int i = 0; i < n; ++i) {
		a *= 0.5;
		b *= 0.5;
		sa += a;
		sb += b;
		char ch;
		scanf("%c", &ch);
		if (ch == 'H') {
			a += 0.5;
		}
		else {
			b += 0.5;
		}
	}

	if (xabs(sa-sb) < EPS) printf("HM");
	else if (sa > sb) printf("H");
	else printf("M");
	return 0;
}