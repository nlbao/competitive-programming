#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

bool ok(int n) {
    int m = 0;
    int a[10];
    while (n > 0) {
        a[++m] = n%10;
        n /= 10;
    }
    int i = 1, j = m;
    while (i < j) {
        if (a[i] != a[j]) return false;
        ++i;    --j;
    }
    return true;
}

int main()  {
    int res = -1;
    forD(i, 999, 100) {
        if (i*999 <= res) break;
        forD(j, 999, i) {
            int k = i*j;
            if (k <= res) break;
            if ((ok(k)) && (k > res)) res = k;
        }
    }
    printf("%d", res);
    return 0;
}
