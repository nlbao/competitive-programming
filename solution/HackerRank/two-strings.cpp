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

const int MAX_N = int(1e5)+5;

char s[MAX_N];
bool ok[100];


int main() {
#ifdef DEBUG
	freopen("two-strings.in", "r", stdin);
	freopen("two-strings.out", "w", stdout);
#endif
	int nTest = readln();
	while (nTest--) {
		string ans = "NO";
		filla(ok, false);
		scanf("%s\n", s);
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
			ok[s[i] - 'a'] = true;
		scanf("%s\n", &s);
		n = strlen(s);
		for (int i = 0; i < n; ++i)
			if (ok[s[i] - 'a']) {
				ans = "YES";
				break;
			}
		printf("%s\n", ans.c_str());
	}
	return 0;
}