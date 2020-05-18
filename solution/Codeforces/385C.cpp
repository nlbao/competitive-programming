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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e6)+6;
const int MAX_A = int(1e7)+7;

int c[MAX_A];
bool ok[MAX_A];
ll s[MAX_A];


int main() {
#ifdef DEBUG
	freopen("385C.in", "r", stdin);
	freopen("385C.out", "w", stdout);
#endif
	filla(c, 0);
	int n = read();
	for (int i = 0; i < n; ++i) {
		int x = read();
		++c[x];
	}

	filla(ok, true);
	filla(s, 0);
	for (int i = 2; i < MAX_A; ++i) {
		s[i] = s[i-1];
		if (!ok[i]) continue;
		for (int j = i; j < MAX_A; j += i) {
			ok[j] = false;
			s[i] += ll(c[j]);
		}
	}

	int m = read();
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		r = min(r, int(1e7));
		l = min(l, r+1);
		printf("%lld\n", s[r] - s[l-1]);
	}
	return 0;
}