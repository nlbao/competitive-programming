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

const int MAX_N = 555;

int n, m, pleft, pright;
vii e[MAX_N];
int sz[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int find_left(int u) {
    int l = 0, r = sz[u]-1, t = -1;
    while (l <= r) {
        int mid = (l+r)>>1;
        if (e[u][mid].fr < pleft) {
            t = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return t;
}

int find_right(int u) {
    int l = 0, r = sz[u]-1, t = sz[u];
    while (l <= r) {
        int mid = (l+r)>>1;
        if (e[u][mid].fr > pright) {
            t = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return t;
}


void dfs(int u) {
    //int id = e[u][i].fr,
    //if (pleft <= id && id <= pright) continue;
    ok[u] = false;
    int k = find_left(u);
    for(int i = 0; i <= k; ++i) {
        int v = e[u][i].sc;
        if (ok[v]) dfs(v);
    }
    for(int i = max(k+1,find_right(u)); i < sz[u]; ++i) {
        int v = e[u][i].sc;
        if (ok[v]) dfs(v);
    }
}

int solve() {
    int c = 0;
    fill(ok,true);
    foru(i,1,n)
        if (ok[i]) {

            ++c;
            dfs(i);
        }
    return c;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("292D.in", "r", stdin);
    freopen("292D.out", "w", stdout);
#endif
    read(n);
    read(m);
    foru(i,1,m) {
        int x = read(), y = read();
        e[x].pb(mp(i,y));
        e[y].pb(mp(i,x));
    }
    foru(i,1,n) sz[i] = size(e[i]);

    int k = read();
    rep(i,k) {
        read(pleft);
        read(pright);
        printf("%d\n",solve());
    }
    return 0;
}
