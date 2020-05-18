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

const int MAX_N = int(1e6) + 6;

bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("472A.in", "r", stdin);
	freopen("472A.out", "w", stdout);
#endif
	filla(ok, true);
	ok[1] = false;
	for (ll i = 2; i < MAX_N; ++i)
		if (ok[i])
			for (ll j = i*i; j < MAX_N; j += i)
				ok[j] = false;

	int n = read();
	for (int i = 4; i < n; ++i) if (!ok[i]) {
		int j = n-i;
		if (j > 1 && !ok[j]) {
			printf("%d %d\n", i, j);
			break;
		}
	}
	return 0;
}