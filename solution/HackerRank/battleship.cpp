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
#include <time.h>
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

const int MAX_N = 13;
const int nShip = 10;
const int dx[4] = {-1,0,+1,0};
const int dy[4] = {0,+1,0,-1};
pii ship_size[nShip] = {{1,1}, {1,1}, {2, 1}, {1, 2}, {3, 1}, {1, 3}, {4, 1}, {1, 4}, {5, 1}, {1, 5}};

int n = 10, m = 10;
char board[MAX_N][MAX_N];
int a[MAX_N][MAX_N];
int ship_count[nShip] = {2, 2, 2, 2, 1, 1, 1, 1, 1, 1};


bool enter() {
    char s[100];
    scanf("%s",&s);
    if (s[0] == 'I') return false;
    n = atoi(s);
    rep(i,n) scanf("%s",&board[i]);
    return true;
}

bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void output(int x, int y) {
    printf("%d %d\n",x,y);
}

bool put_ship(int x, int y, int k) {
    int lx = ship_size[k].fr-1, ly = ship_size[k].sc-1;
    if (!inside(x+lx, y+ly) || ship_count[k] < 1) return false;
    foru(i, x, x+lx)
        foru(j, y, y+ly)
            if (board[i][j] == 'm' || board[i][j] == 'd')
                return false;
    foru(i, x, x+lx)
        foru(j, y, y+ly)
            if (board[i][j] == '-') ++a[i][j];
    return true;
}

int dist(int x, int y) {
    int d = min(min(x,n-x),(y,m-y));
    rep(i,n)
        if (board[i][y] != '-')
            d = min(d,abs(i-x));
    rep(i,m)
        if (board[x][i] != '-')
            d = min(d,abs(i-y));
    return d;
}

void new_ship(int k) {
    srand (time(NULL));
    bool ok;
    int x, y;
    do {
        x = rand()%n, y = rand()%m;
        ok = put_ship(x, y, k);
    } while (!ok);

    int lx = ship_size[k].fr-1, ly = ship_size[k].sc-1;
    if (lx == ly) printf("%d %d\n",x,y);
    else printf("%d %d:%d %d\n",x,y,x+lx,y+ly);
    foru(i,x,x+lx)
        foru(j,y,y+ly)
            board[i][j] = 'd';
}

void init() {
    srand (time(NULL));
    rep(i,n)
        rep(j,m) board[i][j] = '-';
    bool ok[MAX_N];
    fill(ok,true);
    rep(i,nShip)
        if (i < 4 || ok[i]) {
            ok[i] = ok[i^1] = false;
            if (rand()%2 == 0) new_ship(i);
            else new_ship(i^1);
        }
}

bool choose_by_ship() {
    int resX = -1, resY = -1, maxH = -1;
    ford(k,nShip-1,2) {
        int lx = ship_size[k].fr-1, ly = ship_size[k].sc-1;
        rep(x,n)
            rep(y,m)
                if (put_ship(x, y, k)) {
                    int sumH = 0;
                    foru(i,x,x+lx)
                        foru(j,y,y+ly)
                            sumH += int(board[i][j] == 'h');
                    if (sumH <= maxH) continue;

                    int tx = resX, ty = resY;
                    if (lx == 0) {
                        if (board[x][y] == '-' && board[x][y+1] == 'h') {
                            resX = x;
                            resY = y;
                        }
                        foru(i,y+1,y+ly)
                            if (board[x][i] == '-' && board[x][i-1] == 'h') {
                                resX = x;
                                resY = i;
                            }
                    }
                    else {
                        if (board[x][y] == '-' && board[x+1][y] == 'h') {
                            resX = x;
                            resY = y;
                        }
                        foru(i,x+1,x+lx)
                            if (board[i][y] == '-' && board[i-1][y] == 'h') {
                                resX = i;
                                resY = y;
                            }
                    }
                    if (resX != tx && resY != ty) maxH = sumH;
                }
    }
    if (maxH < 1) return false;
    output(resX, resY);
    return true;
}

bool choose_around_h() {
    rep(i,n)
        rep(j,m)
            if (board[i][j] == 'h')
                rep(k,4) {
                    int x = i+dx[k], y = j+dy[k];
                    if (inside(x,y) && board[x][y] == '-') {
                        output(x, y);
                        return true;
                    }
                }
    return false;
}

bool choose_by_count() {
    fill(a,0);
    rep(i,n)
        rep(j,m)
            rep(k,nShip)
                put_ship(i, j, k);

    int x, y, maxA = -1;
    rep(i,n)
        rep(j,m)
            if (a[i][j] > maxA) {
                maxA = a[i][j];
                x = i;
                y = j;
            }
    if (maxA < 1) return false;
    output(x, y);
    return true;
}

bool choose_by_dist() {
    int x = 0, y = 0, d = -1;
    rep(i,n)
        rep(j,m)
            if (board[i][j] == '-') {
                int t = dist(i,j);
                if (t <= d) continue;
                d = t;
                x = i;
                y = j;
            }
    if (d < 1) return false;
    output(x, y);
    return true;
}

bool choose_randomly() {
    int i, j;
    do {
        i = rand()%n;
        j = rand()%m;
    } while (board[i][j] != '-');
    output(i, j);
}

bool choose_even() {
    rep(i,n)
        rep(j,m)
            if (board[i][j] == '-' && (i+j)%2 == 0) {
                output(i, j);
                return true;
            }
    return false;
}

void solve() {
    if (choose_by_ship()) return;
    if (choose_around_h()) return;
    if (choose_by_count()) return;
    //if (choose_by_dist()) return;
    //if (choose_even()) return;
    //srand (time(NULL));
    choose_randomly();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("battleship.in", "r", stdin);
    freopen("battleship.out", "w", stdout);
#endif
    if (!enter()) init();
    else solve();
    return 0;
}
