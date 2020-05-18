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

const int MAX_N = 88;
const int MAX_L = MAX_N * 111;
const ll MODULE = 700000001;


int n, rockPos;
int a[MAX_N], s[MAX_N];
ll g[MAX_N], f[2][MAX_L][MAX_N];


int main() {
#ifdef DEBUG
	freopen("610.in", "r", stdin);
	freopen("610.out", "w", stdout);
#endif
	scanf("%d%d", &n, &rockPos);
	int sum = 0;
	s[0] = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		sum += a[i];
		s[i] = s[i-1] + a[i];
	}


	int turn = 0;
	for (int l = 0; l <= sum; ++l)
		for (int x = 0; x <= n; ++x)
			f[0][l][x] = 0;
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int pre = turn;
		turn = 1-turn;
		for (int l = 0; l <= sum; ++l) {
			for (ll x = 0; x <= n; ++x) {
				f[turn][l][x] = 0;
				if (l > s[i] || x > i) continue;
				f[turn][l][x] = f[pre][l][x];
				if (l >= a[i] && x > 0)
					f[turn][l][x] = (f[turn][l][x] + (f[pre][l-a[i]][x-1] * x)%MODULE)%MODULE;
			}
		}
	}

	ll ans = 1, d = 0;
	g[0] = g[1] = 1;
	for (ll i = 2; i <= n; ++i)
		g[i] = ans = (ans*i)%MODULE;
	for (ll x = 1; x <= n; ++x)
		d = (d + (f[turn][rockPos][x] * g[n-x])%MODULE)%MODULE;
	ans = (ans - d)%MODULE;
	while (ans < 0) ans += MODULE;
	cout << ans%MODULE;
	return 0;
}