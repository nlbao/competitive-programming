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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


int main() {
#ifdef DEBUG
	freopen("427A.in", "r", stdin);
	freopen("427A.out", "w", stdout);
#endif
	int n = read(), a = 0, res = 0;
	for (int i = 0; i < n; ++i) {
		int x = read();
		if (x == -1 && a < 1)
			++res;
		else
			a += x;
	}
	printf("%d\n", res);
	return 0;
}