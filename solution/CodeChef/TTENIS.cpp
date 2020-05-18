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


const int MAX_N = 111;


char s[MAX_N];


bool solve() {
	int n = strlen(s), a = 0, b = 0;
	bool pass11 = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') b += 1;
		else a += 1;
		if (max(a, b) >= 11) pass11 = true;
		if (pass11) {
			if (a-1 > b) return true;
			else if (b-1 > a) return false;
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("TTENIS.in", "r", stdin);
	freopen("TTENIS.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);
		if (solve()) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}