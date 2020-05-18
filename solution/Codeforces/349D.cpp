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

const int MAX_N = 100005;
const ll oo = 1000000000000000000LL;

int n;
vi e[MAX_N];
int nChild[MAX_N], p[MAX_N], a[MAX_N];
ll f[MAX_N], g[MAX_N], x[MAX_N];

ll gcd(ll a, ll b) {
    if (a == 0 || b == 0) return a+b;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return (a/gcd(a,b))*b;
}

void dfs(int u) {
    nChild[u] = 0;
    g[u] = 1;

    int szE = sz(e[u]);
    rep(i, szE) {
        int v = e[u][i];
        if (p[v] != 0) continue;
        p[v] = u;
        dfs(v);
        ++nChild[u];
        g[u] = lcm(g[u], f[v]);
    }

    x[u] = (nChild[u] > 0)?oo:a[u];
    if (g[u] < 1) x[u] = 0;
    rep(i, szE) {
        int v = e[u][i];
        if (p[v] != u) continue;
        if (x[u] < 1) break;
        x[u] = min(x[u], (f[v]*x[v])/g[u]);
    }

    f[u] = (nChild[u] > 0)?(g[u]*nChild[u]):1;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("349D.in", "r", stdin);
    freopen("349D.out", "w", stdout);
#endif
    scanf("%d",&n);
    ll s = 0;
    foru(i,1,n) {
        read(a[i]);
        s += a[i];
    }
    rep(i, n-1) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].pb(y);
        e[y].pb(x);
    }

    fill(p, 0);
    p[1] = -1;
    dfs(1);
    cout << s - f[1]*x[1] << endl;
    return 0;
}
