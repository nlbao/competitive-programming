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


const int MAX_N = 2022;
const int MAX_M = 209;
const ll COL_BASE = 10007;
const ll ROW_BASE = 1299059;

typedef map<ll, pii> hashToPosType;

int N, M;
string mapA[MAX_N], mapB[MAX_N];
map<ll, pii> hashToPosA, hashToPosB;
ll h[MAX_N][MAX_N];
ll pRowBase[MAX_N], pColBase[MAX_N];


ll getHashCol(int col, int startRow, int endRow) {
	if (startRow == 0) return h[col][endRow];
	return h[col][endRow] - h[col][startRow-1] * pColBase[endRow-startRow+1];
}


void collect_hashes(string mapValues[], int nRow, int nCol, hashToPosType &hashToPos) {
	// build hashCol
	for (int col = 0; col < nCol; ++col) {
		h[col][0] = mapValues[0][col];
		for (int row = 1; row < nRow; ++row) {
			h[col][row] = h[col][row-1] * COL_BASE + ll(mapValues[row][col]);
		}
	}
	// cal hashToPos
	for (int startRow = 0, endRow = M-1; endRow < nRow; ++startRow, ++endRow) {
		ll total = 0;
		for (int col = 0; col < M-1; ++col)
			total = ROW_BASE * total + getHashCol(col, startRow, endRow);
		for (int col = M-1, startCol = 0; col < nCol; ++col, ++startCol) {
			total = ROW_BASE * total + getHashCol(col, startRow, endRow);
			hashToPos[total] = pii(startRow, startCol);
			total -= pRowBase[M-1] * getHashCol(startCol, startRow, endRow);
		}
	}
}

pii solve() {
	pRowBase[0] = 1;
	pColBase[0] = 1;
	for (int i = 1; i < N+2; ++i) {
		pRowBase[i] = pRowBase[i-1] * ROW_BASE;
		pColBase[i] = pColBase[i-1] * COL_BASE;
	}
	collect_hashes(mapA, N, M, hashToPosA);
	collect_hashes(mapB, M, N, hashToPosB);
	foreach(it, hashToPosA) {
		ll h = it->first;
		pii posA = it->second;
		__typeof(hashToPosB.begin()) itB = hashToPosB.find(h);
		if (itB != hashToPosB.end()) {
			pii posB = itB->second;
			return pii(posA.first+1, posB.second+1);
		}
	}
	return pii(-1, -1);
}


int main() {
#ifdef DEBUG
	freopen("958A2.in", "r", stdin);
	freopen("958A2.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> mapA[i];
	for (int i = 0; i < M; ++i)
		cin >> mapB[i];
	pii ans = solve();
	cout << ans.first << " " << ans.second << endl;

	return 0;
}