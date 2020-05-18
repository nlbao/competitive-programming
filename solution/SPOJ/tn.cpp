// Problem Set : UVA
// Problem ID : 11426
// Author  : Xavier
// Date  : 2008.5.23
// Time Compl : O(N^0.5)
// Mem Compl : O(N)
// Method  : Number Theory
// State  : Accepted
// Note  :

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define LONG long long
#define SZ(x) ((x).size())
#define PB(x) push_back(x)
#define SQR(x) ((x)*(x))
#define FOR(x,y) for(x=0;x<y;++x)
#define EPS 1e-8
#define INF 0x3fffffff

#define MaxN 5000000
#define MaxP 500000

using namespace std;

LONG phi[MaxN];
int prime[MaxP], pnum;

void GenPhi()
{
 int i,j,k; pnum = 0;
 memset( phi, 0, MaxN*sizeof( phi[0] ));
 phi[1] = 1;
 for( i = 2; i < MaxN; i ++ ) if( ! phi[i] )
 {
  prime[pnum++] = i;
  for( j = i; j < MaxN; j += i )
  {
   if( !phi[j] ) phi[j] = j;
   phi[j] = phi[j]/i*(i-1);
  }
 }

 for( i = 3; i < MaxN; i ++ ) phi[i] += phi[i-1];
 phi[1] = 0;
}

inline LONG sum( int a, int b ) // (b..a]
{
 return (LONG)(a + b + 1) * ( a - b ) / 2;
}

int main ()
{
 GenPhi ();
   for(int i = 1; i < 10; ++i) cout << phi[i] << " ";
   cout << endl;

 return 0;
 int N ;
 while( 1 == scanf("%d", &N) && N )
 {
  if( N == 2 ) {
   printf("1\n");
   continue;
  }
  LONG ans = 0;
  int L = (int)floor(sqrt(N)), rL = N/L;
  for( int i = 3, last = N/2; i <= L; ++ i )
  {
   int now = N/i;
   ans += phi[i-1] * sum( last, now );
   last = now;
  }
  for( int i = 1; i <= rL; ++ i ) ans += phi[N/i] * i;
  printf("%I64d\n", ans );
 }
return 0;
}
