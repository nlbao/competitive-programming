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


int R, C, H, V;
int cells[MAX_N][MAX_N], hID[MAX_N][MAX_N], vID[MAX_N][MAX_N], sum[MAX_N][MAX_N];


bool solve() {
	int nChoco = 0;
	for (int i = 0; i < R; ++i)
		for (int k = 0; k < C; ++k) {
			nChoco += cells[i][k];
			hID[i][k] = -1;
			vID[i][k] = -1;
		}
	if (nChoco == 0) return true;
	int nDiner = (H+1) * (V+1);
	if ((nChoco % nDiner) != 0) return false;
	int nChocoPerDiner = nChoco / nDiner;
	int nChocoPerH = nChoco / (H+1);
	int nChocoPerV = nChoco / (V+1);

	// cal hID
	int lastH = -1, rowsSum = 0, nH = 0;
	for (int i = 0; i < R; ++i) {
		for (int k = 0; k < C; ++k)
			rowsSum += cells[i][k];
		// cout << "H: " << i << " " << rowsSum << endl;
		if (rowsSum > nChocoPerH) return false;
		if (rowsSum < nChocoPerH) continue;
		for (int ii = lastH+1; ii <= i; ++ii)
			for (int k = 0; k < C; ++k)
				hID[ii][k] = nH;
		++nH;
		lastH = i;
		rowsSum = 0;
	}
	if (rowsSum != 0 || nH != H+1) return false;

	// cal vID
	int lastV = -1, colsSum = 0, nV = 0;
	for (int k = 0; k < C; ++k) {
		for (int i = 0; i < R; ++i)
			colsSum += cells[i][k];
		// cout << "V: " << k << " " << colsSum << endl;
		if (colsSum > nChocoPerV) return false;
		if (colsSum < nChocoPerV) continue;
		for (int kk = lastV+1; kk <= k; ++kk)
			for (int i = 0; i < R; ++i)
				vID[i][kk] = nV;
		++nV;
		lastV = k;
		colsSum = 0;
	}
	if (colsSum != 0 || nV != V+1) return false;

	// cal sum[h][v]
	for (int i = 0; i <= H; ++i)
		for (int k = 0; k <= V; ++k)
			sum[i][k] = 0;
	for (int i = 0; i < R; ++i)
		for (int k = 0; k < C; ++k) {
			// cout << i << " " << k << ": " << hID[i][k] << " " << vID[i][k] << ": " << cells[i][k] << endl;
			sum[hID[i][k]][vID[i][k]] += cells[i][k];
		}

	// check
	for (int i = 0; i <= H; ++i)
		for (int k = 0; k <= V; ++k)
			if (sum[i][k] != nChocoPerDiner)
				return false;
	return true;
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
	string s, ans;
	for (int tid = 1; tid <= nTest; ++tid) {
		cin >> R >> C >> H >> V;
		for (int i = 0; i < R; ++i) {
			cin >> s;
			for (int k = 0; k < C; ++k)
				cells[i][k] = int(s[k] == '@');
		}
		ans = solve() ? "POSSIBLE" : "IMPOSSIBLE";
		cout << "Case #" << tid << ": " << ans << endl;
	}

	return 0;
}