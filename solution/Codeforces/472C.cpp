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

const int MAX_N = int(1e5) + 5;

int n;
string f[MAX_N], s[MAX_N], h[MAX_N];
int p[MAX_N];


bool solve() {
	string h = f[p[1]];
	for (int i = 2; i <= n; ++i) {
		int x = p[i];
		if (f[x] > h) h = f[x];
		else if (s[x] > h) h = s[x];
		else return false;
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("472C.in", "r", stdin);
	freopen("472C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> f[i] >> s[i];
		if (f[i] > s[i]) swap(f[i], s[i]);
	}
	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	if (solve()) cout << "YES";
	else cout << "NO";
	return 0;
}