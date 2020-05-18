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


const int MAX_N = 200005;
const int oo = int(1e9);

double C, F, X;
double time_limit;



double solve() {
	int n = int(X)+4;
	double f = X/(2 + F*n);
	for (int i = n-1; i >= 0; --i) {
		double g = 2 + F*i;
		f = min(X/g, C/g + f);
	}
	return f;
}



int main() {
#ifdef DEBUG
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%lf%lf%lf", &C, &F, &X);

		time_limit = X/2;
		double res = solve();

		printf("Case #%d: %.7lf\n", test_id, res);
	}
	return 0;
}