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

const int MAX_M = 1010;
const int MAX_LEN = 50;
const ll BASE = 10007;

int m = 0;
char s[MAX_LEN];
ll h[MAX_M];

int main() {
   freopen("VMSort.in", "r", stdin);
   freopen("VMSort.out", "w", stdout);
   int k, n;
   scanf("%d",&k);
   rep(kk,k) {
      scanf("%d",&n);
      rep(nn,n) {
         scanf("%s",s);
         int len = strlen(s);
         ll g = 0;
         rep(i,len) g = g*BASE+s[i];
         h[m++] = g;
      }
   }
   sort(h,h+m);
   int res = 0;
   for(int i = 0, j = 0; i < m; i = j) {
      ++res;
      while (j < m && h[j] == h[i]) ++j;
   }
   printf("%d\n",res);
   return 0;
}
