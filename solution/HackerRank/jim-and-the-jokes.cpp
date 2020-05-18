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

const int MAX_N = 111;

map<int, int> c;


int to10(int x, int base) {
	int p = 1, ans = 0;
	while (x > 0) {
		int r = x%10;
		if (r >= base) return -1;
		ans += p * r;
		p *= base;
		x /= 10;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("jim-and-the-jokes.in", "r", stdin);
	freopen("jim-and-the-jokes.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) {
		int m, d;
		scanf("%d%d", &m, &d);
		int p = to10(d, m);
		if (p < 0) continue;
		if (c.find(p) == c.end()) c[p] = 1;
		else ++c[p];
	}

	ll ans = 0;
	for(map<int, int>::iterator it = c.begin(); it != c.end(); ++it) {
		ll x = it->second;
		ans += x*(x-1)/2LL;
	}
	cout << ans;
	return 0;
}