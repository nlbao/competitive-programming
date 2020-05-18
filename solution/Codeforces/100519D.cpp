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

bool check(int a, int b) {
	a = sqr(a), b = sqr(b);
	int t = sqrt(a+b);
	if (t*t == a+b) return true;
	t = sqrt(b-a);
	if (t*t == b-a) return true;
	return false;
}

int main() {
#ifdef DEBUG
	freopen("100519D.in", "r", stdin);
	freopen("100519D.out", "w", stdout);
#endif
	int a, b;
	scanf("%d%d", &a, &b);
	if (check(a, b)) printf("YES");
	else printf("NO");
	return 0;
}