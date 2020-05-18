#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (ll i = a; i <= b; ++i)
#define forD(i, a, b) for (ll i = a; i >= b; --i)
#define ll long long

int gcd(ll x, ll y) {
    if ((x == 0) or (y == 0)) return (x+y);
    else return gcd(y,x%y);
}

int main()  {
    ll res = 1;
    forI(i, 2, 20)
        res = (res*i)/gcd(res,i);
    printf("%d\n", res);
    return 0;
}
