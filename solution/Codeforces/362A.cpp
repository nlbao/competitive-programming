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

const int n = 8;
const int MAX_N = 13;
const int dx[4] = {-2, -2, +2, +2};
const int dy[4] = {-2, +2, +2, -2};


char a[MAX_N][MAX_N];
int sx, sy, tx, ty;
queue< pair<pii, pii> > q;
bool c[MAX_N][MAX_N][MAX_N][MAX_N];


bool ok(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n) return false;
	return true;
	//return a[i][j] != '#';
}


void enter() {
	sx = -1;
	rep(i, n) {
		gets(a[i]);
		rep(j, n)
			if (a[i][j] == 'K')
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					tx = i;
					ty = j;
				}
		// printf("%s\n", a[i]);
	}
}


bool bfs(int x1, int y1, int x2, int y2) {
	fill(c, true);
	c[x1][y1][x2][y2] = false;
	while (!q.empty()) q.pop();
	q.push(mp(mp(x1, y1), mp(x2, y2)));

	while (!q.empty()) {
		pair<pii, pii> u = q.front(); q.pop();
		x1 = u.fr.fr;	y1 = u.fr.sc;
		x2 = u.sc.fr;	y2 = u.sc.sc;
		if (x1 == x2 && y1 == y2 && a[x1][y1] != '#') return true;
		rep(k1, 4) {
			int u1 = x1 + dx[k1];
			int v1 = y1 + dy[k1];
			if (!ok(u1, v1)) continue;

			rep(k2, 4) {
				int u2 = x2 + dx[k2];
				int v2 = y2 + dy[k2];
				if (!ok(u2, v2)) continue;
				if (u1 == u2 && v1 == v2) return true;
				if (c[u1][v1][u2][v2]) {
					c[u1][v1][u2][v2] = false;
					q.push(mp(mp(u1, v1), mp(u2, v2)));
				}
			}
		}
	}
	return false;
}


string solve() {
	if (bfs(sx, sy, tx, ty)) return "YES";
	return "NO";
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("362A.in", "r", stdin);
	freopen("362A.out", "w", stdout);
#endif
	int nTest = readln();
	rep(test_id, nTest) {
		enter();
		cout << solve() << endl;
		if (test_id < nTest-1) gets(a[0]);
	}
	return 0;
}