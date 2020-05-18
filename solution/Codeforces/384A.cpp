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


int main() {
#ifdef DEBUG
	freopen("384A.in", "r", stdin);
	freopen("384A.out", "w", stdout);
#endif
	int n = read();
	if (n == 1) {
		printf("1\nC\n");
		return 0;
	}
	int a = (n+1)/2, b = n-a;
	printf("%d\n", a*a + b*b);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i+j)%2 == 0) printf("C");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}