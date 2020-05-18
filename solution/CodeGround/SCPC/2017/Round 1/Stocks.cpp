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


const int MAX_N = 2e5+5;


int n;
int price[MAX_N], f[MAX_N];
int stk[MAX_N];


int solve_0() {
	filla(f, 0);
	for (int i = 1; i < n; ++i) {
		int x = price[i];
		for (int k = 0; k < i; ++k)
			if (price[k] < x) {
				f[i] = max(f[i], 2 + (k>0 ? f[k-1] : 0));
			}
		f[i] = max(f[i], f[i-1]);
	}
	return f[n-1];
}


int solve() {
	filla(f, 0);
	int top = 1;
	stk[0] = 0;
	for (int i = 1; i < n; ++i) {
		int x = price[i];
		int l = 0, r = top-1, k = -1;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (price[stk[mid]] < x) {
				k = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		if (k > -1)
			f[i] = 2 + (stk[k]>0 ? f[stk[k]-1] : 0);
		f[i] = max(f[i], f[i-1]);
		while (top > 0 && price[stk[top-1]] >= x) --top;
		stk[top++] = i;
	}
	return f[n-1];
}


int main() {
#ifdef DEBUG
	freopen("Stocks.in", "r", stdin);
	freopen("Stocks.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid=1; testid <= nTest; ++testid) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> price[i];
		cout << "Case #" << testid << endl;
		if (n <= 5000) cout << solve_0() << endl;
		else cout << solve() << endl;
	}

	return 0;
}