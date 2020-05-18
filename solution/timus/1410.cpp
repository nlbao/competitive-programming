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

int f[MAX_N];
char s[102];

bool ok(char x) { return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'); }

int main() {
   freopen("1410.in", "r", stdin);
   freopen("1410.out", "w", stdout);
   int n = 0;
   while (scanf("%s",&s) == 1) {
      int m = strlen(s), c = 0;
      rep(i,m)
         if (ok(s[i])) ++c;
         else if (i < m-1) {
            if (c > 0) f[n++] = c;
            c = 0;
         }
         if (c > 0) f[n++] = c;
   }
   f[1] = max(f[0],f[1]);
   foru(i,2,n-1)
      f[i] = max(f[i-1],f[i-2]+f[i]);
   printf("%d",f[n-1]);
   return 0;
}
