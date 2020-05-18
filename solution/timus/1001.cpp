#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>

const int MAX_N = 1000000;

using namespace std;

int main()
{
    freopen("1001.inp","rt",stdin);
    int n = 0;
    double *pA = new double[MAX_N];
    double x;
    while (scanf("%lf",&x) != EOF)
          *(pA+(++n)) = x;
    for (int i = n; i >= 1; i--)
        printf("%.4lf\n",sqrt(*(pA+i)));
    getch();
    return 0;
}
