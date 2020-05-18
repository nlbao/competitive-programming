#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
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

int n, k;
vii e[MAX_N];
bool black[MAX_N];
int p[MAX_N], w[MAX_N];
ll f[MAX_N];

void dfs(int u) {
    int sz = size(e[u]);
    rep(i, sz) {
        int v = e[u][i].sc;
        if (p[v] < 0) {
            p[v] = u;
            w[v] = e[u][i].fr;
            dfs(v);
        }
    }

    f[u] = 0;
    int maxW = 0;
    bool is_black = false;
    rep(i, sz) {
        int v = e[u][i].sc;
        if (p[v] == u && black[v]) {
            is_black = true;
            f[u] += f[v] + w[v];
            maxW = max(maxW, w[v]);
        }
    }

    if (!black[u]) {
        black[u] = is_black;
        f[u] -= maxW;
        if (maxW) w[u] = min(w[u], maxW);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    rep(i, n-1) {
        int x, y ,z;
        scanf("%d%d%d", &x, &y, &z);
        e[x].pb(mp(z,y));
        e[y].pb(mp(z,x));
    }
    fill(black, false);
    rep(i, k) {
        int x = read();
        black[x] = true;
    }

    rep(i, n) p[i] = -1;
    p[0] = 0;
    dfs(0);

    cout << f[0] << endl;
    return 0;
}
