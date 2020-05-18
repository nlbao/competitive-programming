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

const int MAX_N = 55;

int n;
pair<char,char> a[MAX_N];
bool f[2][MAX_N][MAX_N][MAX_N];

bool ok(int i, int j) { return a[i].fr == a[j].fr || a[i].sc == a[j].sc;   }

bool solve() {
   if (n < 4) {
      ford(i,n-1,1)
         if (!ok(n,i)) return false;
      return true;
   }
   int t = 0;
   fill(f,false);
   f[t][n-2][n-1][n] = true;
   ford(c,n-3,1) {
      int tt = (t+1)%2;
      foru(i,c+1,n)
         foru(j,c+1,n)
            foru(k,c+1,n) f[tt][i][j][k] = false;
      foru(i,c+1,n)
         foru(j,c+1,n) {
            if (j == i) continue;
            foru(k,c+1,n)
               if (k != j && k != i && f[t][i][j][k]) {
                  if (ok(j,k)) f[tt][c][i][k] = true;
                  if (ok(c,k)) f[tt][k][i][j] = true;
               }
         }
      t = tt;
   }
   foru(i,1,n)
      foru(j,1,n)
         foru(k,1,n)
            if (f[t][i][j][k] && ok(k,j) && ok(k,i)) return true;
   return false;
}

int main() {
   freopen("208B.in", "r", stdin);
   freopen("208B.out", "w", stdout);
   char s[5];
   scanf("%d",&n);
   foru(i,1,n) {
      scanf("%s",&s);
      a[i] = mp(s[0],s[1]);
   }
   if (solve() == true) printf("YES");
   else printf("NO");
   return 0;
}
