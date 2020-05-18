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

const int MAX_A = 202;


int width, height;
int ok[MAX_A][MAX_A];


pii getTarget(int x, int y) {
	pii ans(-1, -1);
	for (int dx = -1; dx <= 1; ++dx) {
		int xx = x + dx;
		// cout << "			" << xx << endl;
		if (xx < 2 || xx >= width) continue;
		for (int dy = -1; dy <= 1; ++dy)  {
			int yy = y + dy;
			// cout << "		" << xx << " " << yy << endl;
			if (yy < 2 || yy >= height) continue;
			// TODO: improving by select the cell with max number of adjacent unprepared cells
			ans = pii(xx, yy);
			if (!ok[xx][yy]) return ans;
		}
	}
	return ans;
}


// A = 20 or A = 200
bool solve(int A) {
	while (A%3 != 0) ++A;
	width = height = -1;
	for (int i = 3; i < A; ++i)
		if ((A%i) == 0) {
			width = i;
			height = A/i;
			break;
		}
	vector<pii> remainCells, tmp;
	for (int i = 1; i <= width; ++i)
		for (int k = 1; k <= height; ++k) {
			ok[i][k] = false;
			remainCells.push_back(pii(i, k));
		}
	// cout << "???" << ": " << width << " " << height << endl << std::flush;
	while (!remainCells.empty()) {
		foreach(it, remainCells) {
			int x = it->first, y = it->second;
			pii targetCell = getTarget(x, y);
			cout << targetCell.first << " " << targetCell.second << endl << std::flush;
			cin >> x >> y;
			if (x == 0 && y == 0) return true;
			if (x < 0 || y < 0) return false;
			ok[x][y] = true;
		}
		///////
		tmp.clear();
		foreach(it, remainCells) {
			int x = it->first, y = it->second;
			if (!ok[x][y]) tmp.push_back(*it);
		}
		remainCells.clear();
		foreach(it, tmp) remainCells.push_back(*it);
	}
	return true;
}


int main() {
// #ifdef DEBUG
	// freopen("C.in", "r", stdin);
	// freopen("C.out", "w", stdout);
// #endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);
	int nTest = read();
	int A;
	while (nTest > 0) {
		--nTest;
		cin >> A;
		if (!solve(A)) break;
	}

	return 0;
}