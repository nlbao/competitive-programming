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

const int MAX_N = int(1e5)+5;

int d[MAX_N];


int main() {
#ifdef DEBUG
	freopen("PRPOTION.in", "r", stdin);
	freopen("PRPOTION.out", "w", stdout);
#endif
	int nTest = read(), R, G, B, M, r, g, b;
	while (nTest--) {
		scanf("%d%d%d%d", &R, &G, &B, &M);
		r = g = b = 0;
		for (int i = 0; i < R; ++i)
			r = max(r, read());
		for (int i = 0; i < G; ++i)
			g = max(g, read());
		for (int i = 0; i < B; ++i)
			b = max(b, read());
		for (int i = 0; i < M; ++i) {
			if (r < g) swap(r, g);
			if (r < b) swap(r, b);
			r /= 2;
		}
		printf("%d\n", max(r, max(g, b)));
	}
	return 0;
}