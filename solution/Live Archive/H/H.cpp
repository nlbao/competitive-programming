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

const int MAX_N = 111;
const int oo = 1000000000;


int n, D;
int szE[MAX_N];
vi e[MAX_N];
vii a[MAX_N];
bool ok[MAX_N];


void choose_horizontally(int u, int v0, int type) {
	int sx = a[v0][type].fr, sy = a[v0][type].sc;
	rep(i, szE[u]) {
		int v = e[u][i];
		if (v == v0) continue;
		int tx = oo;
		rep(j, 2)
			if (a[v][j].sc <= sy)
				tx = min(tx, a[v][j].fr);
		sx += tx;
	}
	sx += (szE[u]+1)*D;
	sy += 2*D;
	rep(j, 2)
		if (sx*sy < a[u][j].fr*a[u][j].sc) {
			a[u][j] = mp(sx, sy);
			break;
		}
}


void choose_vertically(int u, int v0, int type) {
	int sx = a[v0][type].fr, sy = a[v0][type].sc;
	rep(i, szE[u]) {
		int v = e[u][i];
		if (v == v0) continue;
		int ty = oo;
		rep(j, 2)
			if (a[v][j].fr <= sx)
				ty = min(ty, a[v][j].sc);
		sy += ty;
	}
	sy += (szE[u]+1)*D;
	sx += 2*D;
	rep(j, 2)
		if (sx*sy < a[u][j].fr*a[u][j].sc) {
			a[u][j] = mp(sx, sy);
			break;
		}
}


void dfs(int u) {
	if (szE[u] < 1) return;
	rep(i, szE[u])
		dfs(e[u][i]);

	rep(j, 2) a[u][j] = mp(oo, oo);
//horizontally
	rep(j, 2) {
		int id = 0, maxY = 0;
		rep(i, szE[u]) {
			int v = e[u][i];
			if (a[v][j].sc > maxY) {
				maxY = a[v][j].sc;
				id = v;
			}
		}
		choose_horizontally(u, id, j);
	}

//vertically
	rep(j, 2) {
		int id = 0, maxX = 0;
		rep(i, szE[u]) {
			int v = e[u][i];
			if (a[v][j].fr > maxX) {
				maxX = a[v][j].fr;
				id = v;
			}
		}
		choose_vertically(u, id, j);
	}
	cout << u << endl;
	rep(j, 2) cout << a[u][j].fr << " " << a[u][j].sc << endl;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("H.in", "r", stdin);
    //freopen("H.out", "w", stdout);
#endif
    for(;;) {
    	scanf("%d%d", &n, &D);
    	if (n == 0) break;
    	cout << n << endl;
    	foru(id, 1, n) {
    		e[id].clear();
    		a[id].clear();
    		scanf("%d", &szE[id]);
    		if (szE[id] == 0) {
				int x, y;
				scanf("%d%d", &x, &y);
	    		a[id].pb(mp(x, y));
	    		a[id].pb(mp(x, y));
    		}
    		else {
    			rep(i, szE[id])
    				e[id].pb(read());
    			rep(j, 2) a[id].pb(mp(oo, oo));
    		}
    	}


    	dfs(1);
    	int res = oo;
    	rep(j, 2) res = min(res, a[1][j].fr*a[1][j].sc);
    	printf("%d\n", res);
    }
    return 0;
}
