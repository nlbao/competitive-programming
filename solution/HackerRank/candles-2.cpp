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

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 5 * int(1e4) + 4;
const int MAX_H = 5 * int(1e4) + 4;
const int MAX_MASK = (1<<7) + 4;
const int MODULE = int(1e9)+7;


int maxH, nMask;
int f[MAX_H][MAX_MASK];
int h[MAX_N], c[MAX_N], cnt[MAX_MASK];


void update(int i, int mask, int value) {
	if (i > maxH) return;
	f[i][mask] = (f[i][mask] + value)%MODULE;
	update(i + (i & (-i)), mask, value);
}


void get(int i) {
	if (i < 1) return;
	for (int x = 0; x < nMask; ++x)
		cnt[x] = (cnt[x] + f[i][x])%MODULE;
	get(i - (i & (-i)));
}


int main() {
#ifdef DEBUG
	freopen("candles-2.in", "r", stdin);
	freopen("candles-2.out", "w", stdout);
#endif
	int n = read(), K = read();
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &h[i], &c[i]);
		maxH = max(maxH, h[i]);
		--c[i];
	}

	nMask = 1<<K;
	filla(f, 0);
	for (int i = 0; i < n; ++i) {
		filla(cnt, 0);
		get(h[i]-1);
		for (int k = 0; k < nMask; ++k)
			if (cnt[k] > 0)
				update(h[i], k | (1<<c[i]), cnt[k]);
		update(h[i], 1<<c[i], 1);
	}
	filla(cnt, 0);
	get(maxH);
	cout << cnt[nMask-1];
	return 0;
}