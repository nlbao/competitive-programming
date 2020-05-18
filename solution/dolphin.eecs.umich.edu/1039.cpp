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

const int MAX_N = 66;


char s[MAX_N], a[MAX_N];
int n, cnt, maxF;
ll ans;
int c[MAX_N], d[MAX_N];
vector<int> e[MAX_N];


void tryf(int u) {
	if (u > n) return;
	tryf(u+1);
	// if (d[u] <= ans) return;
	if (c[u] < cnt) return;

	for_each(it, e[u]) {
		int v = *it;
		++c[v];
	}
	++ans;
	++cnt;

	cout << "add: " << u << endl;
	a[cnt] = u;
	cout << u << ": ";
	for (int i = 1; i <= cnt; ++i)
		cout << u << " ";
	cout << endl;

	cout << "		tryf: " << u+1 << endl;
	maxF = max(maxF, cnt);
	tryf(u+1);
	--cnt;

	cout << "remove: " << u << endl;

	for_each(it, e[u]) {
		int v = *it;
		--c[v];
	}
}


int main() {
#ifdef DEBUG
	freopen("1039.in", "r", stdin);
	freopen("1039.out", "w", stdout);
#endif
	n = readln();
	filla(d, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%s\n", s);
		for (int j = 0; j < n; ++j)
			if (j != i && s[j] == 'Y') {
				e[i+1].push_back(j+1);
				e[j+1].push_back(i+1);
				++d[i+1], ++d[j+1];
			}
	}

	maxF = 1;
	cnt = 0;
	ans = 0;
	filla(c, 0);
	tryf(1);
	cout << ans;
	return 0;
}