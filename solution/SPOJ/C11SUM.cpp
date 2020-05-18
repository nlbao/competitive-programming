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

const int MAX_N = int(1e6)+6;
const ll MODULE = ll(1e9)+7;

char s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("C11SUM.in", "r", stdin);
	freopen("C11SUM.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	ll ans = 0, preSum = 0;
	for (int i = 0; i < n; ++i) {
		ll sum, x = s[i]-'0';
		sum = (preSum*10LL + x*ll(i+1))%MODULE;
		ans = (ans + sum)%MODULE;
		preSum = sum;
	}
	printf("%d\n", int(ans));
	return 0;
}