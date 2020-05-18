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
	freopen("SNAPE.in", "r", stdin);
	freopen("SNAPE.out", "w", stdout);
#endif
	int nTest = read();
	for (int i = 1; i <= nTest; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%.3lf %.3lf\n",  sqrt(double(abs(x*x-y*y))), sqrt(double(x*x+y*y)));
	}
	return 0;
}