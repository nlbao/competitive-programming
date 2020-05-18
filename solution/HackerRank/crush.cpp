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


const int MAX_N = int(1e7+7);

ll a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("crush.in", "r", stdin);
	freopen("crush.out", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	fill(a, 0);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		ll k = read();
		a[x] += k;
		a[y+1] -= k;
	}

	ll res = 0, value = 0;
	for (int i = 1; i <= n; ++i) {
		value += a[i];
		res = max(res, value);
	}
	cout << res << endl;
	return 0;
}