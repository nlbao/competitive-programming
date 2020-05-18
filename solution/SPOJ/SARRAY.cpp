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
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = int (1e5)+4;

int n;
char s[MAX_N];
int key[MAX_N], cnt[MAX_N];
int sa[MAX_N], sb[MAX_N];
bool isDiff[MAX_N];


void suffixArray() {
	s[n++] = 1;
	fill(cnt, 0);
	for (int i = 0; i < n; ++i) ++cnt[key[i] = int(s[i])];
	for (int i = 1; i < MAX_N; ++i) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; --i) sa[--cnt[key[i]]] = i;
	isDiff[0] = false;
	for (int i = 1; i < n; ++i)
		isDiff[i] = key[sa[i]] != key[sa[i-1]];

	// length = 2^k
	for (int k = 1; k <= n; k <<= 1) {
		int nKeys = 0;
		for (int i = 0; i < n; ++i) {
			if (isDiff[i]) ++nKeys;
			key[sa[i]] = nKeys;
			sb[i] = (sa[i] - k + n)%n;
		}
		// counting sort
		for (int i = 0; i <= nKeys; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[key[i]];
		for (int i = 1; i <= nKeys; ++i) cnt[i] += cnt[i-1];
		for (int i = n-1; i >= 0; --i)
			sa[--cnt[key[sb[i]]]] = sb[i];
		for (int i = 1; i < n; ++i)
			isDiff[i] = isDiff[i] || (key[(sa[i]+k)%n] != key[(sa[i-1]+k)%n]);
	}
}


int main() {
#ifdef DEBUG
	freopen("SARRAY.in", "r", stdin);
	freopen("SARRAY.out", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	suffixArray();
	for (int i = 1; i < n; ++i)
		printf("%d\n", sa[i]);
	return 0;
}