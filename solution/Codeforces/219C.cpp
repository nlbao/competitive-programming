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

const int MAX_N = 500007;
const int MAX_K = 30;
const int oo = 1000000000;

int n, k;
char s[MAX_N];
int a[MAX_N];
int f[MAX_N][MAX_K], trace[MAX_N][MAX_K];

int read() {   int x;   scanf("%d",&x);   return x;   }

void print_path(int i, int j) {
   if (i > 0) print_path(i-1,trace[i][j]);
   printf("%c",char(j+'A'));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("219C.in", "r", stdin);
   freopen("219C.out", "w", stdout);
#endif
   scanf("%d%d",&n,&k);
   scanf("%s",&s);
   rep(i,n) {
      a[i] = s[i]-'A';
      rep(j,k) f[i][j] = oo;
   }
   rep(j,k) f[0][j] = 1;
   f[0][a[0]] = 0;

   rep(i,n-1)
      rep(j,k)
         rep(jj,k) if (jj != j) {
            int d = f[i][j] + (a[i+1] != jj);
            if (d < f[i+1][jj]) {
               f[i+1][jj] = d;
               trace[i+1][jj] = j;
            }
         }

   int res = oo, p;
   rep(j,k)
      if (f[n-1][j] < res) {
         res = f[n-1][j];
         p = j;
      }
   printf("%d\n",res);
   print_path(n-1,p);
   return 0;
}
