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

const int MAX_N = 33;

int n, m;
char a[MAX_N], b[MAX_N];


bool solve() {
	--n, --m;
	if (a[0] == '>' && b[0] == 'v') return false;
	if (a[0] == '<' && b[m] == 'v') return false;
	if (a[n] == '>' && b[0] == '^') return false;
	if (a[n] == '<' && b[m] == '^') return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("475B.in", "r", stdin);
	freopen("475B.out", "w", stdout);
#endif
	scanf("%d%d\n", &n, &m);
	scanf("%s\n", a);
	scanf("%s\n", b);
	if (solve()) printf("YES");
	else printf("NO");
	return 0;
}