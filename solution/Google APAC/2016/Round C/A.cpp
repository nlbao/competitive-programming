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


const int MAX_N = 22;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int m, n, maxLen;
double P, Q, sum, finalAns;
double a[MAX_N][MAX_N], b[MAX_N][MAX_N];
bool used[MAX_N][MAX_N], ok[MAX_N][MAX_N];


inline bool onBoard(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < m) && (y < n);
}


void tryf(int x, int y, int len) {
	finalAns = max(finalAns, sum);
	if (len > maxLen) return;
	if (sum + (maxLen-len+1)*P <= finalAns) return;

	if (len > 0) {
		double tmp = b[x][y], tmpSum = sum;
		sum += a[x][y] * b[x][y];
		b[x][y] *= (1-a[x][y]);
		for (int k = 0; k < 4; ++k) {
			int i = x + dx[k], j = y + dy[k];
			if (onBoard(i, j)) tryf(i, j, len+1);
		}
		b[x][y] = tmp;
		sum = tmpSum;
	}
	for (int k = 0; k < 4; ++k) {
		int i = x + dx[k], j = y + dy[k];
		if (onBoard(i, j)) tryf(i, j, len+1);
	}
}


int main() {
#ifdef DEBUG
	// freopen("A.in", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	int x, y;
	char ch;
	for (int testid = 1; testid <= nTest; ++testid) {
		cin >> m >> n >> x >> y >> maxLen;
		cin >> P >> Q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> ch;
				a[i][j] = (ch == 'A') ? P : Q;
				b[i][j] = 1;
			}
		}

		finalAns = 0;
		sum = 0;
		filla(used, 0);
		filla(ok, 1);
		tryf(x, y, 0);
		cout << "Case #" << testid << ": " << finalAns << endl;
	}

	return 0;
}