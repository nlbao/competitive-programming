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

const int MAX_N = int(1e5) + 5;

ll a[MAX_N];


ll gcd(ll a, ll b) {
	if (a > b) return gcd(b, a);
	if (a == 0) return b;
	return gcd(b%a, a);
}


int main() {
#ifdef DEBUG
	freopen("salary-blues.in", "r", stdin);
	freopen("salary-blues.out", "w", stdout);
#endif
	int n = read(), nQ = read();
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	sort(a, a + n);

	ll g = 0;
	for (int i = 0; i < n; ++i)
		g = gcd(g, a[i]-a[0]);

	for (int q_id = 0; q_id < nQ; ++q_id) {
		ll k = read();
		printf("%lld\n", gcd(a[0]+k, g));
	}
	return 0;
}