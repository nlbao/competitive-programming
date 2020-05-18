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


const ll pre[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
const int MAX_P = 1e6;


ll n, MODULE;
int maxLen, nP;
ll p[MAX_P];


int getLen(int n) {
	int c = 0;
	while (n > 0) {
		n /= 10;
		++c;
	}
	if (c == 0) c = 1;
	return c;
}


void findF(int len, int pos, ll value) {
	if (len > maxLen) return;
	if (pos >= 0) p[nP++] = value;
	for (int i = 0; i <= pos; ++i)
		findF(len+1, pos, value*10 + pre[i]);
	if (pos < 9)
		findF(len+1, pos+1, value*10 + pre[pos+1]);
}


ll solve() {
	ll ans = 0;
	if (n == ll(1e11)) {
		ans += n%MODULE;
		--n;
	}
	nP = 0;
	maxLen = getLen(n);
	findF(0, -1, 0);
	while (nP > 0 && p[nP-1] > n) --nP;
	// cout << " " << nP << endl;
	// for (int i = 0; i < nP; ++i)
	// 	cout << "		" << p[i] << endl;

	return ans;
}


int main() {
#ifdef DEBUG
	freopen("ISONUM.in", "r", stdin);
	freopen("ISONUM.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%lld %lld", &n, &MODULE);
		printf("%lld\n", solve());
	}
	return 0;
}