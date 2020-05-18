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

const int MAX_N = 103;
const int oo = 1000000000;

int a[MAX_N][MAX_N], f[MAX_N][MAX_N], trace[MAX_N][MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void print_path(int u, int v) {
   int k = trace[u][v];
   if (u != v && k != u) {
      print_path(u,k);
      print_path(k,v);
   }
   else {
      ok[u] = ok[v] = false;
      if (ok[u]) printf("%d ",u);
      if (v != u && ok[v]) printf("%d ",v);
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1004.in", "r", stdin);
   freopen("1004.out", "w", stdout);
#endif
   while(1) {
      int n, m, res = oo, res_u, res_v;
      scanf("%d",&n);
      if (n == -1) break;

      foru(i,1,n)
         foru(j,1,n) {
            a[i][j] = f[i][j] = oo;
            trace[i][j] = i;
         }

      scanf("%d",&m);
      rep(i,m) {
         int x, y, w;
         scanf("%d%d%d",&x,&y,&w);
         a[x][y] = a[y][x] = min(a[x][y],w);
      }

      foru(i,1,n)
         foru(j,i+1,n)
            foru(k,1,n)
               if (k != i && k != j) {
                  int d = a[i][k]+a[k][j];
                  if (d < f[i][j]) {
                     f[i][j] = f[j][i] = d;
                     trace[i][j] = trace[j][i] = k;
                  }
               }

      cout << f[1][2] << endl;

      foru(k,1,n)
         foru(i,1,n)
            foru(j,1,n) {
               int d = f[i][k]+f[k][j];
               if (d < f[i][j]) {
                  f[i][j] = d;
                  trace[i][j] = k;
               }
            }

      cout << f[1][2] << endl;

      foru(i,1,n)
         foru(j,1,n)
            if (trace[i][j] != i && f[i][j]+a[j][i] < res) {
               res = f[i][j]+a[j][i];
               res_u = i;  res_v = j;
            }


      cout << res << "  " << res_u << " " << res_v << endl;

      if (res == oo) printf("No solution.\n");
      else {
         fill(ok,true);
         //print_path(res_u,res_v);
         printf("\n");
      }
   }
   return 0;
}
