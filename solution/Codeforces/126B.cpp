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

const int MAX_N = 1000007;

int n;
char s[MAX_N];
int f[MAX_N], c[MAX_N];

void  up(int &x, int &y, int xx, int yy) {  x = xx;  y = yy;  }

int main() {
#ifdef DEBUG
   freopen("126B.in", "r", stdin);
   freopen("126B.out", "w", stdout);
#endif
   scanf("%s", s);
   n = strlen(s);
   int j = 0;
   f[0] = 0;
   fill(c, 0);
   foru(i, 1, n-1) {
      while (j && s[j] != s[i]) j = f[j-1];
      if (s[j] == s[i]) ++j;
      ++c[f[i] = j];
   }
   int pos, len = 0;
   if (f[n-1] > 0) {
      if (c[f[n-1]] > 1) up(len, pos, f[n-1], n-f[n-1]);
      j = f[f[n-1]-1];
      while (j && !len) {
         if (c[j]) up(len, pos, j, n-j);
         else j = f[j-1];
      }
   }
   if (!len) printf("Just a legend");
   else foru(i, pos, pos+len-1) printf("%c", s[i]);
   return 0;
}
