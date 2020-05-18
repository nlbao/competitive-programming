#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)

int main()  {
    int n, res = 0;
    scanf("%d", &n);
    forI(i, 3, n-1)
        if ((i%3 == 0) || (i%5 == 0)) res += i;
    printf("%d", res);
    return 0;
}
