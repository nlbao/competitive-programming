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

const int MAX_N = 111;
const int MAX_K = 30;
const int oo = 1000000000;

char s[MAX_N];
int a[MAX_N];
int c[MAX_K], d[MAX_N][MAX_K], sum[MAX_K];
int g[MAX_N][MAX_K][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int num(char x)   {  return x-'a';  }

int main() {
#ifndef ONLINE_JUDGE
   freopen("237E.in", "r", stdin);
   freopen("237E.out", "w", stdout);
#endif
   scanf("%s",&s);
   int ls = strlen(s);
   fill(c,0);
   rep(i,ls) ++c[num(s[i])];

   fill(d,0);
   int n = read();
   foru(i,1,n) {
      scanf("%s",&s);
      scanf("%d",&a[i]);
      int m = strlen(s);
      rep(j,m) ++d[i][num(s[j])];
   }

   rep(k,MAX_K) {
      foru(j,1,ls) g[n+1][k][j] = oo;
      g[n+1][k][0] = 0;
      sum[k] = 0;
   }
   ford(i,n,1)
      rep(k,MAX_K) {
         foru(j,1,ls) {
            g[i][k][j] = oo;
            foru(jj, max(j-min(d[i][k],a[i]),0), min(sum[k],j))
               g[i][k][j] = min(g[i][k][j], g[i+1][k][jj] + (j-jj)*i);
         }
         g[i][k][0] = 0;
         sum[k] += d[i][k];
      }

   cout << g[n][num('b')][2] << endl;

   int res = 0;
   foru(i,1,n)
      foru(turn,1,a[i]) {
         int u = -1, maxG = -1;
         rep(k,MAX_K)
            if (c[k] > 0 && d[i][k] > 0) {
               int t = g[i+1][k][c[k]];
               if (t > maxG) {
                  maxG = t;
                  u = k;
               }
            }
         if (u < 0) break;
         res += i;
         --c[u];  --d[i][u];

         cout << i << "   " << char(u+int('a')) << "        " << maxG << endl;
      }
   rep(k,MAX_K) if (c[k] > 0) res = -1;
   cout << res;
   return 0;
}
