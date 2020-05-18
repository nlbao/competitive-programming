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

const int MAX_N = 5*int(1e5)+5;

int a[MAX_N];
ll s[MAX_N];
map<ll, int> q;


int main() {
#ifdef DEBUG
	freopen("466C.in", "r", stdin);
	freopen("466C.out", "w", stdout);
#endif
	int n = read();
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		s[i] = s[i-1] + ll(a[i]);
	}

	ll ans = 0, g = a[n];
	q[g] = 1;
	for (int i = n-2; i >= 1; --i) {
		if (s[i]*2 == s[n]-s[i]) {
			if (q.find(s[i]) != q.end())
				ans += ll(q[s[i]]);
		}
		g += a[i+1];
		if (q.find(g) == q.end()) q[g] = 1;
		else ++q[g];
	}
	cout << ans;
	return 0;
}