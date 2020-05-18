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
const int MAX_Y = 30010;

int n, maxy = 0;
int a[MAX_Y], f[MAX_Y];

int main() {
   freopen("1203.in", "r", stdin);
   freopen("1203.out", "w", stdout);
   fill(a,0);
   scanf("%d",&n);
   rep(i,n) {
      int x,y;
      scanf("%d%d",&x,&y);
      if (a[y] < x) a[y] = x;
      maxy = max(maxy,y);
   }

   fill(f,0);
   foru(i,1,maxy) {
      f[i] = f[i-1];
      if (a[i] > 0) f[i] = max(f[i],f[a[i]-1]+1);
   }
   printf("%d",f[maxy]);
   return 0;
}
