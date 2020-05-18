#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 10;

char s[MAX_N];
int c[33];


int main() {
#ifdef DEBUG
	freopen("counting-good-partitions-of-a-string.in", "r", stdin);
	freopen("counting-good-partitions-of-a-string.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	filla(c, 0);
	for (int i = 0; i < n; ++i)
		++c[s[i]-'a'];
	int ans = 1;
	for (int i = 0; i < 27; ++i)
		if (c[i] > 0 && i != (s[0]-'a'))
			ans = (ans * c[i]) % 1000;
	printf("%d\n", ans);
	return 0;
}