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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 504;
const int oo = 1000000000;

int n, m;
char s[MAX_N];
int g[MAX_N][MAX_N], f[MAX_N][MAX_N], trace[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void print_path(int n, int m) {
   if (trace[n][m] > 0) {
      print_path(trace[n][m],m-1);
      printf("+");
   }
   int j = n;
   foru(i,trace[n][m],n-1) {
      if (--j <= i) break;
      s[j] = s[i];
   }
   foru(i,trace[n][m],n-1) printf("%c",s[i]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("137D.in", "r", stdin);
   freopen("137D.out", "w", stdout);
#endif
   scanf("%s%d",&s,&m);
   n = strlen(s);

   foru(i,1,n) g[i][i] = 0;
   foru(i,1,n-1) g[i][i+1] = (s[i-1] != s[i]);
   foru(len,3,n)
      foru(i,1,n-len+1) {
         int j = i+len-1;
         g[i][j] = (s[j-1] != s[i-1]) + g[i+1][j-1];
      }

   foru(i,0,m) f[0][i] = oo;
   f[0][0] = 0;
   foru(i,1,n) {
      foru(j,0,m) f[i][j] = oo;
      foru(j,1,min(i,m))
         foru(ii,max(0,j-1),i-1) {
            int t = f[ii][j-1] + g[ii+1][i];
            if (t < f[i][j]) {
               f[i][j] = t;
               trace[i][j] = ii;
            }
         }
   }

   int res = 1;
   foru(i,2,min(n,m))
      if (f[n][i] < f[n][res]) res = i;
   printf("%d\n",f[n][res]);
   print_path(n,res);
   return 0;
}
