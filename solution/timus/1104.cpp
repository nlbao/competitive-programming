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

const int MAX_N = 1000010;

char s[MAX_N];

int num(char a) {
   if (a <= '9') return a-'0';
   return a-'A'+10;
}

int main() {
   freopen("1104.in", "r", stdin);
   freopen("1104.out", "w", stdout);
   scanf("%s",s);
   int n = strlen(s), res = -1, minb = 2, sum = 0;
   rep(i,n) {
      minb = max(minb,num(s[i])+1);
      sum += num(s[i]);
   }
   foru(i,minb,36)
      if (sum%(i-1) == 0) {
         res = i;
         break;
      }
   if (res < 0) printf("No solution.");
   else printf("%d\n",res);
   return 0;
}
