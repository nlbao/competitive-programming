#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int rock_dx[4] = {-1, 0, +1, 0};
const int rock_dy[4] = {0, -1, 0, +1};
const int bishop_dx[4] = {-1, -1, +1, +1};
const int bishop_dy[4] = {-1, +1, +1, -1};
const int king_dx[8] = {-1, 0, +1, 0, -1, -1, +1, +1};
const int king_dy[8] = {0, -1, 0, +1, -1, +1, +1, -1};
const int n = 8;
const int MAX_N = n+3;
const int oo = int(1e9);

int r1, c1, r2, c2;
int a[MAX_N][MAX_N];


bool ok(int x, int y) {
	return !(x < 1 || y < 1 || x > n || y > n);
}


int bfs_rock() {
	foru(i, 1, n)
		foru(j, 1, n)
			a[i][j] = oo;
	a[r1][c1] = 0;
	queue<pii> q;
	q.push(mp(r1, c1));
	while (!q.empty()) {
		int x = q.front().fr, y = q.front().sc;
		if (x == r2 && y == c2)
			return a[x][y];
		q.pop();
		rep(k, 4)
			foru(d, 1, n) {
				int i = x + rock_dx[k]*d;
				int j = y + rock_dy[k]*d;
				if (ok(i, j) && a[i][j] == oo) {
					a[i][j] = a[x][y]+1;
					q.push(mp(i, j));
				}
			}
	}
	return 0;
}


int bfs_bishop() {
	foru(i, 1, n)
		foru(j, 1, n)
			a[i][j] = oo;
	a[r1][c1] = 0;
	queue<pii> q;
	q.push(mp(r1, c1));
	while (!q.empty()) {
		int x = q.front().fr, y = q.front().sc;
		if (x == r2 && y == c2)
			return a[x][y];
		q.pop();
		rep(k, 4)
			foru(d, 1, n) {
				int i = x + bishop_dx[k]*d;
				int j = y + bishop_dy[k]*d;
				if (ok(i, j) && a[i][j] == oo) {
					a[i][j] = a[x][y]+1;
					q.push(mp(i, j));
				}
			}
	}
	return 0;
}


int bfs_king() {
	foru(i, 1, n)
		foru(j, 1, n)
			a[i][j] = oo;
	a[r1][c1] = 0;
	queue<pii> q;
	q.push(mp(r1, c1));
	while (!q.empty()) {
		int x = q.front().fr, y = q.front().sc;
		if (x == r2 && y == c2)
			return a[x][y];
		q.pop();
		rep(k, 8) {
			int i = x + king_dx[k];
			int j = y + king_dy[k];
			if (ok(i, j) && a[i][j] == oo) {
				a[i][j] = a[x][y]+1;
				q.push(mp(i, j));
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("370A.in", "r", stdin);
	freopen("370A.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	cout << bfs_rock() << " " << bfs_bishop() << " " <<	bfs_king() << endl;
	return 0;
}