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

const int MAX_N = int(1e5)+5;

char s[MAX_N];
int a[MAX_N], sum[MAX_N];
ll c[2][2][2], ans[2];
ll f[MAX_N][2];


int main() {
#ifdef DEBUG
	freopen("451D.in", "r", stdin);
	freopen("451D.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s), m = 0;
	sum[0] = 0;
	for (int i = 0, j = 0 ; i < n; i = j) {
		while (j < n && s[j] == s[i]) ++j;
		a[++m] = j-i;
		sum[m] = sum[m-1] + a[m];
	}

	f[0][0] = f[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i][0] = f[i-1][0] + ll(i/2);
		f[i][1] = f[i-1][1] + ll(i/2 + i%2);
	}

	cout << s << endl;
	for (int i = 1; i <= m; ++i) cout << sum[i] << " ";
	cout << endl;

	fill(ans, 0);
	fill(c, 0);
	for (int i = 1; i <= m; ++i) {
		int k = i%2;
		ll x = sum[i-1]%2;
		ll even = f[a[i]][0], odd = f[a[i]][1];

		cout << i << " " << x << ": " << even << " " << odd << endl;
		ll t[2];
		t[0] = a[i]/2;
		t[1] = a[i]/2 + a[i]%2;
		for (int y = 0; y < 2; ++y)
				for (int z = 0; z < 2; ++z)
					for (int h = 0; h < 2; ++h)
						if ((1-k+x+y+z+h)%2 == 0)
							even += t[y]*c[1-k][z][h];
						else
							odd += t[y]*c[1-k][z][h];
		// if (x == 0) {
			// even += t[0]*(c[0][0] + c[1][1]);
			// odd += t[1]*(c[0][1] + c[1][0]);
		// }
		// else {
			// even += t[0]*(c[0][1] + c[1][0]);
			// odd += t[1]*(c[0][0] + c[1][1]);
		// }

		cout << even << " " << odd << endl;

		ans[0] += even;
		ans[1] += odd;
		c[k][x][0] += a[i]/2;
		c[k][x][1] += a[i]/2 + a[i]%2;
	}
	cout << ans[0] << " " << ans[1];
	return 0;
}