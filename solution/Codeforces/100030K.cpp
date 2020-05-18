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

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 1111;

char s[MAX_N];
// int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100030K.in", "r", stdin);
	freopen("100030K.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	// a[0] = false;
	// for (int i = 1; i < n; ++i)
	// 	a[i] = a[i-1] || (s[i-1] == '1' && s[i] == '3');
	// b[n-1] = false;
	// for (int i = n-2; i >= 0; --i)
	// 	b[i] = b[i+1] || (s[i] == '1' && s[i+1] == '3');

	int ans = n;
	// for (int i = 0; i < n; ++i)
	// 	for (int j = i; j < n; ++j) {
	// 		if (i > 0 && a[i-1]) continue;
	// 		if (j < n-1 && b[j+1]) continue;
	// 		if (i > 0 && j < n-1 && s[i-1] == '1' && s[j+1] == '3') continue;
	// 		// cout << "		" << i << " " << j << endl;
	// 		ans = min(ans, j-i+1);
	// 	}
	for (int i = 0; i < n; ++i) if (s[i] == '1') {
		int c = 0;
		for (int k = i+1; k < n; ++k)
			c += (s[k] == '3');
		ans = min(ans, c);
		break;
	}
	for (int i = n-1; i >= 0; --i) if (s[i] == '3') {
		int c = 0;
		for (int k = i-1; k >= 0; --k)
			c += (s[k] == '1');
		ans = min(ans, c);
		break;
	}
	printf("%d\n", ans);
	return 0;
}