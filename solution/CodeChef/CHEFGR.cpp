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


int main() {
#ifdef DEBUG
	freopen("CHEFGR.in", "r", stdin);
	freopen("CHEFGR.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		int n = read(), m = read(), s = 0;
		for (int i = 0; i < n; ++i) {
			int x = read();
			s += x;
		}
		m += s;
		if (m%n != 0) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
	return 0;
}