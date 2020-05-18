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

const int MAX_N = 5003;
const int oo = 2000000000;

struct edge {
    int v, link;
    int c, f;
    edge (int vv, int cc, int l) {
        v = vv;     link = l;
        c = cc;     f = 0;
    }
};


int n, m, s, t;
int szE[MAX_N], d[MAX_N], q[MAX_N], pos[MAX_N];
vector<edge> e[MAX_N];


void add_edge(int u, int v, int c) {
    e[u].pb(edge(v, c, szE[v]++));
    e[v].pb(edge(u, 0, szE[u]++));
}


bool bfs_flow() {
    fill(d, 0);
    int l, r;
    l = r = d[s] = 1;
    q[1] = s;
    while (l <= r) {
        int u = q[l++];
        rep(i, szE[u]) {
            int v = e[u][i].v;
            if (!d[v] && e[u][i].f < e[u][i].c) {
                d[v] = d[u] + 1;
                if (v == t) return true;
                q[++r] = v;
            }
        }
    }
    return false;
}


int dfs_flow(int u, int flow) {
    if (u == t || flow == 0) return flow;
    for ( ; pos[u] < szE[u]; ++pos[u]) {
        int i = pos[u], v = e[u][i].v;
        if (d[v] == d[u]+1) {
            int delta = dfs_flow(v, min(flow, e[u][i].c-e[u][i].f));
            if (delta) {
                e[u][i].f += delta;
                e[v][e[u][i].link].f -= delta;
                return delta;
            }
        }
    }
    d[u] = -1;
    return 0;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("FASTFLOW.in", "r", stdin);
    freopen("FASTFLOW.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    s = 1;
    t = n;
    fill(szE, 0);
    rep(id, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        if (u == v) continue;
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    ll res = 0;
    while (bfs_flow()) {
        fill(pos, 0);
        for (ll delta = 1; delta > 0; )
            res += (delta = dfs_flow(s, oo));
    }
    cout << res << endl;

    return 0;
}
