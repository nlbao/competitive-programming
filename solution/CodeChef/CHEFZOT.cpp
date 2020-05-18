#include <cstdio>
#include <cmath>
#include <cstdlib>
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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }



int main() {
	freopen("CHEFZOT.in", "r", stdin);
	int n = read(), res = 0, c = 0;
	for (int i = 0; i < n; ++i) {
		int x = read();
		if (x) ++c;
		else c = 0;
		res = max(res, c);
	}
	printf("%d\n", res);
	return 0;
}