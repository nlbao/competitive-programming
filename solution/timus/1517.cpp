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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2*int(1e5)+5;
const int MAX_LOG = 20;

int n, logN;
char s[MAX_N], t[MAX_N];
int key[MAX_N], cnt[MAX_N], sa[MAX_N], sb[MAX_N];
int lcp[MAX_N], rank[MAX_N];
bool mark[MAX_N];


void build_sa() {
	s[n++] = 1;
	fill(cnt, 0);
	for (int i = 0; i < n; ++i) ++cnt[key[i] = s[i]];
	for (int i = 1; i < MAX_N; ++i) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; --i) sa[--cnt[key[i]]] = i;
	mark[0] = true;
	for (int i = 1; i < n; ++i) mark[i] = (key[sa[i-1]] != key[sa[i]]);

	for (int k = 1; k <= n; k <<= 1) {
		int nKey = 0;
		for (int i = 0; i < n; ++i) {
			if (mark[i]) ++nKey;
			key[sa[i]] = nKey;
			sb[i] = (sa[i] - k + n)%n;
		}
		fill(cnt, 0);
		for (int i = 0; i < n; ++i) ++cnt[key[i]];
		for (int i = 1; i <= nKey; ++i) cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; --i) sa[--cnt[key[sb[i]]]] = sb[i];
		for (int i = 1; i < n; ++i)
			mark[i] = mark[i] || (key[(sa[i-1]+k)%n] != key[(sa[i]+k)%n]);
	}
}


void build_lcp() {
	for (int i = 0; i < n; ++i)
		rank[sa[i]] = i;
	lcp[0] = 1;
	for (int i = 0, q = 0; i < n-1; ++i) {
		int j = sa[rank[i]-1];
		while (s[j+q] == s[i+q]) ++q;
		lcp[rank[i]] = q;
		q = max(q-1, 0);
	}
}


int main() {
#ifdef DEBUG
	freopen("1517.in", "r", stdin);
	freopen("1517.out", "w", stdout);
#endif
	int m = readln();
	scanf("%s\n", s);
	scanf("%s\n", t);
	s[m] = '#';
	for (int i = 0; i < m; ++i)
		s[m+1+i] = t[i];
	n = m+1+m;
	build_sa();
	build_lcp();

	int maxLen = 0, pos = m;
	for (int i = 1; i < n; ++i) {
		int u = sa[i-1], v = sa[i];
		if ((u < m && v >= m) || (u >= m && v < m))
			if (lcp[i] > maxLen) {
				maxLen = lcp[i];
				pos = u < m ? u : v;
			}
	}
	for (int i = 0; i < maxLen; ++i) printf("%c", s[pos+i]);
	return 0;
}