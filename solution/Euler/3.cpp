#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

int main()  {

    forI(i, 100, 999)
        forI(j, 100, 999) {
            int k = i*j;
            if ((ok(k) == 0) && (k > res)) res = k;
    }

    printf("%I64d", n);
    return 0;
}
