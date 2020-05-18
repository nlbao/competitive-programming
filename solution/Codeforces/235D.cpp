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
typedef unsigned long long ull;
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

const int MAX_N = 404;

char str[MAX_N], a[MAX_N][MAX_N];
int h[MAX_N][MAX_N], s[MAX_N];
ll c[33];

int num(char x) { return x-'a'+1;   }

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("235D.in", "r", stdin);
   freopen("235D.out", "w", stdout);
#else
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n, m, limit;
   scanf("%d%d%d",&n,&m,&limit);
   foru(i,1,n) {
      scanf("%s",&str);
      foru(j,1,m) a[i][j] = str[j-1];
   }

   fill(h,0);
   foru(i,1,m)
      foru(j,1,n) h[i][j] = h[i][j-1] + int(a[j][i] == 'a');

   ll res = 0;
   s[0] = 0;
   foru(i,1,n)
      foru(j,i+1,n) {
         fill(c,0);
         int l = 0;
         foru(k,1,m) {
            s[k] = s[k-1] + h[k][j]-h[k][i-1];
            while (l < k-1 && s[k]-s[l] > limit) {
               ++l;
               if (a[i][l] == a[j][l]) --c[num(a[i][l])];
            }
            if (a[i][k] == a[j][k]) {
               if (s[k]-s[l] <= limit) res += c[num(a[i][k])];
               ++c[num(a[i][k])];
            }
         }
      }
   cout << res;
   return 0;
}
