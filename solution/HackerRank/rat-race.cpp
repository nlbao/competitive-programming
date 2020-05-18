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


const int MAX_N = int(1e3) + 3;


int d[MAX_N], s[MAX_N];
vector<int> ans;


int main() {
#ifdef DEBUG
	freopen("rat-race.in", "r", stdin);
	freopen("rat-race.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) s[i] = read();
	for (int i = 0; i < n; ++i) d[i] = read();
	ans.clear();
	ans.push_back(0);
	for (int i = 1; i < n; ++i) {
		int x = ans[0];
		int a = d[i] * s[x], b = d[x] * s[i];
		if (a < b) ans.clear();
		if (a <= b) ans.push_back(i);
	}
	foreach(it, ans) printf("%d\n", (*it)+1);
	return 0;
}