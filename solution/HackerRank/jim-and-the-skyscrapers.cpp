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

const int MAX_N = 3*int(1e5)+5;

int a[MAX_N], f[MAX_N], q[MAX_N];


int main() {
#ifdef DEBUG
	freopen("jim-and-the-skyscrapers.in", "r", stdin);
	freopen("jim-and-the-skyscrapers.out", "w", stdout);
#endif
	int n = read();
	int l = 1, r = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		while (r >= l && a[i] > a[q[r]]) --r;
		q[++r] = i;
		f[i] = 1;
		if (r > 1 && a[q[r-1]] == a[i])
			f[i] += f[q[r-1]];
		ans += ll(f[i]-1);
	}
	cout << 2LL*ans;

	return 0;
}