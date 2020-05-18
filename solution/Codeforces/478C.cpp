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
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


int main() {
#ifdef DEBUG
	freopen("478C.in", "r", stdin);
	freopen("478C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	ll a[3], s = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a+3);
	cout << min(s/3, a[0]+a[1]);
	return 0;
}