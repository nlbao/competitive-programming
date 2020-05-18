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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e5)+4;


int n;
char s[MAX_N];


int solve() {
	int ans = 0, c = 0;
	for (int i = 0; i < n; ++i)
		if (s[i] == '1') ++c;
		else ans += c;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("100534G.in", "r", stdin);
	freopen("100534G.out", "w", stdout);
#endif
	scanf("%s", &s);
	n = strlen(s);
	int ans = solve();
	for (int i = 0; i < n; ++i)
		if (s[i] == '1') s[i] = '2';
		else s[i] = '1';
	ans = min(ans, solve());
	printf("%d\n", ans);
	return 0;
}