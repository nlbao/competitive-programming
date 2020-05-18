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

const int MAX_N = 4002;

char s[MAX_N];
bool ok[MAX_N][MAX_N];
int f[MAX_N], trace[MAX_N];

void print_path(int r) {
   if (r < 0) return;
   print_path(trace[r]);
   foru(i,trace[r]+1,r) printf("%c",s[i]);
   printf(" ");
}

int main() {
   freopen("1635.in", "r", stdin);
   freopen("1635.out", "w", stdout);
   scanf("%s",&s);
   int n = strlen(s);

   rep(i,n) ok[i][i] = true;
   rep(i,n-1) ok[i][i+1] = (s[i] == s[i+1]);
   foru(len,3,n) {
      rep(i,n-len+1) {
         int j = i+len-1;
         ok[i][j] = (s[i] == s[j]) && ok[i+1][j-1];
      }
   }

   rep(i,n)
      if (ok[0][i]) {
         f[i] = 1;
         trace[i] = -1;
      }
      else {
         f[i] = i+1;
         trace[i] = i-1;
         rep(j,i)
         if (ok[j+1][i] && f[j]+1 < f[i]) {
            f[i] = f[j]+1;
            trace[i] = j;
         }
      }

   printf("%d\n",f[n-1]);
   print_path(n-1);
   return 0;
}
