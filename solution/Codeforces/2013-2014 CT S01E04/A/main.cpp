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

const int MAX_N = 1000006;

int a[6][4] = { 0, 0, 1, 2,
                0, 0, 2, 1,
                0, 1, 0, 2,
                0, 1, 2, 0,
                0, 2, 0, 1,
                0, 2, 1, 0 };

int f[6][MAX_N][3];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    rep(id, 6) {
        rep(i, 3) f[id][0][i] = 0;
        int x = a[id][1], y = a[id][2], z = a[id][3];
        foru(i, 1, MAX_N) {
            rep(j, 3) f[id][i][j] = f[id][i-1][j];
            if (i == 1) ++f[id][i][x];
            else if (i == 2) ++f[id][i][y];
            else if (i == 3) ++f[id][i][z];
            else {
                int t = 3-y-z;
                x = y;
                y = z;
                z = t;
                ++f[id][i][z];
            }
        }
    }


    int nTest = read();
    rep(test_id, nTest) {
        int b[3], n = 0, res = 0;
        rep(i, 3) {
            scanf("%d", &b[i]);
            n += b[i];
        }
        if (n == 1) res = 1;
        else if (n == 2) {
            if (b[0] < 2 && b[1] < 2 && b[2] < 2) res = 2;
            else res = 0;
        }
        else
            rep(id, 6) {
                bool ok = true;
                rep(i, 3) ok = ok && (b[i] == f[id][n][i]);
                if (ok) ++res;
            }
        printf("%d\n", res);

    }
    return 0;
}
