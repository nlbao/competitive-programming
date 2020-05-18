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


const int MAX_N = 111;


bool mess[MAX_N][MAX_N];
char s[MAX_N];


vector<int> solve(vector<pii> a) {
	vector<int> ans;
	int n = a.size();
	int id0 = -1;
	for (int i = 0; i < n; ++i)
		if (a[i].second == 0) {
			id0 = i;
			break;
		}
	if (id0 == -1)
		return ans;
	ans.push_back(a[id0].first);
	vector<pii> b;
	for (int i = 0; i < n; ++i)
		if (i != id0) {
			int d = mess[a[id0].first][a[i].first];
			b.push_back(make_pair(a[i].first, a[i].second-d));
		}
	vector<int> tmp = solve(b);
	foreach(it, tmp)
		ans.push_back(*it);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("549B.in", "r", stdin);
	freopen("549B.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		for (int j = 0; j < n; ++j)
			mess[i][j] = (s[j] == '1');
	}

	vector<pii> a;
	for (int i = 0; i < n; ++i)
		a.push_back(make_pair(i, read()));
	vector<int> ans = solve(a);
	n = ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d\n", ans[i]+1);
	return 0;
}