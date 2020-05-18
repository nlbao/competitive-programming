/*
    ID: storm59061
    LANG: C++
    TASK: maze1
*/
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

const int MAX_N = 204;
const int oo = MAX_N*(MAX_N+4);
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};

int m, n;
char s[MAX_N][MAX_N];
int d[MAX_N][MAX_N];

bool ok(int i, int j) {
    return !(i < 0 || j < 0 || i >= m || j >= n);
}

bool is_empty(int i, int j) {
    return ok(i,j) && s[i][j] == ' ';
}

bool is_exit(int x, int y) {
    rep(k,4) {
        int i = x+dx[k], j = y+dy[k];
        if (is_empty(i,j) && (i == 0 || j == 0 || i == m-1 || j == n-1))
            return true;
    }
    return false;
}

void bfs(int x, int y) {
    d[x][y] = 1;
    queue<pii> q;
    q.push(mp(x,y));
    while (!q.empty()) {
        x = q.front().fr, y = q.front().sc;
        q.pop();
        rep(k,4) {
            int i = x+2*dx[k], j = y+2*dy[k];
            if (is_empty(x+dx[k], y+dy[k]) && is_empty(i,j) && d[x][y]+1 < d[i][j]) {
                d[i][j] = d[x][y]+1;
                q.push(mp(i,j));
            }
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    m = 2*m + 1;
    n = 2*n + 1;
    gets(s[0]);
    rep(i,m) {
        gets(s[i]);
        //cout << s[i] << endl;
    }
    int res = 0;
    vii v;
    for(int i = 1; i < m; i += 2)
        for(int j = 1; j < n; j += 2)
            if (is_empty(i,j)) {
                d[i][j] = oo;
                if (is_exit(i,j)) v.pb(mp(i,j));
            }
    rep(i,size(v)) bfs(v[i].fr, v[i].sc);
    rep(i,m)
        rep(j,n)
            res = max(res, d[i][j]);
    printf("%d\n",res);
    return 0;
}
