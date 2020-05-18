#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 5e4 + 4;
const int MAX_A = 30;


char s[MAX_N];
int c[MAX_A];
pii a[MAX_A];


int main() {
#ifdef DEBUG
	freopen("count-the-string.in", "r", stdin);
	freopen("count-the-string.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		filla(c, 0);
		int n = read(), k = read();
		scanf("%s", s);
		for (int i = 0; i < n; ++i)
			++c[s[i]-'a'];
		int m = 0;
		for (int i = 0; i < MAX_A; ++i)
			if (c[i] > k)
				a[m++] = pii(-c[i], i);
		if (m == 0) {
			printf("NONE\n");
			continue;
		}
		sort(a, a+m);
		for (int i = 0; i < m; ++i)
			printf("%c", char('a'+a[i].second));
		printf("\n");
	}
	return 0;
}