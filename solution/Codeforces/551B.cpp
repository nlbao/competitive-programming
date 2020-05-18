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


const int MAX_N = 1e5 + 5;
const int MAX_X = 27;


int na, nb, nc;
char a[MAX_N], b[MAX_N], c[MAX_N];
int ca[MAX_X], cb[MAX_X], cc[MAX_X], d[MAX_N];


int find(int m) {
	for (int i = 0; i < MAX_X; ++i)
		d[i] = ca[i];
	for (int i = 0; i < MAX_X; ++i)
		if (m*cb[i] > d[i]) return -1;
		else d[i] -= m*cb[i];
	int ans = MAX_N;
	for (int i = 0; i < MAX_X; ++i)
		if (cc[i] > 0)
			ans = min(ans, d[i] / cc[i]);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("551B.in", "r", stdin);
	freopen("551B.out", "w", stdout);
#endif
	scanf("%s%s%s", a, b, c);
	na = strlen(a), nb = strlen(b), nc = strlen(c);
	filla(ca, 0);
	filla(cb, 0);
	filla(cc, 0);
	for (int i = 0; i < na; ++i) ++ca[a[i]-'a'];
	for (int i = 0; i < nb; ++i) ++cb[b[i]-'a'];
	for (int i = 0; i < nc; ++i) ++cc[c[i]-'a'];

	int tb = 0, tc = 0;
	for (int i = 0; i < (na / nb) + 1; ++i) {
		int j = find(i);
		if (j > -1 && i+j > tb+tc) {
			tb = i;
			tc = j;
		}
	}

	if (tb == 0 && tc == 0)
		printf("%s", a);
	else {
		for (int i = 0; i < tb; ++i) printf("%s", b);
		for (int i = 0; i < tc; ++i) printf("%s", c);
		for (int i = 0; i < nb; ++i) ca[b[i]-'a'] -= tb;
		for (int i = 0; i < nc; ++i) ca[c[i]-'a'] -= tc;
		for (int i = 0; i < MAX_X; ++i)
			for (int j = 0; j < ca[i]; ++j)
				printf("%c", char('a' + i));
	}
	return 0;
}