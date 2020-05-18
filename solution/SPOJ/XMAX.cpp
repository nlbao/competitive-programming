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

const int MAX_N = int(1e5)+5;
const int MAX_BIT = 64;

int n;
vector<ll> a;


ll solve(vector<ll> a) {
	int n = (int)a.size();
	for (int row = 0, col = MAX_BIT-1; col >= 0 && row < n; --col) {
		for (int i = row; i < n; ++i)
			if ((a[i]>>col)&1) {
				swap(a[i], a[row]);
				break;
			}
		if (!((a[row]>>col)&1)) continue;
		for (int i = 0; i < n; ++i)
			if (i != row && ((a[i]>>col)&1))
				a[i] ^= a[row];
		++row;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans ^= a[i];
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("XMAX.in", "r", stdin);
	freopen("XMAX.out", "w", stdout);
#endif
	scanf("%d", &n);
	a.clear();
	a.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	printf("%lld\n", solve(a));
	return 0;
}