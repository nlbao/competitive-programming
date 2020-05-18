#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); (it) != (X).end(); (it)++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e6)+6;

int n;
int a[MAX_N];
ll f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("484D.in", "r", stdin);
	freopen("484D.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();

	f[0] = 0;
	for (int i = 1, pre = 1; i <= n; ++i) {
		f[i] = f[i-1];
		f[i] = max(f[i], f[pre-1] + 1LL*abs(a[i] - a[pre]));
		if (pre < i)
			f[i] = max(f[i], f[pre] + 1LL*abs(a[i] - a[pre+1]));

		if (a[i] == a[pre]) pre = i;
		else if (a[pre] < a[pre+1] && a[i] >= a[i+1]) pre = i;
		else if (a[pre] > a[pre+1] && a[i] <= a[i+1]) pre = i;
	}
	cout << f[n];
	return 0;
}