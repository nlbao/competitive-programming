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


int solve(ll n, ll k) {
	ll p = n*(n-4*k);
	if (p <= 0) return n-1;
	ll a = (ll)ceil((n*1.0 + sqrt(p))/2.0);
	a = min(a, n);
	a = max(a, 1LL);
	ll b = (ll)floor((n*1.0 - sqrt(p))/2.0);
	b = max(b, 0LL);
	b = min(b, n-1);
	// cout << a << " " << b << endl;
	return (n-1-a+1) + b;
}


int main() {
#ifdef DEBUG
	freopen("sherlock-and-counting.in", "r", stdin);
	freopen("sherlock-and-counting.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		ll n = read(), k = read();
		printf("%d\n", solve(n, k));
	}
	return 0;
}