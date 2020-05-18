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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e5) + 55;
const ll MODULE = ll(1e9)+7;


char s[MAX_N];
string a[MAX_N];
int nexts[10][MAX_N];
vector<int> last[10];
bool ok[10];
ll value[MAX_N], len[MAX_N];


ll mpow(ll a, ll n) {
	if (n < 1) return 1;
	if (n == 1) return a%MODULE;
	ll t = mpow(a, n>>1);
	t = (t*t)%MODULE;
	if (n&1LL) return (t*a)%MODULE;
	return t;
}


int main() {
#ifdef DEBUG
	freopen("464C.in", "r", stdin);
	freopen("464C.out", "w", stdout);
#endif
	scanf("%s\n", s);
	a[0] = string(s);
	len[0] = strlen(s);
	for (int x = 0; x < 10; ++x) {
		last[x].clear();
		last[x].push_back(0);
		nexts[x][0] = -1;
	}

	int n = readln();
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d%s\n", &x, s);
		a[i] = string(s+2, s + strlen(s));
		len[i] = a[i].length();
		for (int k = 0, sz = (int)last[x].size(); k < sz; ++k) {
			int u = last[x][k];
			nexts[x][u] = i;
		}
		last[x].clear();
		filla(ok, true);
		for (int k = 0; k < len[i]; ++k) {
			x = a[i][k] - '0';
			if (ok[x]) {
				last[x].push_back(i);
				ok[x] = false;
			}
		}
		for (x = 0; x < 10; ++x) nexts[x][i] = -1;
	}

	// (a^b) mod m = (a^(b mod phi(m)) mod m
	// (if and if only a and m are coprime)
	ll phi_MODULE = MODULE-1;

	for (int u = n; u >= 0; --u) {
		value[u] = 0;
		ll new_len = 0;
		for (int k = 0; k < len[u]; ++k) {
			ll x = a[u][k] - '0';
			int v = nexts[x][u];
			if (v == -1) {
				value[u] = (value[u] * 10LL + x)%MODULE;
				new_len = (new_len+1)%phi_MODULE;
			}
			else {
				value[u] = ((value[u] * mpow(10, len[v]))%MODULE + value[v])%MODULE;
				new_len = (new_len + len[v])%phi_MODULE;
			}
		}
		len[u] = new_len;
	}
	printf("%lld\n", value[0]);
	return 0;
}