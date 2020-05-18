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


const int MAX_N = 111;


int nCol;
int a[MAX_N], endCol[MAX_N];
char ansMap[MAX_N][MAX_N];


int solve() {
	int s = 0;
	for (int i = 0; i < nCol; ++i)
		s += a[i];
	if (s != nCol) return -1;

	// mapping
	for (int i = 0; i < nCol; ++i)
		endCol[i] = -1;
	int crrCol = 0;
	for (int i = 0; i < nCol; ++i) {
		while (a[i] > 0) {
			endCol[crrCol] = i;
			++crrCol;
			--a[i];
		}
	}
	if (endCol[0] != 0) return -1;	// left column must be empty
	if (endCol[nCol-1] != nCol-1) return -1;  // right column must be empty

	// calculate nRow
	int nRow = 0;
	for (int i = 0; i < nCol; ++i)
		nRow = max(nRow, abs(i-endCol[i]));
	++nRow; // last row is empty

	// draw the map
	for (int i = 0; i < nRow; ++i)
		for (int k = 0; k < nCol; ++k)
			ansMap[i][k] = '.';
	for (int col = 0; col < nCol; ++col) {
		int end = endCol[col];
		char dir = (col < end) ? '\\' : '/';
		for (int row = 0, k = col; k != end; ++row) {
			assert(row < nRow);
			ansMap[row][k] = dir;
			if (k < end) ++k;
			else --k;
		}
	}
	return nRow;
}


int main() {
#ifdef DEBUG
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> nCol;
		for (int i = 0; i < nCol; ++i)
			cin >> a[i];
		int nRow = solve();
		cout << "Case #" << testid << ": ";
		if (nRow < 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << nRow << endl;
			for (int i = 0; i < nRow; ++i) {
				for (int k = 0; k < nCol; ++k)
					cout << ansMap[i][k];
				cout << endl;
			}
		}
	}

	return 0;
}