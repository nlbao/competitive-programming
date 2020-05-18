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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e6) + 6;

char s[MAX_N], t[2*MAX_N];
int kmp[MAX_N];


int main() {
#ifdef DEBUG
	freopen("TASHIFT.in", "r", stdin);
	freopen("TASHIFT.out", "w", stdout);
#endif
	int n = readln();
	scanf("%s\n", s);
	scanf("%s\n", t);

	kmp[0] = 0;
	for (int i = 1, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != s[j]) j = kmp[j-1];
		if (s[i] == s[j]) ++j;
		kmp[i] = j;
	}

	for (int i = 0; i < n; ++i)
		t[n+i] = t[i];

	int len = 0, ans = 0, m = n+n-1;
	for (int i = 0, j = 0; i < m; ++i) {
		while (j > 0 && t[i] != s[j]) j = kmp[j-1];
		if (t[i] == s[j]) ++j;
		if (j > len) {
			len = j;
			ans = i - len + 1;
		}
		if (j == n) j = kmp[n-1];
	}
	printf("%d\n", ans);
	return 0;
}