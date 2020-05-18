/*
    ID: storm59061
    LANG: C++
    TASK: castle
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

const int MAX_N = 55;
const int dx[4] = {0, -1, 0, +1};
const int dy[4] = {-1, 0, +1, 0};

int n, m, nC;
int a[MAX_N][MAX_N], c[MAX_N][MAX_N], f[MAX_N*MAX_N];


bool ok(int x, int y) {
    return !(x < 1 || x > m || y < 1 || y > n);
}

bool check_adj(int value, int i) {
    return (value&(1<<i)) == 0;
}

void enter() {
    scanf("%d%d",&n,&m);
    foru(i,1,m)
        foru(j,1,n)
            scanf("%d",&a[i][j]);
}

void dfs(int x, int y) {
    if (!ok(x,y)) return;
    //cout << nC << "         " << x << " " << y << endl;
    c[x][y] = nC;
    ++f[nC];
    rep(i,4) {
        int xx = x+dx[i], yy = y+dy[i];
        if (c[xx][yy] == 0 && check_adj(a[x][y],i))
            dfs(xx, yy);
    }
}

void find_components() {
    nC = 0;
    fill(c,0);
    foru(i,1,m)
        foru(j,1,n)
            if (c[i][j] == 0) {
                f[++nC] = 0;
                dfs(i,j);
            }
}

void solve() {
    int maxF = 0;
    foru(i,1,nC) maxF = max(maxF, f[i]);
    printf("%d\n%d\n",nC,maxF);

    maxF = 0;
    int x = -1, y = -1;
    char d = 'F';
    foru(j,1,n)
        ford(i,m,1)
            foru(k,1,2) {
                if (check_adj(a[i][j],k)) continue;
                int ii = i+dx[k], jj = j+dy[k];
                if (!ok(ii,jj) || c[i][j] == c[ii][jj]) continue;
                if (f[c[i][j]]+f[c[ii][jj]] > maxF) {
                    maxF = f[c[i][j]]+f[c[ii][jj]];
                    x = i, y = j;
                    d = k==1?'N':'E';
                }
            }
    printf("%d\n%d %d %c\n",maxF,x,y,d);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
#endif
    enter();
    find_components();
    solve();
    return 0;
}
