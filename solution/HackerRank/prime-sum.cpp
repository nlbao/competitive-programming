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
#include <time.h>

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


const ll nWitness = 4;
const ll witness[nWitness] = {2, 13, 23, 1662803};


ll mMultiply(ll a, ll b, ll module) {
	if (a == 0 || b == 0)
		return 0;
	a %= module;
	ll result = 0;
	while (b) {
		if (b&1)
			result = (result+a)%module;
		b >>= 1;
		a = (a<<1)%module;
	}
	return result;
}


ll mPow(ll a, ll n, ll module) {
	if (n < 1) return 1;
	if (n == 1) return a%module;
	ll result = mPow(a, n>>1, module);
	result = mMultiply(result, result, module);
	if (n&1) result = mMultiply(result, a, module);
	return result;
}


bool primalityMillerRabinTest(ll n) {
	ll d = n-1, s = 0;
	while ((d&1) == 0) {
		++s;
		d >>= 1;
	}
	for (int k = 0; k < nWitness; ++k) {
		ll a = witness[k];
		ll b = mPow(a, d, n);
		if (b == 1 || b == n-1) continue;
		bool isPrime = false;
		for (int i = 0; i < s-1; ++i) {
			b = mMultiply(b, b, n);
			if (b == n-1) {
				isPrime = true;
				break;
			}
		}
		if (!isPrime) return false;
	}
	return true;
}


bool isPrime(ll n) {
	if (n == 2) return true;
	if (n < 2 || (n&1) == 0) return false;
	for (int i = 0; i < nWitness; ++i)
		if (n == witness[i]) return true;
		else if (n%witness[i] == 0) return false;
	return primalityMillerRabinTest(n);
}


bool check(ll n, ll k) {
	if (n < 2*k)
		return false;
	if (k == 1)
		return isPrime(n);
	if (k == 2)
		return n%2 == 0 || isPrime(n-2);
	return true;
}


int main() {
#ifdef DEBUG
	freopen("prime-sum.in", "r", stdin);
	freopen("prime-sum.out", "w", stdout);
#endif
	// solve
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		ll n, k;
		scanf("%lld%lld", &n, &k);
		if (check(n, k))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}