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


const int MAX_N = 111;


ll w, m;
int a[MAX_N], f[MAX_N], carry[MAX_N];
bool hasCarry[MAX_N];


inline ll mmod(ll x) {
	x %= w;
	if (x < 0) x += w;
	return x;
}


bool solve() {
	int n = 0;
	while (m > w) {
		a[n++] = m%w;
		m /= w;
	}
	a[n++] = m;

	filla(hasCarry, false);
	for (int i = 0; i < n; ++i)
		if (a[i] > 1) {
			if (a[i] < w-2) return false;
			if (a[i] == w-2) hasCarry[i] = true;
		}
	filla(carry, 0);
	filla(f, 0);
	for (int i = 0; i < n; ++i) {
		int t = a[i] + carry[i];
		if (t == 0) {
			if (hasCarry[i+1]) return false;
		}
		else if (t == 1) {
			if (hasCarry[i+1]) {
				if (w > 2) return false;
				f[i] = 1;
				carry[i+1] = 1;
			}
		}
		else if (t == w) {
			carry[i+1] = 1;
		}
		else if (t < w-1) return false;
		else if (t == w-1) {
			f[i] = 1;
			carry[i+1] = 1;
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	freopen("552C.in", "r", stdin);
	freopen("552C.out", "w", stdout);
#endif
	w = read();
	m = read();
	if (solve()) printf("YES");
	else printf("NO");
	return 0;
}