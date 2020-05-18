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

const int MAX_N = int(1e5)+5;
const ll MODULE = ll(1e9)+9;

int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("FATCHEF.in", "r", stdin);
	freopen("FATCHEF.out", "w", stdout);
#endif
	int nTest = readln();
	while (nTest--) {
		int n, m;
		scanf("%d%d\n", &n, &m);
		for (int i = 1; i <= n; ++i)
			a[i] = -1;
		for (int i = 0; i < m; ++i) {
			char ch;
			int x;
			scanf("%c %d\n", &ch, &x);
			a[x] = ch-'a';
		}

		ll ans = 1;
		int start = 1, end = n;
		while (start <= n && a[start] == -1) ++start;
		while (end > 0 && a[end] == -1) --end;
		for (int i = start, j = i; i <= end; i = j) {
			int pre = a[i];
			while (i <= end && a[i] != -1) {
				pre = a[i];
				++i;
			}
			if (i > end) break;
			j = i;
			while (j <= end && a[j] == -1) ++j;
			if (a[j] != pre)
				ans = (ans * ll(j-i+1))%MODULE;
		}
		printf("%lld\n", ans);
	}
	return 0;
}