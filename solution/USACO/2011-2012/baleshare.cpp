#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

const int MAX_N = 21;
const int MAX_A = 2010;
const int oo = 1000000;

int f[MAX_N][MAX_A][MAX_A];

int main() {
    freopen("baleshare.in", "r", stdin);
    freopen("baleshare.out", "w", stdout);
    int n;
    int a[MAX_N];
    scanf("%d", &n);
    forI(i, 0, n-1) scanf("%d", &a[i]);

    int res = oo;

    forI(j, 0, MAX_A)
        forI(k, 0, MAX_A) f[0][j][k] = oo;
    f[0][a[0]][0] = f[0][0][a[0]] = 0;
    int t = 0;
    forI(i, 1, n-1) {
        forI(j, 0, MAX_A)
            forI(k, 0, MAX_A) {
                f[i][j][k] = min(oo, f[i-1][j][k]+a[i]);
                if (j >= a[i])
                    f[i][j][k] = min(f[i][j][k], f[i-1][j-a[i]][k]);
                if (k >= a[i])
                    f[i][j][k] = min(f[i][j][k], f[i-1][j][k-a[i]]);
            }
    }
    printf("%d\n", f[n-1][100][100]);
    forD(j, MAX_A, 0)
        forD(k, j, 0)
            if (f[n-1][j][k] <= k) res = j;
    printf("%d\n", res);
    return 0;
}
