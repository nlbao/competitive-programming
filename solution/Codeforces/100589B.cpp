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


const int A = 26;
const int B = 62;
const int C = 62;
const int MAX_N = A * B * C + 44;


int n;
int id[A][B][C], f[MAX_N];
char a[111], b[111];


string toString(int x) {
	string s = "";
	while (x > 0) {
		s = char(x%10 + '0') + s;
		x /= 10;
	}
	if (s == "") s = "0";
	if (s.length() < 2) s = "0" + s;
	return s;
}


string toTime(int x, int y, int z) {
	return toString(x) + ":" + toString(y) + ":" + toString(z);
}


int isPalin(string s) {
	for (int i = 0, j = s.length()-1; i < j; ++i, --j)
		if (s[i] != s[j])
			return 0;
	return 1;
}


int getID(char a[]) {
	int x[3], p = 0;
	for (int i = 0; i < 3; ++i) {
		x[i] = 0;
		for (int k = 0; k < 2; ++k)
			x[i] = x[i]*10 + a[p++] - '0';
		++p;
	}
	return id[x[0]][x[1]][x[2]];
}


int main() {
#ifdef DEBUG
	freopen("100589B.in", "r", stdin);
	freopen("100589B.out", "w", stdout);
#endif
	n = 0;
	f[0] = 0;
	for (int i = 0; i < 24; ++i)
		for (int j = 0; j < 60; ++j)
			for (int k = 0; k < 60; ++k) {
				id[i][j][k] = ++n;
				f[n] = f[n-1] + isPalin(toTime(i, j, k));
			}
	int nQ = read();
	while (nQ--) {
		scanf("%s%s", a, b);
		int i = getID(a), j = getID(b);
		printf("%d\n", f[j] - f[i-1]);
	}
	return 0;
}