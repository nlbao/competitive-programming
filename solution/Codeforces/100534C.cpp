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



bool check(int s) {
	if (s == 2) return false;
	if (s == 1) return true;
	if (s == 0) return true;
	// check if s = x*(x-1)/2
	for (int x = 2; x <= s; ++x) {
		int t = x*(x-1)/2;
		if (t > s) break;
		if (t == s) return true;
	}
	// other
	int x = 1, t = 2*s;
	while (x*(x+1) <= t && x*(x+3)-2 < t)
		++x;
	if (x*(x+1) > t) return false;
	// if (x*(x+3)/2-s <= 0) cout << "!!!!!!!!!!!!!" << endl;
	if (x*(x+3)/2-s <= 0) return false;
	return true;
}


bool solve(int s) {
	if (s == 2) return false;
	if (s == 1) {
		printf("2 1\n1 2\n");
		return true;
	}
	if (s == 0) {
		printf("1 0\n");
		return true;
	}

	// check if s = x*(x-1)/2
	for (int x = 2; x <= s; ++x) {
		int t = x*(x-1)/2;
		if (t > s) break;
		if (t == s) {
			printf("%d %d\n", x, t);
			for (int i = 1; i <= x; ++i)
				for (int j = i+1; j <= x; ++j)
					printf("%d %d\n", i, j);
			return true;
		}
	}

	// other
	int x = 1, t = 2*s;
	while (x*(x+1) <= t && x*(x+3)-2 < t)
		++x;
	if (x*(x+1) > t) return false;

	int k = x*(x+3)/2 - s;
	if (k == 0) return false;

	int n = x + 1;
	int m = x*(x-1)/2 + k;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= x; ++i)
		for (int j = i+1; j <= x; ++j)
			printf("%d %d\n", i, j);
	for (int i = 1; i <= x && k > 0; ++i, --k)
		printf("%d %d\n", n, i);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("100534B.in", "r", stdin);
	freopen("100534B.out", "w", stdout);
#endif
	// for (int i = 0; i <= 100000; ++i)
	// 	if (!check(i)) cout << "Impossible: " << i << endl;

	int s = read();
	if (!solve(s)) printf("Impossible\n");
	return 0;
}