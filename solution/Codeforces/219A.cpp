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

char s[1010];
int c[33];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("219A.in", "r", stdin);
   freopen("219A.out", "w", stdout);
#endif
   int k;
   scanf("%d",&k);
   scanf("%s",&s);
   int n = strlen(s);
   if (n%k != 0) {
      printf("-1");
      return 0;
   }
   fill(c,0);
   rep(i,n) ++c[s[i]-'a'];
   n = 0;
   rep(i,30) {
      if (c[i]%k != 0) {
         printf("-1");
         return 0;
      }
      rep(j,c[i]/k) s[n++] = char(i+'a');
   }
   rep(i,k)
      rep(j,n) printf("%c",s[j]);
   return 0;
}
