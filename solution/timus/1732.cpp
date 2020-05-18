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

const int MAX_N = 100007;

char s[MAX_N], t[MAX_N], res[MAX_N];

int main() {
   freopen("1732.in", "r", stdin);
   freopen("1732.out", "w", stdout);
   gets(s);
   gets(t);
   int n = strlen(s), m = strlen(t);

   int i = 0, j = 0, len = 0;
   while (i < n && j < m) {
      //cout << i << " " << j << endl;
      if (s[i] == t[j]) {
         res[len++] = s[i];
         ++i;  ++j;
      }
      else if (s[i] == ' ') res[len++] = s[i++];
      else {
         res[len++] = '_';
         ++i;
         if (t[j] == ' ') ++j;
      }
   }


   if (j < m) {
      printf("I HAVE FAILED!!!");
      return 0;
   }

   for(i; i < n; ++i) res[len++] = '_';
   rep(i, len) printf("%c", res[i]);
   return 0;
}
