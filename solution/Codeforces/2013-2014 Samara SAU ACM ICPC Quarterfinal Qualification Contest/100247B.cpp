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

const int MAX_N = int(1e6)+6;
const ll BASE = 10007;

char s[MAX_N];
int a[33];
map<ll, ll> c;


int main() {
#ifdef DEBUG
	freopen("100247B.in", "r", stdin);
	freopen("100247B.out", "w", stdout);
#endif
	int n = readln();
	ll ans = 0;
	for (int id = 0; id < n; ++id) {
		scanf("%s", s);
		int len = strlen(s);
		filla(a, 0);
		int m = 0;
		ll h = 0;
		for (int i = 0; i < len; ++i) {
			int x = s[i] - 'a';
			if (a[x] == 0) a[x] = ++m;
			h = h*BASE + ll(a[x]);
		}
		if (c.find(h) == c.end()) c[h] = 1;
		else {
			ans += c[h];
			++c[h];
		}
	}
	cout << ans;
	return 0;
}