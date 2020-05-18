#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e5)+7;

char s[MAX_N];
int f[MAX_N];


int check(int n) {
	int k = n>>1;
	fill(f, false);
	for(int i = k, j = n-k; i >= 0 && j < n && s[i] == s[j]; --i, ++j)
		f[i] = true;
	if (f[1]) return 0;
	for (int i = 0, j = n-1; i < j && s[i] == s[j]; ++i, --j)
		if (i+1 == j || f[i+2])
			return i+1;
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("palindrome-index.in", "r", stdin);
	freopen("palindrome-index.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		scanf("%s", s);
		int n = strlen(s), res = check(n);
		if (res == -1) {
			for (int i = 0, j = n-1; i < j; ++i, --j)
				swap(s[i], s[j]);
			res = n-1-check(n);
		}
		printf("%d\n", res);
	}
	return 0;
}