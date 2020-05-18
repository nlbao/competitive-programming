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

const int MAX_W = 13;
const int MAX_N = MAX_W*MAX_W;
const double eps = 1.e-8;

int W, H, D, n;

int id[MAX_W][MAX_W];
double value[MAX_N];
double a[MAX_N][MAX_N], res[MAX_W][MAX_W];

void enter() {
    n = 0;
    foru(x, 1, H)
        foru(y, 1, W) {
            id[x][y] = ++n;
            scanf("%lf", &value[n]);
        }

    fill(a, 0);
    foru(x, 1, H)
        foru(y, 1, W) {
            int u = id[x][y];
            foru(i, 1, H)
                foru(j, 1, W)
                    if (abs(x-i)+abs(y-j) <= D) {
                        a[u][id[i][j]] = 1;
                        ++a[u][n+1];
                    }
            a[u][n+1] *= value[u];
        }
}

int find_non0_row(int col) {
    int res = min(col+1, n);
    foru(i, col+1, n)
        if (abs(a[i][col]) > abs(a[res][col])+eps)
            res = i;
    return res;
}

void swap_row(int x, int y) {
    foru(i,1,n+1) swap(a[x][i], a[y][i]);
}

void fix_col(int col) {
    double x = a[col][col];
    foru(i, col+1, n) {
        double t = a[i][col]/x;
        foru(j, col, n+1)
            a[i][j] -= t*a[col][j];
        a[i][col] = 0;
    }
}

void solve() {  //using Gauss's algorithm
    foru(i, 1, n) {
        if (abs(a[i][i]) < eps) {
            int ii = find_non0_row(i);
            swap_row(i, ii);
        }
        if (a[i] != 0)
            fix_col(i);

    }

    ford(i, n, 1) {
        double s = 0;
        foru(j, i+1, n)
            s += value[j]*a[i][j];
        value[i] = (a[i][n+1]-s)/a[i][i];
    }

    foru(i, 1, H)
        foru(j, 1, W)
            res[i][j] = value[id[i][j]];
}


void print_res() {
    foru(i, 1, H) {
        foru(j, 1, W)
            printf("%8.2lf", res[i][j]+1e-8);
        printf("\n");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("4741.in", "r", stdin);
    freopen("4741.out", "w", stdout);
#endif
    for(int test_id = 1; ; ++test_id) {
        scanf("%d%d%d", &W, &H, &D);
        if (W == 0) break;
        if (test_id > 1) printf("\n");
        enter();
        solve();
        print_res();
    }
    return 0;
}
