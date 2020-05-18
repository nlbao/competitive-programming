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

const int MAX_N = 2*int(1e5)+5;

map<ll, ll> c;


int main() {
#ifdef DEBUG
	freopen("100247C.in", "r", stdin);
	freopen("100247C.out", "w", stdout);
#endif
	int n = read();
	ll s, sum = 0, ans = 0;
	cin >> s;
	c[0] = 1;
	for (int i = 0; i < n; ++i) {
		ll x = read();
		sum += x;
		x = sum - s;
		if (c.find(x) != c.end())
			ans += c[x];
		if (c.find(sum) == c.end()) c[sum] = 1;
		else ++c[sum];
	}
	cout << ans;
	return 0;
}