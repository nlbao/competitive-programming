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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


int main() {
#ifdef DEBUG
	freopen("sansa-and-xor.in", "r", stdin);
	freopen("sansa-and-xor.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read(), ans = 0;
		for (int i = 1; i <= n; ++i) {
			int x = read();
			if ((i*(n-i+1))&1)
				ans ^= x;
		}
		printf("%d\n", ans);
	}
	return 0;
}