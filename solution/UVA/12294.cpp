#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <functional>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a, x) memset((a), (x), sizeof(a))
#define foreach(it, x) for (typeof((x).begin()) (it) = (x).begin(); (it) != (x).end(); ++(it))
//#define for_each(it, x) for (auto (it) = (x).begin(); (it) != (x).end(); ++(it))

int read()  {   int x;  scanf("%d", &x);    return x;   }
int readln()  {   int x;  scanf("%d\n", &x);    return x;   }


const int MAX_N = 1120;
const int MAX_P = 120;
const int MAX_W = 8;
const double oo = 1e9;
const double EPSILON = 1e-7;


int n;
int power;
int p[MAX_N][2];
double t[MAX_N][2];
int w[MAX_N][2];
double f[2][MAX_P][MAX_W];


double cost(int i, int power) {
    if (power < p[i][1])
        return oo;
    else if (power > p[i][2])
        return t[i][2];
    return t[i][2] + double(p[i][2] - power) / double(p[i][2] - p[i][1]) * (t[i][1] - t[i][2]);
}


double solve() {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < MAX_P; ++j)
            for (int k = 0; k < MAX_W; ++k)
                f[i][j][k] = oo;
    f[0][power][0] = 0;

    int t = 0;
    for (int turn = 1; turn <= n; ++turn) {
        int tt = 1-t;
        for (int x = 0; x < MAX_P; ++x)
            for (int y = 0; y < MAX_W; ++y)
                f[tt][x][y] = oo;

        for (int x = 0; x < MAX_P; ++x) {
            double tmp = cost(turn, x);
//            cout << " xxx " <<  tmp << endl;
            if (fabs(tmp - oo) < EPSILON) continue;
            for (int y = 0; y < MAX_W; ++y) {
                if (fabs(f[t][x][y] - oo) < EPSILON) continue;

                //cout << fixed << setprecision(2) << "   " << turn-1 << " " << x << " " << y << " " << f[t][x][y] << "\n";

                for (int j = 0; j <= min(MAX_W-1, y + w[turn][2]); ++j) {
                    int k1 = min(MAX_P-1, (x + w[turn][1])*(1<<j));
                    int k2 = min(MAX_W-1, y + w[turn][2] - j);
                    f[tt][k1][k2] = min(f[tt][k1][k2], f[t][x][y] + tmp);
                }
            }
        }
        t = tt;
    }

    double ans = oo;
    for (int x = 0; x < MAX_P; ++x)
        for (int y = 0; y < MAX_W; ++y)
            ans = min(ans, f[t][x][y]);

    return ans;
}


int main() {
//    freopen("H.in", "r", stdin);
//    freopen("H.out", "w", stdout);

    while (true) {
        n = read();
        power = read();
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) {
            p[i][1] = read();
            p[i][2] = read();
            t[i][1] = read();
            t[i][2] = read();
            w[i][1] = read();
            w[i][2] = read();

        }
        double ans = solve();
        if (fabs(ans - oo) < EPSILON) printf("Impossible\n");
        else cout << fixed << setprecision(2) << ans << "\n";
    }
    return 0;
}
