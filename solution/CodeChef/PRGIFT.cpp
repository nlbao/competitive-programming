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

const int MAX_N = 55;

int n, k;
int a[MAX_N];
bool ok[MAX_N];


string solve() {
	fill(ok, false);
	ok[0] = true;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += 1- int(a[i]&1);
		if (sum >= k && ok[sum-k])
			return "YES";
		ok[sum] = true;
	}
	return "NO";
}


int main() {
#ifdef DEBUG
	freopen("PRGIFT.in", "r", stdin);
	freopen("PRGIFT.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest) {
		--nTest;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) read(a[i]);
		printf("%s\n", solve().c_str());
	}
	return 0;
}