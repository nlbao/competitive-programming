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

#define filla(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 4*int(1e6)+6;

int n;
char s[MAX_N];
int kmp[MAX_N];


int main() {
#ifdef DEBUG
	freopen("KAN13C.in", "r", stdin);
	freopen("KAN13C.out", "w", stdout);
#endif
	while (1) {
		scanf("%s\n", s);
		n = strlen(s);
		if (strcmp(s, "End") == 0) break;
		kmp[0] = 0;
		for (int i = 1, j = 0; i < n; ++i) {
			while (j > 0 && s[j] != s[i]) j = kmp[j-1];
			if (s[j] == s[i]) ++j;
			kmp[i] = j;
		}
		for (int i = 0; i < n; ++i)
			printf("%d ", kmp[i]);
		printf("\n");
	}
	return 0;
}