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

const int MAX_N = int(1e5)+5;

int n;
int a[MAX_N], q[MAX_N], tmp[MAX_N];
bool ok[MAX_N];
map<int, ll> cnt;


int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}


inline void push(int x, ll c) {
	if (cnt.find(x) != cnt.end())
		cnt[x] += c;
	else
		cnt[x] = c;
}


int main() {
#ifdef DEBUG
	freopen("475D.in", "r", stdin);
	freopen("475D.out", "w", stdout);
#endif
	n = read();
	int top = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		int x = a[i], lastPos = i;
		while (top > 0 && gcd(x, a[q[top]]) == x)
			--top;
		for (int k = top; k > 0; --k) {
			int pos = q[k];
			push(x, lastPos-pos);
			lastPos = pos;
			int y = gcd(x, a[pos]);
			tmp[k] = pos;
			if (y != x) {
				ok[k] = true;
				x = y;
			}
			else ok[k] = false;
		}
		if (lastPos) push(x, lastPos);

		int m = top;
		top = 0;
		for (int k = 1; k <= m; ++k)
			if (ok[k])
				q[++top] = tmp[k];
		q[++top] = i;
	}

	int nQ = read();
	while (nQ--) {
		int x = read();
		if (cnt.find(x) != cnt.end())
			printf("%lld\n", cnt[x]);
		else printf("0\n");
	}
	return 0;
}