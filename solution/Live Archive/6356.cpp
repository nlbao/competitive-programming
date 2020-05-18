#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
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
#define size(a) int(a.size())
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

const int MAX_N = 100005;
const int oo = 1000000000;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


int n, m, nTime, minR, maxU;
int a[MAX_N], turn[MAX_N], ok[MAX_N];
int d[MAX_N], f[MAX_N], g[MAX_N], h[MAX_N];
vi e[MAX_N];
queue<pii> q;


int id(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return -1;
	return (x-1)*m+y;
}


void bfs(int sx, int sy) {
	if (turn[id(sx, sy)]) return;
	++nTime;
	while (!q.empty()) q.pop();
	q.push(mp(sx, sy));

	while (!q.empty()) {
		sx = q.front().fr;
		sy = q.front().sc;
		q.pop();
		int u = id(sx, sy);
		turn[u] = nTime;

		rep(k, 4) {
			int x = sx+dx[k], y = sy+dy[k];
			int v = id(x, y);
			if (v < 1 || turn[v] == nTime) continue;
			if (a[v] == a[u]) {
				turn[v] = nTime;
				q.push(mp(x, y));
			}
			else if (turn[v] && ok[turn[v]] < nTime) {
				e[nTime].pb(turn[v]);
				e[turn[v]].pb(nTime);
				ok[turn[v]] = nTime;
			}
		}
	}
}


void dfs(int u) {
    d[u] = 1;
    h[u] = 0;
	int szE = size(e[u]), m = 0;
    if (szE == 0) return;
	rep(i, szE) {
		int v = e[u][i];
		if (ok[v] == 0) {
            ok[v] = u;
			dfs(v);
            d[u] = max(d[u], d[v]+1);
            a[m++] = v;
		}
	}

    f[0] = a[0];
    foru(i, 1, m-1)
        f[i] = max(f[i-1], d[a[i]]);
    g[m] = 0;
    ford(i, szE-1, 0)
        g[i] = max(g[i+1], d[a[i]]);

    rep(i, m) {
        if (i) h[a[i]] = max(h[a[i]], f[i-1]+1);
        h[a[i]] = max(h[a[i]], g[i+1]+1);
        minR = min(minR, f[i] + 1 + g[i+1]);
    }
}

void dfs_2(int u) {
    int szE = size(e[u]);
    rep(i, szE) {
        int v = e[u][i];
        if (ok[v] == u) {
            h[v] = max(h[v], h[u]+1);
            dfs(v);
        }
    }
    minR = min(minR, h[u] + d[u]);
}


int solve() {
    minR = nTime;
    fill(d, 0);
    fill(ok, 0);
    ok[1] = -1;
    dfs(1);
    dfs_2(1);
    return minR;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("6356.in", "r", stdin);
    freopen("6356.out", "w", stdout);
#endif
    for(;;) {
    	scanf("%d%d", &n, &m);
    	if (n < 1) break;
    	foru(i, 1, n) {
    		char ch;
    		scanf("%c", &ch);
    		foru(j, 1, m) {
    			scanf("%c", &ch);
    			int u = id(i, j);
    			a[u] = ch-'0';
    			e[u].clear();
    		}
    	}

//create tree
    	nTime = 0;
    	fill(ok, 0);
    	fill(turn, 0);
    	foru(i, 1, n)
    		foru(j, 1, m)
    			bfs(i, j);

//solve
    	int res = solve();
    	printf("%d\n", res);
    }
    return 0;
}