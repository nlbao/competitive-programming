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

const int MAX_N = 3*int(1e4)+4;

int s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("506.in", "r", stdin);
	freopen("506.out", "w", stdout);
#endif
	int n = read();
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int x = read();
		s[i] = s[i-1] + int(x == 1);
	}

	int ans = s[n];
	for (int i = 1; i <= n; ++i)
		ans = min(ans, (i-s[i]) + (s[n] - s[i]));
	printf("%d\n", ans);
	return 0;
}