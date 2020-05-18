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


const int MAX_N = int(1e5) + 100;
const ll oo = ll(1e18);

int q[MAX_N];
int a[MAX_N];
ll f[MAX_N];
multiset<ll> heap;


int main() {
#ifdef DEBUG
	// freopen("CUTSEQS.in", "r", stdin);
	freopen("test.in", "r", stdin);
	freopen("CUTSEQS.out", "w", stdout);
#endif
	int n = read();
	ll limit;
	scanf("%lld", &limit);
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	ll sum = 0;
	int l = 0, r = -1, pos = 1;
	heap.clear();
	for (int i = 1; i <= n; ++i) {
		if (a[i] > limit) {
			f[n] = oo;
			break;
		}

		sum += a[i];
		while (sum > limit)
			sum -= a[pos++];

		while (l <= r && a[q[r]] <= a[i]) {
			if (l < r)
				heap.erase(heap.find(f[q[r-1]] + a[q[r]]));
			--r;
		}

		q[++r] = i;
		if (l < r)
			heap.insert(f[q[r-1]] + a[q[r]]);

		while (l <= r && q[l] < pos) {
			if (l < r)
				heap.erase(heap.find(f[q[l]] + a[q[l+1]]));
			++l;
		}

		f[i] = f[pos-1] + a[q[l]];
		if (l < r && !heap.empty())
			f[i] = min(f[i], *heap.begin());
	}

	if (f[n] >= oo)
		f[n] = -1;
	printf("%lld\n", f[n]);
	return 0;
}