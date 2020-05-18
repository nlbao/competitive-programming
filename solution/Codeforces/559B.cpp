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


const int MAX_N = 2e5 + 55;


int n;
char a[MAX_N], b[MAX_N], ta[MAX_N], tb[MAX_N];


void getS(char a[], char s[], int l, int r) {
	if (l > r) return;
	if ((r-l+1)&1) {
		for (int i = l; i <= r; ++i)
			s[i] = a[i];
		return;
	}

	int mid = (l+r)>>1;
	getS(a, s, l, mid);
	getS(a, s, mid+1, r);

	bool ok = true;
	for (int i = l, j = mid+1; i <= mid; ++i, ++j)
		if (s[i] != s[j]) {
			ok = s[i] < s[j];
			break;
		}
	if (ok) return;
	for (int i = l, j = mid+1; i <= mid; ++i, ++j)
		swap(s[i], s[j]);
}


bool solve() {
	getS(a, ta, 0, n-1);
	getS(b, tb, 0, n-1);

	for (int i = 0; i < n; ++i)
		if (ta[i] != tb[i])
			return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("559B.in", "r", stdin);
	freopen("559B.out", "w", stdout);
#endif
	scanf("%s", &a);
	scanf("%s", &b);
	n = strlen(a);
	if (solve()) printf("YES\n");
	else printf("NO\n");
	return 0;
}