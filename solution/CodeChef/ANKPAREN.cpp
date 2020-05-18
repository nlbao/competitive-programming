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

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;


char s[MAX_N];
int a[MAX_N], f[MAX_N];


inline int num(char x) {
	if (x == '(') return 1;
	return -1;
}


bool solve(int k) {
	int n = strlen(s);
	int sum = 0;
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		sum += num(s[i]);
		if (sum < 0) ok = false;
	}
	if (sum != 0) ok = false;

	if (!ok) {
		if (k > 1) return false;
		printf("%s\n", s);
		return true;
	}

	f[0] = 0;
	for (int i = 1; i < n; ++i)
		f[i] = f[i-1] + int(s[i] != s[i-1]);
	int m = f[n-1] + 1;
	if (k > m) return false;

	int c = 0;
	for (int i = 1; i < m; i += 2)
		a[c++] = i;
	for (int i = m-1 - int(m%2 == 0); i >= 0; i -= 2)
		a[c++] = i;

	// printf("%s\n", s);
	// for (int i = 0; i < c; ++i) cout << a[i] << " ";
	// cout << endl;

	int t = a[k-1];
	bool del = false;
	for (int i = 0; i < n; ++i) {
		if (del) printf("%c", s[i]);
		else {
			if (f[i] == t) del = true;
			else printf("%c", s[i]);
		}
	}
	printf("\n");
	return true;
}


int main() {
#ifdef DEBUG
	freopen("ANKPAREN.in", "r", stdin);
	freopen("ANKPAREN.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);
		int k = read();
		if (!solve(k)) printf("-1\n");
	}
	return 0;
}