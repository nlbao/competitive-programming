#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

int main()  {
    ll res = 2, f1 = 1, f2 = 2, f3 = 0, limit = 4000001;
    while (f3 < limit)  {
        f3 = f1+f2;
        if (f3%2 == 0) res += f3;
        f1 = f2;    f2 = f3;
    }
    printf("%d", res);
    return 0;
}
