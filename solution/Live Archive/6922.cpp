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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5 + 5;


string s;
int a[MAX_N], b[MAX_N], f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("6922.in", "r", stdin);
	freopen("6922.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> s;
		int n = s.size();
		a[0] = b[0] = 0;
		for (int i = 1; i <= n; ++i) {
			a[i] = a[i-1];
			b[i] = b[i-1];
			if (s[i-1] == 'a') ++a[i];
			else ++b[i];
		}
		f[n+1] = 0;
		for (int i = n; i >= 1; --i)
			f[i] = max(f[i+1], b[i]-a[i]+1);

		int c = 0, ans = 0, i = 1;
		if (s[0] == '+') {
			if (i < n-1 && s[i] == 'a' && s[i+1] == 'a' && c >= f[i+2]) {
				ans = 2;
				i += 2;
			}
			else {
				c = ans = 1;
				if (!(i < n && s[i] == 'a' && c >= f[i+1]))
					++c;
				++ans;
				++i;
			}
		}
		for (; i <= n; ++i) {
			if (a[i]+c >= b[i]+1) continue;
			if (!(i < n && s[i] == 'a' && c >= f[i+1]))
				++c;
			++ans;
		}
		ans += abs(a[n]+c - (b[n]+1));
		cout << "Case " << testid << ": " << ans << endl;
	}

	return 0;
}