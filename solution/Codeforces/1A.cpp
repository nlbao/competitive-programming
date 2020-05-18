#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("1A.inp","rt",stdin);
    long long n, m, a;
    scanf("%I64d%I64d%I64d", &n, &m, &a);
    printf("%I64d", ((n-1)/a+1)*((m-1)/a+1));
    getch();
}
