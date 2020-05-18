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

const int MAX_N = 200;

int n;
char s[MAX_N];
int z[MAX_N];

int main() {
   freopen("455.in", "r", stdin);
   freopen("455.out", "w", stdout);
   int nTest;
   cin >> nTest;
   rep(id, nTest) {
      scanf("%s", s);
      n = strlen(s);
      if (n < 1) {
         scanf("%s", s);
         n = strlen(s);
      }
      rep(i,n) s[n+i] = s[i];
      z[0] = 0;
      for(int l = 0, r = 0, i = 1; i < 2*n; ++i) {
         z[i] = 0;
         if (i <= r) z[i] = min(r-i+1,z[i-l]);
         while (z[i] < n && i+z[i] < 2*n && s[z[i]] == s[i+z[i]]) ++z[i];
         if (z[i] >= n && i && n%i == 0) {
            printf("%d\n",i);
            break;
         }
         if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
         }
      }
      if (id < nTest-1) printf("\n");
   }
   return 0;
}
