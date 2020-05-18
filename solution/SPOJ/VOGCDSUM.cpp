#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5)+5;
const ll MODULE = ll(1e9)+7;

int n;
ll a[MAX_N];
int q[MAX_N], tmp[MAX_N];
bool ok[MAX_N];


ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}


int main() {
#ifdef DEBUG
	freopen("VOGCDSUM.in", "r", stdin);
	freopen("VOGCDSUM.out", "w", stdout);
#endif
	n = read();
	int top = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		ll x = a[i], lastPos = i;
		while (top > 0 && gcd(x, a[q[top]]) == x)
			--top;
		for (int k = top; k > 0; --k) {
			int pos = q[k];
			ans = (ans + (x*(lastPos-pos))%MODULE)%MODULE;
			tmp[k] = lastPos = pos;
			ll y = gcd(x, a[pos]);
			if (y != x) {
				ok[k] = true;
				x = y;
			}
			else ok[k] = false;
		}
		if (lastPos)
			ans = (ans + (x*lastPos)%MODULE)%MODULE;

		int m = top;
		top = 0;
		for (int k = 1; k <= m; ++k)
			if (ok[k])
				q[++top] = tmp[k];
		q[++top] = i;
	}

	printf("%lld\n", ans);
	return 0;
}