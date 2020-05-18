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

const int MAX_N = 100010;

int n;
char s[MAX_N];
int kmp[MAX_N];

int main() {
   freopen("FINDSR.in", "r", stdin);
   freopen("FINDSR.out", "w", stdout);
   for(;;) {
      scanf("%s", s);
      if (s[0] == '*') break;
      n = strlen(s);
      rep(i,n) s[n+i] = s[i];
      kmp[0] = 0;
      foru(i,1,2*n-1) {
         int j = kmp[i-1];
         while (j && s[j] != s[i]) j = kmp[j-1];
         if (s[j] == s[i]) ++j;
         kmp[i] = j;
         if (j >= n)
            if (i > n-1 && n%(i-n+1) == 0) {
               printf("%d\n",n/(i-n+1));
               break;
            }
            else j = kmp[j-1];
      }
   }
   return 0;
}
