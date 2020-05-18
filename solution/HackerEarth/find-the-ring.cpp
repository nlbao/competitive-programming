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

int solve(int id, int n) {
	if (n == 0) return id;
	if (n%2 == 1) {
		if (id == 1) return 0;
		return 1;
	}
	else {
		if (id == 1) return 1;
		return 0;
	}
}


int main() {
#ifdef DEBUG
	freopen("find-the-ring.in", "r", stdin);
	freopen("find-the-ring.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int id, n;
		scanf("%d%d", &id, &n);
		printf("%d\n", solve(id, n));
	}
	return 0;
}