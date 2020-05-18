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
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1003;
const int MAX_C = 260;
const ll BASE = 10007LL;


char s[MAX_N];
int a[MAX_N];
set<ll> q;


inline ll num(char x) {
	return (ll)x + 1;
}


int main() {
#ifdef DEBUG
	freopen("100534B.in", "r", stdin);
	freopen("100534B.out", "w", stdout);
#endif
	q.clear();

	scanf("%s", &s);
	int n = strlen(s), ans = 0;

	string t = "";
	for (int x = 1; x <= n; ++x)
		for (int y = x+1; y <= n; ++y) {
			a[0] = x, a[1] = y;
			int c = 2;
			ll h = num(s[x-1])*BASE + num(s[y-1]);
			while (true) {
				int k = a[c-2] + a[c-1];
				if (k > n) break;
				a[c++] = k;
				h = h*BASE + num(s[k-1]);
				// if (k > c) break;
			}
			if (q.find(h) == q.end()) {
				++ans;
				q.insert(h);
			}
		}
	printf("%d\n", ans);
	return 0;
}