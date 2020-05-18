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


const int MAX_N = int(2e2);
const int oo = int(1e9);


int n, len;
string a[MAX_N], b[MAX_N];
map<string, int> q;


string match(int x, int y) {
	string s = "";
	for (int i = 0; i < len; ++i)
		if (a[x][i] != b[y][i]) s += "1";
		else s += "0";
	return s;
}


bool solve() {
	sort(a, a+n);
	sort(b, b+n);
	for (int i = 1; i < n; ++i)
		if (a[i] == a[i-1] || b[i] == b[i-1])
			return false;
	q.clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			string s = match(i, j);
			map<string, int>::iterator it = q.find(s);
			if (it != q.end()) ++(it->second);
			else q[s] = 1;
		}
	int ans = oo;
	foreach(it, q)
		if (it->second == n) {
			int c = 0;
			for (int i = 0; i < len; ++i)
				if (it->first[i] == '1')
					++c;
			ans = min(ans, c);
		}
	if (ans >= oo) return false;
	printf("%d\n", ans);
	return true;
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-practice.in", "r", stdin);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		scanf("%d %d", &n, &len);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		printf("Case #%d: ", testid);
		if (!solve()) printf("NOT POSSIBLE\n");
	}
	return 0;
}