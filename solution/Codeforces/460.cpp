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
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+5;


int n, m, w;
int a[MAX_N], b[MAX_N], d[MAX_N];


bool check(int value) {
	for (int i = 0; i < n; ++i) {
		b[i] = (a[i] >= value) ? 0 : value - a[i];
		d[i] = 0;
	}

	int sum = 0, c = 0;
	for (int i = 0; i < n; ++i) {
		b[i] = b[i] - sum;
		if (b[i] > 0) {
			if (m-c < b[i]) return false;
			sum += b[i];
			c += b[i];
			d[min(i+w-1, n)] = b[i];
		}
		sum -= d[i];
	}

	return true;
}


int main() {
#ifdef DEBUG
	freopen("460.in", "r", stdin);
	freopen("460.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &w);
	int maxA = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = read();
		maxA = max(maxA, a[i]);
	}

	int ans = 0;
	int l = 0, r = maxA + m;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}