// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e6+1;
const int MAX_A = 26;

string s;
int n, m;
int a[MAX_N], f[MAX_N][MAX_A];


int main() {
#ifdef DEBUG
	freopen("smriti-and-strings.in", "r", stdin);
	freopen("smriti-and-strings.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest;
	cin >> nTest;
	while (nTest--) {
		cin >> s >> m;
		n = s.size();
		for (int i = 0; i < n; ++i)
			a[i] = s[i] - 'a';
		for (int x = 0; x < MAX_A; ++x)
			f[n][x] = -1;
		for (int i = n-1; i >= 0; --i) {
			for (int x = 0; x < MAX_A; ++x)
				f[i][x] = f[i+1][x];
			f[i][a[i]] = i;
		}
		int i = 0, cnt = n - m;
		while (i < n && m > 0 && cnt > 0) {
			for (int x = MAX_A-1; x >= 0; --x) {
				int k = f[i][x];
				if (k < 0) continue;
				if (k-i > m) continue;
				if (n-k < cnt) continue;
				cout << s[k];
				m -= k-i;
				i = k+1;
				--cnt;
				break;
			}
		}
		for (; i < n && cnt > 0; ++i, --cnt)
			cout << s[i];
		cout << endl;
	}

	return 0;
}