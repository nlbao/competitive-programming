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


const int N = 30;


char s[int(1e5) + 5];
int c[N];


bool solve() {
	sort(c, c + N);
	int i = 0;
	while (i < N && c[i] == 0) ++i;
	int t = 0;
	for (int j = i; j < N; ++j)
		t += c[j] - c[i];
	if (t <= 1) return true;
	if (c[i] == 1) {
		for (int j = i+2; j < N; ++j)
			if (c[j] != c[j-1]) return false;
		return true;
	}
	return false;
	// for (int i = 0; i < N; ++i) cout << c[i] << endl;
}


int main() {
#ifdef DEBUG
	freopen("sherlock-and-valid-string.in", "r", stdin);
	freopen("sherlock-and-valid-string.out", "w", stdout);
#endif
	filla(c, 0);
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i)
		++c[s[i]-'a'];

	if (solve()) printf("YES");
	else printf("NO");
	return 0;
}