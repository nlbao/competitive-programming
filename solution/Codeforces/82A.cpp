#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    freopen ( "82A.inp", "rt", stdin );
    int n;
    scanf ( "%d", &n );
    int m = 0;
    while ( 5*m*(m+1)/2 < n ) ++m;
    --m;
    int t = (n-5*m*(m+1)/2)/(m+1);
    printf ( "%d\n", t );
    if ( (n-5*m*(m+1)/2)%(m+1) != 0 ) t++;
    printf ( "%d\n", t );
    switch (t)
    {
        case 1: printf ( "Sheldon" ); break;
        case 2: printf ( "Leonard" ); break;
        case 3: printf ( "Penny" ); break;
        case 4: printf ( "Rajesh" ); break;
        case 5: printf ( "Howard" ); break;  
    }
    getch();
}
