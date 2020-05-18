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


const int MAX_N = 55;


int m, n;
char a[MAX_N][MAX_N];


bool check(int x, int y) {
	vector<char> v;
	v.push_back(a[x][y]);
	v.push_back(a[x+1][y]);
	v.push_back(a[x][y+1]);
	v.push_back(a[x+1][y+1]);
	sort(v.begin(), v.end());
	return v[0] == 'a' && v[1] == 'c' && v[2] == 'e' && v[3] == 'f';
}


int main() {
#ifdef DEBUG
	freopen("549A.in", "r", stdin);
	freopen("549A.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		scanf("%s", a[i]);
	int ans = 0;
	for (int i = 0; i < m-1; ++i)
		for (int j = 0; j < n-1; ++j)
			if (check(i, j))
				++ans;
	printf("%d\n", ans);
	return 0;
}