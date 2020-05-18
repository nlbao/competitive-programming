#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;
typedef pair<int, pii> piii;

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

const int MAX_N = 1003;
const int MAX_C = 104;
const int oo = 1000000000;

class hmax {
public:
	bool operator() (const piii &a, const piii &b) const {
		if (a.fr != b.fr) return a.fr > b.fr;
		return a.sc.sc < b.sc.sc;
	}
};

int n, m, fuel_capacity;
vii e[MAX_N];
int price[MAX_N], szE[MAX_N];
int d[MAX_N][MAX_C];
bool visited[MAX_N][MAX_C];
priority_queue<piii, vector<piii>, hmax> h;


int dijkstra(int s, int t) {
	while (!h.empty()) h.pop();
	rep(u, n)
		rep(i, fuel_capacity+2) {
			d[u][i] = oo;
			visited[u][i] = false;
		}
	d[s][0] = 0;
	h.push(mp(0, mp(s, 0)));

	while (!h.empty()) {
		int value = h.top().fr, u = h.top().sc.fr, x = h.top().sc.sc;
		h.pop();
		if (value > d[u][x] || visited[u][x]) continue;
		visited[u][x] = true;
		if (u == t) break;

		if (x < fuel_capacity-1) {
			int y = x+1, cost = value + price[u];
			if (cost < d[u][y]) {
				d[u][y] = cost;
				h.push(mp(d[u][y], mp(u,y)));
			}
		}

		rep(i, szE[u]) {
			int v = e[u][i].sc, w = e[u][i].fr;
			int y = x-w;
			if (y >= 0 && value < d[v][y]) {
				d[v][y] = value;
				h.push(mp(d[v][y], mp(v,y)));
			}
		}
	}
	return d[t][0];
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("tank.in", "r", stdin);
    freopen("F.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d", &price[i]);
    rep(i, m) {
    	int w, x, y;
    	scanf("%d%d%d", &x, &y, &w);
    	e[x].pb(mp(w, y));
    	e[y].pb(mp(w, x));
    }
    rep(i, n) szE[i] = sz(e[i]);

    int nQ = read();
    rep(qid, nQ) {
    	int s, t;
    	scanf("%d%d%d", &fuel_capacity, &s, &t);
    	++fuel_capacity;
    	int res = dijkstra(s, t);
    	if (res == oo) printf("impossible\n");
    	else printf("%d\n", res);
    }
    return 0;
}