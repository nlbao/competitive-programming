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


ll f(ll n, ll k) {
	if (k < 2) return 0;
	ll d = k/2;
	ll t = max(1LL, k-n);
	if (k&1) return 2LL*(d-t)+2;
	else return 2LL*(d-t)+1;
}


int main() {
#ifdef DEBUG
	freopen("RRSUM.in", "r", stdin);
	freopen("RRSUM.out", "w", stdout);
#endif
	ll n = read();
	int m = read();
	for (int i = 0; i < m; ++i) {
		ll q;
		scanf("%lld", &q);
		q -= n;
		printf("%lld\n", f(n, q));
	}
	return 0;
}