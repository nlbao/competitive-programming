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


const int MAX_N = 5*int(1e3) + 4;
const int MAX_A = MAX_N;


int a[MAX_N], f[MAX_A];
map<int, int> id;


int main() {
#ifdef DEBUG
	freopen("twisty-tuple.in", "r", stdin);
	freopen("twisty-tuple.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) {
		a[i] = read();
		id[a[i]];
	}
	int m = 0;
	foreach(it, id)
		it->second = ++m;
	for (int i = 0; i < n; ++i)
		a[i] = id[a[i]];

	ll ans = 0;
	filla(f, 0);
	for (int j = n-1; j >= 1; --j) {
		for (int i = 0; i < j; ++i) if (a[i] < a[j])
			ans += f[a[i]];
		for (int x = 0; x < MAX_A; ++x)
			if (a[j] < x) ++f[x];
	}
	cout << ans << endl;
	return 0;
}