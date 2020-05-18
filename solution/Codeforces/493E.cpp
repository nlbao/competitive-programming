#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const ll BASE = ll(1e18) + 3;
const ll MODULE = ll(1e9) + 7;


ll mmul(ll a, ll b, ll module) {
	if (a == 1) return b % module;
	if (b == 1) return a % module;
	ll t = mmul(a, b>>1);
	t = (t+t) % module;
	if (b&1) return (t+a) % module;
	return t;
}


// for bitset (modulo 2)
ll gauss(vector< bitset<MAX_N> > &a, int m) {
	int n = a.size();
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		for (int i = row; i < n; ++i)
			if (a[i][col]) {
				swap(a[row], a[i]);
				break;
			}
		if (!a[row][col]) continue;
		for (int i = 0; i < n; ++i)
			if (i != row && a[i][col]) {
				a[i] ^= a[row];
				a[i] = 
			}
		++row;
	}

	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j]) {
				zero = false;
				break;
			}
		if (zero && a[i][m])
			return 0;
	}
	ll rank = 0;
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (a[i][j]) {
			++rank;
			++i;
		}
	if (rank < m) return oo;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("493E.in", "r", stdin);
	freopen("493E.out", "w", stdout);
#endif
	
	
	return 0;
}