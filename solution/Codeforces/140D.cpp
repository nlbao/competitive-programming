#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forI(i, a, b) for(int i = a; i <= b; ++i)
#define forD(i, a, b) for(int i = a; i >= b; --i)
#define ll long long;

const int MAX_N = 110;

int main() {
    freopen("140D.in", "r", stdin);
    freopen("140D.out", "w", stdout);
    int n;
    int a[MAX_N];
    scanf("%d", &n);
    forI(i, 0, n-1) scanf("%d", &a[i]);

    sort(a, a+n);
    int res = 0, sum = 10, c = 0;
    forI(i, 0, n-1) {
        sum += a[i];
        if (sum > 720) break;
        if (sum > 360) res += sum-360;
        ++c;
    }
    printf("%d %d\n", c, res);
    return 0;
}
