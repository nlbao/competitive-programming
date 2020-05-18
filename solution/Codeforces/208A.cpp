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

char s[203], t[203];

int main() {
   freopen("208A.in", "r", stdin);
   freopen("208A.out", "w", stdout);
   scanf("%s",&s);
   int n = strlen(s);
   int i = 0, m = 0;
   while (i < n)
      if (s[i] == 'W' && i < n-2 && s[i+1] == 'U' && s[i+2] == 'B') {
         if (m > 0 && t[m-1] != ' ') t[m++] = ' ';
         i += 3;
      }
      else t[m++] = s[i++];
   if (t[m-1] == ' ') --m;
   rep(i,m) printf("%c",t[i]);
   return 0;
}
