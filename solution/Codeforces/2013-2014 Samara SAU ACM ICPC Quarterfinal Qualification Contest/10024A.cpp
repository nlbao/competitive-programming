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


bool cmp(const pair<pii, int> &a, const pair<pii, int> &b) {
	if (a.first.first > b.first.second && a.first.second > b.first.first) return false;
	if (a.first.second > b.first.second) return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("100247A.in", "r", stdin);
	freopen("100247A.out", "w", stdout);
#endif
	int n = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			b[j] = read();
		sort(b, b+3);
		a[i-1] = make_pair(make_pair(b[0], b[1]), i);
	}

	sort(a, a+n);

	int ans = 0;
	filla(ok, false);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < i && cmp(a[i], a[j]) == false) ++j;
		
	}
	return 0;
}