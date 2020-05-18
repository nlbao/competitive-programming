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


// pcount(p, n) = number of factors p of n! (p is prime)
ll pcount(ll p, ll n) {
	if (p > n) return 0;
	return (n/p) + pcount(p, n/p);
}


int main() {
#ifdef DEBUG
	freopen("manasa-and-factorials.in", "r", stdin);
	freopen("manasa-and-factorials.out", "w", stdout);
#endif
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		ll n;
		cin >> n;
		ll l = 1, r = 5LL*n, ans = 0;
		while (l <= r) {
			ll mid = (l+r)>>1;
			if (pcount(5, mid) >= n) {
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		cout << ans << endl;
	}
	return 0;
}