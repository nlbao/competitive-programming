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

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 100;
const ll MAX_G = ll(1e12);

ll c[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("BICO.in", "r", stdin);
	freopen("BICO.out", "w", stdout);
#endif
	for (int i = 0; i < MAX_N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			if (c[i-1][j] == -1 || c[i-1][j-1] == -1)
				c[i][j] = -1;
			else {
				c[i][j] = c[i-1][j] + c[i-1][j-1];
				if (c[i][j] > MAX_G)
					c[i][j] = -1;
			}
	}

	int nTest = read();
	for (int test_id = 1; test_id <= nTest; ++test_id) {
		int row, col;
		ll g;
		cin >> row >> col >> g;

		vector<ll> res;
		ll maxCoin = g;
		while(col >= 0 && g > 0) {
			for (int i = MAX_N-1; i >= col; --i)
				if (c[i][col] > 0 && c[i][col] <= maxCoin) {
					ll x = c[i][col];
					res.push_back(x);
					g -= x;
					maxCoin = min(g, x);
					break;
				}
			--col;
		}

		int n = res.size();
		cout << n << '\n';
		for (int i = 0; i < n; ++i)
			cout << res[i] << " ";
		cout << '\n';
	}
	return 0;
}