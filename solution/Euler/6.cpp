#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define forI(i, a, b) for (ll i = a; i <= b; ++i)
#define forD(i, a, b) for (ll i = a; i >= b; --i)
#define ll long long

int main()  {
    ll n = 100;
    ll s1 = n*(n+1)/2;
    ll s2 = (2*n+1)*(n+1)*n/6;
    printf("%d\n", s1*s1-s2);
    return 0;
}
