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

const int MAX_N = 1003;
const int MAX_M = 103;

int n, m, d;
int a[MAX_N][MAX_M];
vector<pii> ans;


int main() {
#ifdef DEBUG
	freopen("384B.in", "r", stdin);
	freopen("384B.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &a[i][j]);
	}
	ans.clear();
	if (d == 0) {
		for (int i = 0; i < m; ++i)
			for (int j = i+1; j < m; ++j) {
				bool ok = false;
				for (int k = 0; k < n; ++k)
					if (a[k][i] > a[k][j]) {
						swap(a[k][i], a[k][j]);
						ok = true;
					}
				if (ok) ans.push_back(make_pair(i, j));
			}
	}
	else {
		for (int i = m-1; i >= 0; --i)
			for (int j = 0; j < i; ++j) {
				bool ok = false;
				for (int k = 0; k < n; ++k)
					if (a[k][i] > a[k][j]) {
						swap(a[k][i], a[k][j]);
						ok = true;
					}
				if (ok) ans.push_back(make_pair(i, j));
			}
	}

	n = (int)ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", ans[i].first+1, ans[i].second+1);
	return 0;
}