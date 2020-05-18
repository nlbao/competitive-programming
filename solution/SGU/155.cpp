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

const int MAX_N = 5*int(1e4) + 4;
const int oo = 1e9;


pair<pii, int> a[MAX_N];
int parent[MAX_N], l[MAX_N], r[MAX_N];
int ansp[MAX_N], ansl[MAX_N], ansr[MAX_N];


int main() {
#ifdef DEBUG
	freopen("155.in", "r", stdin);
	freopen("155.out", "w", stdout);
#endif
	int n = read();
	for (int i = 1; i <= n; ++i) {
		int x = read(), y = read();
		a[i] = make_pair(make_pair(x, y), i);
	}

	sort(a+1, a+1+n);

	int root = 1;
	parent[1] = l[1] = r[1] = 0;
	for (int i = 2; i <= n; ++i) {
		parent[i] = l[i] = r[i] = 0;
		int last = i-1;
		while (last != root && a[last].first.second > a[i].first.second)
			last = parent[last];
		if (a[last].first.second > a[i].first.second) {
			l[i] = root;
			parent[root] = i;
			root = i;
		}
		else if (r[last] == 0) {
			r[last] = i;
			parent[i] = last;
		}
		else {
			l[i] = r[last];
			parent[l[i]] = i;
			r[last] = i;
			parent[i] = last;
		}
	}

	for (int i = 1; i <= n; ++i) {
		int x = a[i].second;
		ansp[x] = parent[i] ? a[parent[i]].second : parent[i];
		ansl[x] = l[i] ? a[l[i]].second : l[i];
		ansr[x] = r[i] ? a[r[i]].second : r[i];
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d %d %d\n", ansp[i], ansl[i], ansr[i]);
	return 0;
}