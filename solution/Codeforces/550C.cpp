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


char s[MAX_N];
int n;
int a[MAX_N];
bool f[MAX_N][2][8];
string ans;


inline int mmod(int x) {
	x %= 8;
	if (x < 0) x += 8;
	return x;
}


void printAns(int i, int status, int r) {
	if (status == 1) ans = s[i] + ans;
	if (i < 1) return;

	if (status == 0) {
		if (f[i-1][1][r]) printAns(i-1, 1, r);
		else printAns(i-1, 0, r);
		return;
	}

	int k = -1;
	for (int t = 0; t < 8; ++t)
		if (mmod(10*t + a[i]) == r)
			if (f[i-1][1][t] || f[i-1][0][t]) {
				k = t;
				break;
			}

	if (f[i-1][1][k]) printAns(i-1, 1, k);
	else printAns(i-1, 0, k);
}


bool solve() {
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		a[i] = s[i] - '0';
		if (a[i] == 0) {
			printf("YES\n0");
			return true;
		}
		a[i] = mmod(a[i]);
	}

	filla(f, false);
	f[0][0][0] = true;
	f[0][1][a[0]] = true;
	for (int i = 1; i < n; ++i)
		for (int k = 0; k < 8; ++k) {
			f[i][0][k] = f[i-1][0][k] || f[i-1][1][k];
			int r = mmod(10*k + a[i]);
			f[i][1][r] = f[i][1][r] || (f[i-1][1][k] || f[i-1][0][k]);
		}

	for (int i = 0; i < n; ++i)
		if (f[i][1][0]) {
			printf("YES\n");
			ans = "";
			printAns(i, 1, 0);
			cout << ans;
			return true;
		}

	return false;
}


int main() {
#ifdef DEBUG
	freopen("550C.in", "r", stdin);
	freopen("550C.out", "w", stdout);
#endif
	scanf("%s", s);
	if (!solve()) printf("NO");
	return 0;
}