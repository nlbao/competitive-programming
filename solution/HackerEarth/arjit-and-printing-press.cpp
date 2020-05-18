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

inline int read() {   int x;   cin >> x;   return x;   }


const int MAX_N = 1e4 + 44;
const int MAX_C = 29;


string a, b;
int c[MAX_C];


int main() {
#ifdef DEBUG
	freopen("arjit-and-printing-press.in", "r", stdin);
	freopen("arjit-and-printing-press.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cout.precision(9);

	int nTest = read();
	while (nTest--) {
		cin >> a >> b;
		filla(c, 0);
		int n = b.size();
		for (int i = 0; i < n; ++i)
			++c[b[i]-'a'];
		n = a.size();
		for (int i = 0, j = 0; i < n && j < MAX_C; ++i) {
			while (j < MAX_C && c[j] == 0) ++j;
			if (j >= MAX_C) break;
			if (j < a[i]-'a') {
				a[i] = char(j+'a');
				--c[j];
			}
		}
		cout << a << '\n';
	}
	return 0;
}