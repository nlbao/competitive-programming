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

const int MAX_N = 22;

char s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("435B.in", "r", stdin);
	freopen("435B.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s), k = read();
	for (int i = 0; i < n-1 && k; ++i) {
		int p = i;
		for (int j = i+1; j <= i+k; ++j)
			if (s[j] > s[p])
				p = j;
		k -= p-i;
		for (int j = p; j > i; --j)
			swap(s[j], s[j-1]);
	}
	printf("%s\n", s);
	return 0;
}