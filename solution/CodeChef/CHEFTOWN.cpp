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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 400003;

int n, w;
int a[MAX_N], f[4*MAX_N], q[MAX_N];

void update(int i, int v) {
   if (i < 1 || i > n) return;
   f[i] += v;
   update(i+(i&(-i)),v);
}

int get(int i) {
   if (i < 1 || i > n) return 0;
   return f[i] + get(i-(i&(-i)));
}

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("CHEFTOWN.in", "r", stdin);
   freopen("CHEFTOWN.out", "w", stdout);
#endif
   scanf("%d%d",&n,&w);
   foru(i,1,n) scanf("%d",&a[i]);
   fill(f,0);
   int l = 1, r = 0, res = 0;
   foru(i,1,w-1) {
      while (r >= l && a[q[r]] >= a[i]) --r;
      q[++r] = i;
      update(a[i],1);
   }
   foru(i,w,n) {
      if (i > w) update(a[i-w],-1);
      if (l <= r && q[l] < i-w+1) ++l;
      while (r >= l && a[q[r]] >= a[i]) --r;
      q[++r] = i;
      update(a[i],1);
      int x = a[q[l]];
      if (x <= n-w+1 && get(x+w-1)-get(x-1) == w) ++res;
   }
   printf("%d",res);
   return 0;
}
