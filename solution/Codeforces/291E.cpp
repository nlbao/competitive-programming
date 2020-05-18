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
typedef pair<int, int> pi;
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

const int MAX_N = 300005;
const ll BASE = 10007LL;

int n = 0, res = 0, len;
ll p;
vi e0[MAX_N], e[MAX_N];
string s[MAX_N];
ll h[MAX_N];
int sz[MAX_N], d[MAX_N], f[MAX_N][20];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void add_edge(int u, int v, char x) {
    e[u].pb(v);
    f[v][0] = u;
    d[v] = d[u]+1;
    h[v] = h[u]*BASE + ll(x);
}

void init(int num, int pos) {
    int u = ++n;
    foru(i,1,n)
        if (d[u]-(1<<i) < 0) break;
        else f[u][i] = f[f[u][i-1]][i-1];

    if (pos < sz[num]-1) {
        add_edge(u,n+1,s[num][pos+1]);
        init(num,pos+1);
        return;
    }

    for(int i = 0, c = size(e0[num]); i < c; ++i) {
        int des = e0[num][i];
        add_edge(u,n+1,s[des][0]);
        init(des,0);
    }
}

ll get_root(int u) {
    if (d[u] <= len) return -1;
    int k = d[u]-len, v = u;
    ford(i,20,0)
        if (d[v]-(1<<i) >= k)
            v = f[v][i];
    return v;
}

ll get_h(int i, int j) {
    return h[j] - h[i-1]*p;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("291E.in", "r", stdin);
    freopen("291E.out", "w", stdout);
#endif
    int m = read();
    foru(i,2,m) {
        int x = read();
        e0[x].pb(i);
        getline(cin, s[i]);
        s[i].erase(0,1);
        sz[i] = size(s[i]);
    }

    getline(cin, s[0]);
    len = size(s[0]);
    p = 1;
    ll tmp = 0;
    rep(i,len) {
        p = p*BASE;
        tmp = tmp*BASE + ll(s[0][i]);
    }

    s[1] = "";
    sz[1] = 0;
    fill(f,0);
    fill(h,0);
    d[1] = 1;
    init(1,0);

    foru(u,1,n) {
        int v = get_root(u);
        if (v > 0 && h[u]-h[v]*p == tmp) ++res;
    }
    cout << res;
    return 0;
}
