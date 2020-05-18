#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int(1e6) + 6;
const ll BASE = 10007LL;

int n, m;
char s[MAX_N], t[MAX_N];
ll h[MAX_N], g[MAX_N], p[MAX_N];
vector<int> ans;

ll num(char x) {
	return x - 'a'+1;
}


int main() {
#ifdef DEBUG
	freopen("39J.in", "r", stdin);
	freopen("39J.out", "w", stdout);
#endif
	scanf("%s\n", s);
	scanf("%s", t);
	n = strlen(s);
	m = n-1;

	ll f = 0;
	p[0] = 1;
	h[0] = g[n] = 0;
	for (int i = 0; i < n; ++i) {
		if (i) {
			p[i] = p[i-1] * BASE;
			h[i] = h[i-1] * BASE + num(s[i]);
		}
		else h[0] = num(s[0]);
		if (i < n-1) f = f*BASE + num(t[i]);
	}
	ll c = 1;
	for (int i = n-1; i >= 0; --i) {
		g[i] = g[i+1] + c*num(s[i]);
		c *= BASE;
	}

	for (int i = 0; i < n; ++i) {
		ll tmp = 0;
		if (i > 0) tmp = h[i-1];
		if (i < n-1) tmp = tmp*p[n-1-i] + g[i+1];
		if (tmp == f)
			ans.push_back(i+1);
	}

	n = ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}