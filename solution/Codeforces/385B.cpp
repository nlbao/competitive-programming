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

const int MAX_N = 5555;
const char BEAR[5] = "bear";

int n;
char s[MAX_N];


bool isBear(int i) {
	if (i < 3) return true;
	for (int d = 0; d < 4; ++d)
		if (s[i-d] != BEAR[3-d])
			return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("385B.in", "r", stdin);
	freopen("385B.out", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	int ans = 0, last = -1;
	for (int i = 0; i < n; ++i) {
		if (isBear(i)) last = i-3;
		if (last >= 0) ans += last + 1;
	}
	printf("%d\n", ans);
	return 0;
}