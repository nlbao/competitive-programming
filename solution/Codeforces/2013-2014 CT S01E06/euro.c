#include <stdio.h>


#define NUM 6
#define MAX 100


int coins[NUM];


/*** Computes for all transactions in the range of 1 till MAX the minimal number
     of coins needed for that transaction and return the sum of these numbers. ***/
void solve (void)
{
  int i,j;       /* loop indices */
  int* d;        /* the array we are going to fill with the amount of coins needed for that value*/
  int s = 1;     /* our current step number */
  int a,b;       /* split of step number (a + b = s) */
  int f = -1;    /* boolean control to check whether d is completely filled */
  int sum = 0;   /* the resulting sum (average = sum / 100) */

  /*** For the six available coins the minimum is 1, the rest we initiate on 0 ***/
  d = (int*)calloc(MAX*10+1,sizeof(int));
  for (i=0; i<NUM; i++) d[coins[i]] = 1;

  while (f == -1)
  {
    /*** Let's go into the next step ***/
    s++;

    /*** We use some tricks to walk through the different combinations of a and b, with a+b=s. ***/
    for (a=1; a<=s/2; a++)
    {
      b = s-a;
      f = 1;
      for (i=1; i<=MAX; i++)
      {
        if (d[i] == 0) f = -1;
        else if (d[i] == a)
        {
          for (j=1; j<=MAX; j++)
          {
            if (d[j] == b)
            {
              /*** When we found that d[i] is already set on a and d[j] is already set on b, then we
                   can set d[i+j], d[i-j] and d[j-i] on a+b=s, only if the indexes are in the range 1..MAX ***/
              if (i+j <= MAX && d[i+j] == 0) d[i+j] = s;
              if (i-j > 0 && d[i-j] == 0) d[i-j] = s;
              else if (j-i > 0 &&d[j-i] == 0) d[j-i] = s;
            }
          }
        }
      } 
    }
  }

  /*** Afterwards, we compute the average and seek for the maximum ***/
  s = 0;
  for (i=0; i<=MAX; i++) 
  {
    if (d[i] > s)
    {
      s = d[i];
      j = i;
    }
    sum += d[i];
  }

  /*** Now, we can print the solution ***/
  printf("%4.2f %d\n",((float)sum/MAX),s);
}


int main (void)
{
  int i, j, n;
  FILE* fp;

  fp = fopen("a.in","r");
  fscanf(fp,"%d\n",&n);
  for (i=1; i<=n; i++)
  {
    /*** Scan in the NUM coin values ***/
    for (j=0; j<NUM; j++) fscanf(fp,"%d",coins+j);
    fscanf(fp,"\n");
    solve();
  }

  return 0;
}
