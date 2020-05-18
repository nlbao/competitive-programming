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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 3*int(1e5)+5;

ll a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("461A.in", "r", stdin);
	freopen("461A.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();

	if (n == 1) {
		cout << a[0];
		return 0;
	}

	sort(a, a+n);

	ll ans = 0, c = 2;
	for (int i = 0; i < n; ++i) {
		ans += a[i]*c;
		if (i < n-2) ++c;
	}
	cout << ans;
	return 0;
}