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

const int MAX_N = 222;

int n, nX, nY;
int c[MAX_N][MAX_N];
int szE[MAX_N], d[MAX_N], matchX[MAX_N], matchY[MAX_N];
vi e[MAX_N];
queue<int> q;

bool bfs() {
    while (!q.empty()) q.pop();
    foru(i, 1, n)
        if (matchX[i] == 0) {
            d[i] = 1;
            q.push(i);
        }
        else d[i] = 0;
    d[0] = 0;

    while (!q.empty()) {
        int u = q.front();  q.pop();
        rep(i, szE[u]) {
            int v = e[u][i], y = matchY[v];
            if (!d[y]) {
                d[y] = d[u]+1;
                if (!y) return true;
                q.push(y);
            }
        }
    }
    return false;
}


bool dfs(int u) {
    if (!u) return true;
    rep(i, szE[u]) {
        int v = e[u][i], y = matchY[v];
        if (d[y] == d[u]+1 && dfs(y)) {
            matchX[u] = v;
            matchY[v] = u;
            return true;
        }
    }
    d[u] = 0;
    return false;
}


bool check(int value) {
    foru(i, 1, nX) e[i].clear();
    foru(u, 1, nX) {
        foru(v, 1, nY)
            if (c[u][v] <= value)
                e[u].pb(v);
        szE[u] = sz(e[u]);
    }

    int res = 0;
    fill(matchX, 0);
    fill(matchY, 0);
    while (bfs())
        foru(i, 1, nX)
            if (matchX[i] == 0 && dfs(i))
                ++res;
    return (res == n);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("ASSIGN1.in", "r", stdin);
    freopen("ASSIGN1.out", "w", stdout);
#endif
    int res = 0;
    scanf("%d", &n);
    nX = nY = n;
    foru(i, 1, n)
        foru(j, 1, n) {
            scanf("%d", &c[i][j]);
            res = max(res, c[i][j]);
        }

    int l = 0, r = res;
    while (l <= r) {
        int mid = (l+r)>>1;
        if (check(mid) == true) {
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    printf("%d\n", res);

    return 0;
}
