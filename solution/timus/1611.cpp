#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 10003;
const int MAX_P = 53;
const int oo = 1000000000;

char s[MAX_N];
bool a[MAX_N];
int f[MAX_N][MAX_P], trace[MAX_N][MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }

int c(int n) {
   if (n < 10) return 0;
   return n/10;
}

void print_res(int i, int j) {
   if (i < 1) return;
   print_res(i-1,trace[i][j]);
   foru(t,i+trace[i][j],i+j-1) printf(" %d",t);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1611.in", "r", stdin);
   freopen("1611.out", "w", stdout);
#endif
   int n, p;
   scanf("%d%d",&n,&p);
   scanf("%s",&s);
   foru(i,1,n) {
      if (s[i-1] == '1') a[i] = true;
      else a[i] = false;
   }

   fill(trace,0);
   foru(i,1,n)
      foru(j,0,p) f[i][j] = oo;
   foru(j,0,p) f[1][j] = int(a[1] && (1+j)%10 == 0) + (j/10);

   foru(i,1,n-1)
      foru(j,0,p)
         foru(k,0,p-j) {
            int x = f[i][j] + int(a[i+1] && (i+1+j+k)%10 == 0);
            x += c(i+j+k)-c(i+j);

            if (x < f[i+1][j+k]) {
               f[i+1][j+k] = x;
               trace[i+1][j+k] = j;
            }
         }

   int res = oo, m;
   foru(j,0,p)
      if (f[n][j] < res) {
         res = f[n][j];
         m = j;
      }
   printf("%d\n",res);
   printf("%d",m);
   print_res(n,m);
   return 0;
}
