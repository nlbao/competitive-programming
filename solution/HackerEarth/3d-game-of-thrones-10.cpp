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



int main() {
#ifdef DEBUG
	freopen("3d-game-of-thrones-10.in", "r", stdin);
	freopen("3d-game-of-thrones-10.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read(), f = 0;
		for (int i = 0; i < n; ++i) {
			// int x = 0;
			for (int k = 0; k < 3; ++k)
				f ^= read();
			// f ^= x;
		}
		if (f) printf("Stark\n");
		else printf("Lannister\n");
	}
	return 0;
}