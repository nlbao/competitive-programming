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

ll s[MAX_N];

int main() {
   freopen("1118.in", "r", stdin);
   freopen("1118.out", "w", stdout);
   fill(s,0);
   for(int i = 1; i < MAX_N; ++i)
      for(int j = i+i; j < MAX_N; j += i)
         s[j] += i;

   int l, r;
   scanf("%d%d",&l,&r);
   double mint = s[l]*1.0/l;
   int res = l;
   foru(i,l+1,r) {
      double t = s[i]*1.0/i;
      if (t < mint) mint = t, res = i;
   }
   printf("%d\n",res);
   return 0;
}
