#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX_N = 20;
const int MAX_W = 100000;

int main()
{
    // freopen("1005.inp","rt",stdin);
    int n;
    int w[MAX_N];
    int sumW[1];
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&w[i]);
    int minRes = (MAX_W+1)*MAX_N;
    for (int i = 0; i <= (1<<(n-1))-1; i++)
    {
        sumW[0] = sumW[1] = 0;
        for (int j = 1; j <= n; j++) 
            sumW[(i>>(j-1))&1] += w[j];
        minRes = min(minRes, abs(sumW[0]-sumW[1]));
    }
    printf("%d",minRes);
    getch();
    return 0;
}
