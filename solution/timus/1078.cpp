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

const int MAX_N = 510;

pair<PI,int> a[MAX_N];
int f[MAX_N], trace[MAX_N];

void print_path(int i) {
   if (i < 0) return;
   print_path(trace[i]);
   printf("%d ",a[i].sc);
}

int main() {
   freopen("1078.in", "r", stdin);
   freopen("1078.out", "w", stdout);
   int n;
   scanf("%d",&n);
   rep(i,n) {
      int x,y;
      scanf("%d%d",&x,&y);
      a[i] = mp(mp(x,y),i+1);
   }
   sort(a,a+n);

   int res = 0, p = 0;
   ford(i,n-1,0) {
      f[i] = 1;
      trace[i] = -1;
      foru(j,i+1,n-1)
         if (a[j].fr.fr > a[i].fr.fr && a[j].fr.sc < a[i].fr.sc && f[j]+1 > f[i]) {
            f[i] = f[j]+1;
            trace[i] = j;
         }
      if (f[i] > res) {
         res = f[i];
         p = i;
      }
   }
   printf("%d\n",res);
   print_path(p);
   return 0;
}
