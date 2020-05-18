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

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e3 + 33;


int n, m;
string s;
int a[MAX_N], b[MAX_N];
int d[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("10405.in", "r", stdin);
	freopen("10405.out", "w", stdout);
#endif
	while (getline(cin, s)) {
		n = s.length();
		for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'a';
		getline(cin, s);
		m = s.length();
		for (int i = 1; i <= m; ++i) b[i] = s[i-1]-'a';

		filla(d, 0);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				d[i][j] = max(d[i-1][j], d[i][j-1]);
				if (a[i] == b[j])
					d[i][j] = max(d[i][j], d[i-1][j-1] + 1);
			}
		printf("%d\n", d[n][m]);
	}
	return 0;
}