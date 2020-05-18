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

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 2*int(1e5)+5;


int n;
int a[MAX_N];


int find(int l, int x) {
	int r = n-1, t = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (a[mid] <= x) {
			t = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return t;
}


int main() {
#ifdef DEBUG
	freopen("484B.in", "r", stdin);
	freopen("484B.out", "w", stdout);
#endif
	n = read();
	for (int i = 0; i < n; ++i)
		a[i] = read();
	sort(a, a+n);

	int ans = 0;
	int limit = a[n-1];
	for (int i = 0; i < n-1; ++i) {
		if (i && a[i] == a[i-1]) continue;
		for (int x = 0, y = x; x <= limit; x = y) {
			y += a[i];
			int t = find(i+1, y-1);
			if (t < 0) continue;
			int r = a[t] - x;
			if (0 <= r && r < a[i])
				ans = max(ans, r);
		}
	}

	printf("%d\n", ans);
	return 0;
}