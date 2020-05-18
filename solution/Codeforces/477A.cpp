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

const int MAX_P = int(1e6)+6;
const int MAX_N = int(1e4)+4;

int f[MAX_P], prime[MAX_P];


int main() {
#ifdef DEBUG
	freopen("477.in", "r", stdin);
	freopen("477.out", "w", stdout);
#endif
	int n, k;
	scanf("%d%d", &n, &k);

	int m = 4*n, nPrime = 0;
	filla(f, 0);
	for (int i = 2; i < MAX_P; ++i) {
		if (f[i] == 0) {
			f[i] = i;
			prime[nPrime++] = i;
		}
		int limit = min(f[i], (MAX_P-1)/i);
		for (int k = 0; k < nPrime && prime[k] <= limit; ++k)
			f[i*prime[k]] = prime[k];
	}

	// printf("%d\n", nPrime);

	for (int i = 0; i < m; ++i)
	return 0;
}