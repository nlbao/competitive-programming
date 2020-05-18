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

const int MAX_N = 5*int(1e4)+4;

int n;
char s[MAX_N];
int key[MAX_N], cnt[MAX_N], sa[MAX_N], sb[MAX_N], lcp[MAX_N], rank[MAX_N];
bool isDiff[MAX_N];


void buildSuffixArray() {
	s[n++] = 1;
	fill(cnt, 0);
	for (int i = 0; i < n; ++i) ++cnt[key[i] = int(s[i])];
	for (int i = 1; i < MAX_N; ++i) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; --i) sa[--cnt[key[i]]] = i;
	isDiff[0] = false;
	for (int i = 1; i < n; ++i)
		isDiff[i] = key[sa[i]] != key[sa[i-1]];

	for (int k = 1; k <= n; k <<= 1) {
		int nKeys = 0;
		for (int i = 0; i < n; ++i) {
			if (isDiff[i]) ++nKeys;
			key[sa[i]] = nKeys;
			sb[i] = (sa[i] - k + n)%n;
		}
		for (int i = 0; i <= nKeys; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[key[i]];
		for (int i = 1; i <= nKeys; ++i) cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; --i) sa[--cnt[key[sb[i]]]] = sb[i];
		for (int i = 1; i < n; ++i)
			isDiff[i] = isDiff[i] || (key[(sa[i]+k)%n] != key[(sa[i-1]+k)%n]);
	}
}


void buildLCP() {
	for (int i = 0; i < n; ++i) rank[sa[i]] = i;
	lcp[0] = 0;
	for (int i = 0, c = 0; i < n-1; ++i) {
		int j = sa[rank[i]-1];
		while (s[i+c] == s[j+c]) ++c;
		lcp[rank[i]] = c;
		c = max(c-1, 0);
	}
}


int main() {
#ifdef DEBUG
	freopen("SUBST1.in", "r", stdin);
	freopen("SUBST1.out", "w", stdout);
#endif
	int nTest;
	scanf("%d\n", &nTest);
	for (int test_id = 0; test_id < nTest; ++test_id) {
		scanf("%s\n", s);
		n = strlen(s);
		buildSuffixArray();
		buildLCP();
		--n;
		ll res = ll(n)*ll(n+1)/2LL;
		for (int i = 1; i < n+1; ++i)
			res -= lcp[i];
		printf("%d\n", int(res));
	}
	return 0;
}