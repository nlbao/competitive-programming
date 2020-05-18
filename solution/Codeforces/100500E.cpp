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

const int MAX_N = int(100)+5;


int n, k;
bool win[MAX_N], toWin[MAX_N];
int cWin[MAX_N];


// bool check(int x, int y) {
// 	for (int i = 1; i <= x-k+1; ++i) {
// 		int l = i-1, r = x - (i+k-1);

// 	}
// }


int main() {
#ifdef DEBUG
	freopen("100500E.in", "r", stdin);
	freopen("100500E.out", "w", stdout);
#endif
	int nTest = readln();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; ++i) {
			win[i] = false;
			cWin[i] = 0;
		}
		win[k] = true;
		cWin[k] = 0;
		for (int i = k+1; i <= n; ++i) {
			win[i] = false;
			for (int x = 1; x <= i-k+1; ++x) {
				int l = x-1, r = i - (x+k-1);
				// if ((win[l] && win[r]) || (!win[l] && !win[r])) {
				if (!win[l] && !win[r]) {
					win[i] = true;
					break;
				}
			}
		}
		if (win[n]) printf("Case %d: Winning\n", test_id);
		else printf("Case %d: Losing\n", test_id);
	}
	return 0;
}