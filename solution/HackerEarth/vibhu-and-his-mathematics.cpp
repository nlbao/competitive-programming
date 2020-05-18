#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6 + 6;
const ll MODULE = 1e9 + 7;


ll f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("vibhu-and-his-mathematics.in", "r", stdin);
	freopen("vibhu-and-his-mathematics.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	f[0] = f[1] = 1;
	for (int i = 2; i < MAX_N; ++i)
		f[i] = (f[i-1] + f[i-2] * (i-1)) % MODULE;

	int nTest = read();
	while (nTest--) {
		int n = read();
		cout << f[n] << endl;
	}

	return 0;
}