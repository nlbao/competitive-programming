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


bool solve() {
	int n = strlen(s);
	int minA = MAX_N, maxA = -1;
	int minB = MAX_N, maxB = -1;
	for (int i = 0; i < n-1; ++i) {
		if (s[i] == 'A' && s[i+1] == 'B') {
			minA = min(minA, i);
			maxA = max(maxA, i);
		}
		if (s[i] == 'B' && s[i+1] == 'A') {
			minB = min(minB, i);
			maxB = max(maxB, i);
		}
	}
	if (maxA < 0 || maxB < 0) return false;
	return (minA < maxB-1) || (minB < maxA-1);
}


int main() {
#ifdef DEBUG
	freopen("550A.in", "r", stdin);
	freopen("550A.out", "w", stdout);
#endif
	scanf("%s", s);
	if (solve()) printf("YES");
	else printf("NO");
	return 0;
}