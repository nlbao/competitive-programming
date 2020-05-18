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

const int MAX_N = 111;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("385A.in", "r", stdin);
	freopen("385A.out", "w", stdout);
#endif
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	int ans = 0;
	for (int i = 1; i < n; ++i)
		ans = max(ans, a[i] - a[i+1] - c);
	printf("%d\n", ans);
	return 0;
}