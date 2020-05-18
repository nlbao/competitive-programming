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


ll f(ll x) {
	return x*(x-1)/2;
}


int main() {
#ifdef DEBUG
	freopen("478B.in", "r", stdin);
	freopen("478B.out", "w", stdout);
#endif
	ll n, m;
	cin >> n >> m;
	ll d = n/m, r = n%m;
	ll a = (m-r)*f(d) + r*f(d+1);
	ll b = f(n-m+1);
	cout << a << " " << b;
	return 0;
}