#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fab(i, a, b) for (int i = a; i <= b; ++i)
#define fba(i, b, a) for (int i = b; i >= a; --i)
#define ll long long

const int MAX_N = 1000010;

int n;
int a[MAX_N], p[MAX_N], f[MAX_N];

int main() {
    freopen("67D.in", "r", stdin);
    freopen("67D.out", "w", stdout);
    scanf("%d", &n);
    forI(i, 0, n-1) {
        int j;
        scanf("%d", &j);
        p[j-1] = i;
    }
    forI(i, 0, n-1) {
        scanf("%d", &a[i]);
        a[i] = p[a[i]-1];
    }

    int top = 0;
    f[0] = 0;
    forI(i, 1, n-1) {
        int l = 0, r = top, t = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (a[f[mid]] >= a[i]) {
                t = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if (t == top) ++top;
        f[++t] = i;
    }
    printf("%d\n", ++top);
    return 0;
}
