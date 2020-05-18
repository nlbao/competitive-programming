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


const int MAX_N = 505;


int nRow, nCol;
int a[MAX_N][MAX_N];
int sBot[MAX_N][MAX_N], sTop[MAX_N][MAX_N], sRight[MAX_N][MAX_N], sLeft[MAX_N][MAX_N];


inline void update(int &x, int value) {
	x = max(x, value);
}


void build_squares() {
	for (int i = 1; i <= nRow; ++i)
		for (int k = 1; k <= nCol; ++k) {
			update(sTop[i][k], max(a[i-1][k-1], sTop[i-1][k-1]));
			update(sTop[i][k], sTop[i-1][k]);
			update(sTop[i][k], sTop[i][k-1]);
		}
	for (int i = nRow; i >= 1; --i)
		for (int k = nCol; k >= 1; --k) {
			update(sBot[i][k], max(a[i+1][k+1], sBot[i+1][k+1]));
			update(sBot[i][k], sBot[i+1][k]);
			update(sBot[i][k], sBot[i][k+1]);
		}
	for (int i = nRow; i >= 1; --i)
		for (int k = 1; k <= nCol; ++k) {
			update(sLeft[i][k], max(a[i+1][k-1], sLeft[i+1][k-1]));
			update(sLeft[i][k], sLeft[i+1][k]);
			update(sLeft[i][k], sLeft[i][k-1]);
		}
	for (int i = 1; i <= nRow; ++i)
		for (int k = nCol; k >= 1; --k) {
			update(sRight[i][k], max(a[i-1][k+1], sRight[i-1][k+1]));
			update(sRight[i][k], sRight[i-1][k]);
			update(sRight[i][k], sRight[i][k+1]);
		}
}


void print_squares() {
	for (int i = 1; i <= nRow; ++i) {
		for (int k = 1; k <= nCol; ++k) {
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl << "Top:" << endl;
	for (int i = 1; i <= nRow; ++i) {
		for (int k = 1; k <= nCol; ++k) {
			cout << sTop[i][k] << " ";
		}
		cout << endl;
	}
	cout << "Bot:" << endl;
	for (int i = 1; i <= nRow; ++i) {
		for (int k = 1; k <= nCol; ++k) {
			cout << sBot[i][k] << " ";
		}
		cout << endl;
	}
	cout << "Left:" << endl;
	for (int i = 1; i <= nRow; ++i) {
		for (int k = 1; k <= nCol; ++k) {
			cout << sLeft[i][k] << " ";
		}
		cout << endl;
	}
	cout << "Right:" << endl;
	for (int i = 1; i <= nRow; ++i) {
		for (int k = 1; k <= nCol; ++k) {
			cout << sRight[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}


ll solve() {
	build_squares();
	// print_squares();
	ll ans = 2e9 + 99;
	for (int i = 2; i < nRow; ++i) {
		for (int k = 2; k < nCol; ++k) {
			ll maxX = max(max(sTop[i][k], sBot[i][k]), max(sLeft[i][k], sRight[i][k]));
			ll minX = min(min(sTop[i][k], sBot[i][k]), min(sLeft[i][k], sRight[i][k]));
			ans = min(ans, maxX-minX);
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("101972G.in", "r", stdin);
	freopen("101972G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> nRow >> nCol;
		for (int i = 0; i <= nRow+1; ++i)
			for (int k = 0; k <= nCol+1; ++k)
				a[i][k] = sTop[i][k] = sBot[i][k] = sLeft[i][k] = sRight[i][k] = 0;
		for (int i = 1; i <= nRow; ++i)
			for (int k = 1; k <= nCol; ++k)
				cin >> a[i][k];
		cout << solve() << endl;
	}

	return 0;
}