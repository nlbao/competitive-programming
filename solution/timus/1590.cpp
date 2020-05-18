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

const int MAX_N = 5007;

int n;
char s[MAX_N];
string t;
int kmp[MAX_N];

int main() {
   freopen("1590.in", "r", stdin);
   freopen("1590.out", "w", stdout);
   scanf("%s", s);
   n = strlen(s);
   int res = 0, m = 0;
   rep(i, n) {
      t = s[i]+t;
      ++m;
      int j = 0, maxL = 0;
      kmp[0] = 0;
      foru(k, 1, m-1) {
         while (j && t[j] != t[k]) j = kmp[j-1];
         if (t[j] == t[k]) ++j;
         kmp[k] = j;
         maxL = max(maxL, j);
      }
      res += i+1-maxL;
   }
   printf("%d", res);
   return 0;
}
