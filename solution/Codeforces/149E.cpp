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

const int MAX_N = int(1e6)+6;
const ll BASE = 10007LL;

char s[MAX_N], t[MAX_N];
ll h[MAX_N], p[MAX_N];
int a[MAX_N], b[MAX_N];


ll getH(int i, int j) {
	if (i == 0) return h[j];
	return h[j] - h[i-1]*p[j-i+1];
}


ll num(char x) {
	return x - 'A'+1;
}


int main() {
#ifdef DEBUG
	freopen("149E.in", "r", stdin);
	freopen("149E.out", "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i) p[i] = p[i-1] * BASE;

	scanf("%s\n", s);
	int n = strlen(s);
	h[0] = num(s[0]);
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1]*BASE + num(s[i]);

	int nQuery, res = 0;
	scanf("%d\n", &nQuery);
	for (int qid = 0; qid < nQuery; ++qid) {
		scanf("%s\n", t);
		int m = strlen(t);
		if (m < 2) continue;

		ll f = 0;
		for (int i = 0; i < m; ++i) a[i] = -1;
		for (int i = 0, j = 0; i < m; ++i) {
			f = f*BASE + num(t[i]);
			j = max(j, i);
			while (j < n && getH(j-i, j) != f) ++j;
			if (j >= n) break;
			a[i] = j;
		}

		f = 0;
		for (int i = 0; i < m; ++i) b[i] = -1;
		for (int i = m-1, j = n-1, len = 1; i >= 0; --i, ++len) {
			f = f + num(t[i])*p[len-1];
			j = min(j, n-len);
			while (j >= 0 && getH(j, j+len-1) != f) --j;
			if (j < 0) break;
			b[i] = j;
		}

		bool ok = (a[m-1] > -1);
		for (int i = 0; i < m-1; ++i) {
			if (ok) break;
			if (a[i] > -1 && b[i+1] > -1)
				ok = ok || (a[i] < b[i+1]);
		}
		if (ok) ++res;
	}
	printf("%d\n", res);
	return 0;
}