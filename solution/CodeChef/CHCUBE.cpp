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


char s[22];
string a[6];
int d[6];


void input(int i) {
	a[i] = "";
	int n = strlen(s);
	for (int k = 0; k < n; ++k)
		a[i] += s[k];
}


string solve() {
	for (int i = 0; i < 6; ++i)
		for (int j = 0; j < 6; ++j)
			for (int k = 0; k < 6; ++k) {
				if (i == j || i == k || j == k) continue;
				if (i == d[j] || i == d[k]) continue;
				if (j == d[i] || j == d[k]) continue;
				if (k == d[i] || k == d[j]) continue;
				if (a[i] == a[j] && a[j] == a[k])
					return "YES";
			}
	return "NO";
}


int main() {
#ifdef DEBUG
	freopen("CHCUBE.in", "r", stdin);
	freopen("CHCUBE.out", "w", stdout);
#endif
	d[0] = 2;	d[1] = 3;	d[2] = 0;
	d[3] = 1;	d[4] = 5;	d[5] = 4;
	int nTest = read();
	while (nTest--) {
		scanf("%s", s);	input(4);
		scanf("%s", s);	input(5);
		scanf("%s", s);	input(3);
		scanf("%s", s);	input(1);
		scanf("%s", s);	input(2);
		scanf("%s", s);	input(0);
		printf("%s\n", solve().c_str());
	}
	return 0;
}