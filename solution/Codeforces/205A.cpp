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


int main() {
   freopen("205A.in", "r", stdin);
   freopen("205A.out", "w", stdout);
   int n;
   scanf("%d",&n);
   int x = 2000000000, id;
   bool stay = false;
   rep(i,n) {
      int a;
      scanf("%d",&a);
      if (a == x) stay = true;
      else if (a < x) {
         x = a;
         id = i+1;
         stay = false;
      }
   }
   if (stay) printf("Still Rozdil");
   else printf("%d",id);
   return 0;
}
