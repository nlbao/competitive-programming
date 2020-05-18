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

const int MAX_N = 33*int(1e3)+4;
const int MAX_A = int(1e6)+6;


int n;
bool isPrime[MAX_A];
bool a[MAX_N];
int f[MAX_N];


void update(int i, int value) {
	if (i > n) return;
	f[i] += value;
	update(i + (i & (-i)), value);
}


int get(int i) {
	if (i < 1) return 0;
	return f[i] + get(i - (i & (-i)));
}



int main() {
#ifdef DEBUG
	freopen("help-the-avengers-6.in", "r", stdin);
	freopen("help-the-avengers-6.out", "w", stdout);
#endif
	filla(isPrime, true);
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i < MAX_A; ++i) if (isPrime[i]) {
		for (ll j = i*i; j < MAX_A; j += i)
			isPrime[j] = false;
	}

	int nTest = read();
	while (nTest--) {
		n = read();
		filla(f, 0);
		for (int i = 1; i <= n; ++i) {
			int x = read();
			a[i] = isPrime[x];
			if (a[i]) update(i, 1);
		}
		int m = readln();
		while (m--) {
			char ch;
			int x, y;
			scanf("%c %d %d\n", &ch, &x, &y);
			if (ch == 'C') {
				if (a[x]) update(x, -1);
				a[x] = isPrime[y];
				if (a[x]) update(x, 1);
			}
			else {
				int ans = get(y) - get(x-1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}