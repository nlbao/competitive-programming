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

const int MAX_N = int(1e5+5);

ll c[MAX_N];


int main() {
#ifdef DEBUG
	freopen("439B.in", "r", stdin);
	freopen("439B.out", "w", stdout);
#endif
	ll n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i)
		c[i] = read();
	sort(c, c+n);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += x*c[i];
		if (x > 1) --x;
	}
	cout << res << endl;
	return 0;
}