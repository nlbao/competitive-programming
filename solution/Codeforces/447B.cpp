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

const int MAX_N = 1003;

char s[MAX_N];
int w[33];

int num(char x) {
	return x-int('a');
}


int main() {
#ifdef DEBUG
	freopen("447B.in", "r", stdin);
	freopen("447B.out", "w", stdout);
#endif
	scanf("%s\n", &s);
	int n = strlen(s);
	int k = read(), maxW = 0;
	for (int i = 0; i < 26; ++i) {
		w[i] = read();
		maxW = max(maxW, w[i]);
	}

	int res = 0;
	for (int i = 0; i < n; ++i)
		res += w[num(s[i])]*(i+1);
	for (int i = 0; i < k; ++i)
		res += maxW*(n+1+i);
	printf("%d\n", res);
	return 0;
}