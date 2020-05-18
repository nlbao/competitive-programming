#include <cstdio>
#include <cmath>
#include <cstdlib>
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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }


int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}


struct Frac {
	ll a, b;
	Frac() {
		a = 0;	b = 1;
	}
	Frac(ll aa, ll bb) {
		int d = gcd(aa, bb);
		a = aa/d;
		b = bb/d;
	}
	Frac operator + (const Frac &other) {
		return Frac(a*other.b + b*other.a, b*other.b);
	}
	Frac operator - (const Frac &other) {
		return Frac(a*other.b - b*other.a, b*other.b);
	}
	Frac operator * (const Frac &other) {
		return Frac(a*other.a, b*other.b);
	}
};


Frac f(ll n) {
	return Frac(n/2, n);
}



int main() {
	freopen("GUESS.in", "r", stdin);
	int nTest = read();
	for (int test_id = 0; test_id < nTest; ++test_id) {
		int n, m;
		scanf("%d%d", &n, &m);
		Frac one(1, 1);
		Frac fn = f(n), fm = f(m);
		Frac res = fn*(one-fm) + fm*(one-fn);
		printf("%lld/%lld\n", res.a, res.b);
	}

	return 0;
}