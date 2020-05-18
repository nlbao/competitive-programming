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

const int MAX_N = 210;
const int MAX_K = 11;

int n, k;
char s[MAX_N];
int a[MAX_N], c[MAX_N], res[MAX_N], rr[MAX_N];
bool ok[MAX_N][MAX_K];

void get_rr(int p) {
   rep(i, n) {
      rr[i] = p;
      if (i < n-1)
         rep(j,k)
            if (j != p && ok[i+1][j]) {
               p = j;
               break;
            }
   }
}

void up() {
   rep(i, n)
      if (rr[i] < res[i]) break;
      else if (rr[i] > res[i]) return;
   rep(i, n) res[i] = rr[i];
}

int main() {
   freopen("CAKEDOOM.in", "r", stdin);
   freopen("CAKEDOOM.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&k);
      scanf("%s",s);
      n = strlen(s);
      rep(i, n) {
         if (s[i] == '?') a[i] = -1;
         else a[i] = s[i]-'0';
         res[i] = k+100;
      }

      bool found = false;
      rep(j,k) {
         if (j && a[n-1] > -1) break;
         fill(ok,false);
         fill(c,0);
         int x;
         if (a[n-1] == -1) ok[n-1][j] = true, x = j;
         else ok[n-1][a[n-1]] = true, x = a[n-1];
         c[n-1] = 1;

         ford(i,n-2,0)
            rep(jj,k) {
               if (a[i] > -1 && jj != a[i]) continue;
               if ((ok[i+1][jj] && c[i+1] > 1) || (!ok[i+1][jj] && c[i+1])) {
                  ok[i][jj] = true;
                  ++c[i];
               }
            }

         rep(jj,k)
            if (ok[0][jj] && (n == 1 || jj != x)) {
               get_rr(jj);
               up();
               found = true;
               break;
            }
      }

      if (!found) printf("NO");
      else rep(i, n) printf("%d",res[i]);
      printf("\n");
   }
   return 0;
}
