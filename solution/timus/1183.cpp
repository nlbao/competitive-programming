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

const int MAX_N = 110;

int n;
char s[MAX_N];
int f[MAX_N][MAX_N];
string res[MAX_N][MAX_N];

char inv(char x) {
   if (x == '(') return ')';
   if (x == '[') return ']';
   return '-';
}

string get_res(int x) {
   if (x == '(' || x == ')') return "()";
   return "[]";
}

int main() {
   freopen("1183.in", "r", stdin);
   freopen("1183.out", "w", stdout);
   scanf("%s",s);
   n = strlen(s);

   if (n == 1) {
      cout << get_res(s[0]);
      return 0;
   }

   rep(i,n-1) {
      f[i][i] = 1;
      res[i][i] = get_res(s[i]);
      if (s[i+1] == inv(s[i])) {
         f[i][i+1] == 0;
         res[i][i+1] = res[i][i];
      }
      else {
         f[i][i+1] = 2;
         res[i][i+1] = get_res(s[i])+get_res(s[i+1]);
      }
   }
   f[n-1][n-1] = 1;
   res[n-1][n-1] = get_res(s[n-1]);

   foru(len,3,n)
      rep(i,n-len+1) {
         int j = i+len-1, trace = -1;
         f[i][j] = n+1;
         if (s[j] == inv(s[i])) f[i][j] = f[i+1][j-1];
         foru(k,i,j-1) {
            int t = f[i][k]+f[k+1][j];
            if (t < f[i][j]) {
               f[i][j] = t;
               trace = k;
            }
         }
         if (trace == -1) res[i][j] = s[i]+res[i+1][j-1]+s[j];
         else res[i][j] = res[i][trace]+res[trace+1][j];
      }

   cout << res[0][n-1];
   return 0;
}
