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


bool solve(int x, int y) {
	if (x == 0 && y == 0) return true;
	if (x == 1 && y == 0) return true;
	if (x > 0 && x%2 == 1) {
		if (-x+1 <= y && y <= x+1) return true;
		if (y < 0 && (y+x)%2 != 0) return true;
		if (y > 0 && (y-x)%2 != 0 && abs((y-x)/2) > 0) return true;
	}
	if (x <= 0 && x%2 == 0) {
		if (x <= y && y <= -x) return true;
		if (y < 0 && (y-x)%2 == 0 && abs((y-x)/2) > 0) return true;
		if (y > 0 && (y+x)%2 == 0 && abs((y+x)/2) > 0) return true;
	}
	if (y%2 == 0) {
		if (y > 0) {
			if (-y <= x && x <= y-1) return true;
			if (x < 0 && (x+y)%2 == 0 && abs((x+y)/2) > 0) return true;
			if (x > 0 && (x-y)%2 != 0) return true;
		}
		else {
			if (y <= x && x <= -y+1) return true;
			if (x < 0 && (x-y)%2 == 0 && abs((x-y)/2) > 0) return true;
			if (x > 0 && (x+y)%2 != 0 && abs((x+y)/2) > 1) return true;
		}
	}
	return false;
}


int main() {
#ifdef DEBUG
	freopen("CRAWA.in", "r", stdin);
	freopen("CRAWA.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest) {
		--nTest;
		int x, y;
		scanf("%d%d", &x, &y);
		if (solve(x, y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}