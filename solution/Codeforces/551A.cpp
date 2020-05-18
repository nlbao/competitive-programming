#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2022;


int n;
pii a[MAX_N];
int ans[MAX_N];


int main() {
#ifdef DEBUG
	freopen("551A.in", "r", stdin);
	freopen("551A.out", "w", stdout);
#endif
	int n = read();
	for (int i = 0; i < n; ++i)
		a[i] = make_pair(-read(), i);
	sort(a, a+n);

	int c = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || a[i].first != a[i-1].first)
			c = i+1;
		ans[a[i].second] = c;
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}