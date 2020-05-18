#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>
#include <iomanip>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define foreach(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_H = 14;
const int MAX_N = MAX_H * MAX_H;
const double EPS = 1e-9;
const double oo = 1e9;


int id[MAX_H][MAX_H];
pii rid[MAX_N];
vector< vector<double> > a;
vector<double> ans;
double value[MAX_H][MAX_H];


int gauss(vector< vector<double> > &a, vector<double> &ans, int &rank) {
	int n = (int)a.size();
	int m = (int)a[0].size() - 1;
	for (int col = 0, row = 0; col < m && row < n; ++col) {
		int k = row;
		for (int i = row+1; i < n; ++i)
			if (abs(a[i][col]) > abs(a[k][col]))
				k = i;
		if (abs(a[k][col]) < EPS) continue;

		for (int i = col; i <= m; ++i)
			swap(a[k][i], a[row][i]);
		for (int i = 0; i < n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j = col+1; j <= m; ++j)
					a[i][j] -= a[row][j] * c;
				a[i][col] = 0;
			}
		++row;
	}

	// check no solution
	for (int i = 0; i < n; ++i) {
		bool zero = true;
		for (int j = 0; j < m; ++j)
			if (abs(a[i][j]) >= EPS) {
				zero = false;
				break;
			}
		if (zero && abs(a[i][m]) >= EPS)
			return 0;
	}

	rank = 0;
	ans.assign(m, 0);
	for (int i = 0, j = 0; i < n && j < m; ++j)
		if (abs(a[i][j]) >= EPS) {
			ans[j] = a[i][m] / a[i][j];
			++i, ++rank;
		}
	if (rank < m) return oo;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("ANARC09I.in", "r", stdin);
	freopen("ANARC09I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	bool firstTest = true;
	while (true) {
		int H, W, D, n = 0;
		cin >> W >> H >> D;
		if (H == 0) break;

		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				cin >> value[i][j];
				rid[n] = make_pair(i, j);
				id[i][j] = n++;
			}

		a.clear();
		a.resize(n);
		for (int i = 0; i < H; ++i)
			for (int j = 0; j < W; ++j) {
				int cnt = 0, pos = id[i][j];
				a[pos].resize(n+1, 0);
				for (int x = 0; x < H; ++x)
					for (int y = 0; y < W; ++y) {
						if (abs(x-i) + abs(y-j) > D) continue;
						++cnt;
					}
				for (int x = 0; x < H; ++x)
					for (int y = 0; y < W; ++y) {
						if (abs(x-i) + abs(y-j) > D) continue;
						a[pos][id[x][y]] = 1.0/cnt;
					}
				a[pos][n] = value[i][j];
			}

		int rank;
		ans.clear();
		gauss(a, ans, rank);
		for (int i = 0; i < n; ++i) {
			int x = rid[i].first, y = rid[i].second;
			value[x][y] = ans[i];
		}

		if (!firstTest) cout << '\n';
		else firstTest = false;

		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j)
				cout << setw(8) << fixed << setprecision(2) << fabs(value[i][j]);
			cout << '\n';
		}
	}
	return 0;
}