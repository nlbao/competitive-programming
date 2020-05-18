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


const int MAX_N = 33;
const int oo = int(1e9);
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m, sx, sy, tx, ty;
int a[MAX_N][MAX_N], f[MAX_N][MAX_N];
char s[MAX_N];
queue<pii> q;
bool in_q[MAX_N][MAX_N];



bool ok(int x, int y) {
	return !(x < 0 || x >=m || y < 0 || y >= n || a[x][y] == -1);
}



int bfs() {
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			f[i][j] = oo;
	f[sx][sy] = 0;

	while (!q.empty()) q.pop();
	q.push(mp(sx, sy));

	fill(in_q, false);
	in_q[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().fr, y = q.front().sc;
		q.pop();
		in_q[x][y] = false;
		for (int k = 0; k < 4; ++k) {
			int i = x + dx[k], j = y + dy[k];
			if (ok(i, j) && f[x][y]+a[i][j] < f[i][j]) {
				f[i][j] = f[x][y] + a[i][j];
				if (!in_q[i][j]) {
					q.push(mp(i, j));
					in_q[i][j] = true;
				}
			}
		}
	}
	return f[tx][ty];
}



int main() {
#ifdef DEBUG
	freopen("SHOP.in", "r", stdin);
	freopen("SHOP.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		cin >> n >> m;
		cin.get();
		if (m == 0) break;
		fill(a, 0);
		for (int i = 0; i < m; ++i) {
			cin.get(s, n+1, '\n');
			cin.get();
			for (int j = 0; j < n; ++j)
				switch(s[j]) {
					case 'X':
						a[i][j] = -1;
						break;

					case 'S':
						sx = i;
						sy = j;
						break;

					case 'D':
						tx = i;
						ty = j;
						break;

					default:
						a[i][j] = s[j] - '0';
						break;
				}
		}
		cout << bfs() << '\n';
	}
	return 0;
}