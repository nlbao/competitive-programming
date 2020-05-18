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

const int MAX_N = int(1e9)+6;
const int MAX_M = 2*MAX_N + 10;

int n;
map<int, int> c;


void update(int x, int y) {
	x += MAX_N;
	y += MAX_N;
	if (c.find(x) == c.end()) c[x] = 1;
	else ++c[x];
	if (c.find(y) == c.end()) c[y] = -1;
	else --c[y];
}


int main() {
#ifdef DEBUG
	freopen("916.in", "r", stdin);
	freopen("916.out", "w", stdout);
#endif
	n = readln();
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		char ch;
		scanf("%d %c\n", &x, &ch);
		if (ch == 'L') {
			update(pos-x, pos);
			pos -= x;
		}
		else {
			update(pos, pos+x);
			pos += x;
		}
	}

	int ans = 0, sum = 0, pre = -1;
	for_each(it, c) {
		int x = it->first;
		if (sum >= 2 && pre > -1)
			ans += x - pre;
		pre = x;
		sum += it->second;
	}
	cout << ans;
	return 0;
}