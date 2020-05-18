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

const int MAX_N = 410;
const int MAX_M = 410;

int n, m;
char a[MAX_N][MAX_M];
bool ok[MAX_N][MAX_M];

bool cmp_row(int id, int i, int j, string s) {
   if (i < 0 || j >= m) return false;
   foru(k,i,j)
      if ((!ok[id][k]) || a[id][k] != s[k-i]) return false;
   return true;
}

bool cmp_column(int id, int i, int j, string s) {
   if (i < 0 || j >= n) return false;
   foru(k,i,j)
      if ((!ok[k][id]) || a[k][id] != s[k-i]) return false;
   return true;
}

int count() {
   int res = 0;
   rep(i, n)
      rep(j, m) {
         if (cmp_row(i,j,j+2,">o<")) {
            ++res;
            foru(k,j,j+2) ok[i][k] = false;
         }
         if (cmp_column(j,i,i+2,"vo^")) {
            ++res;
            foru(k,i,i+2) ok[k][j] = false;
         }
      }
   return res;
}

int main() {
   freopen("a.in", "r", stdin);
   freopen("a.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d%d",&n,&m);
      rep(i, n) scanf("%s",a[i]);
      fill(ok,true);
      printf("%d\n",count());
   }
   return 0;
}
