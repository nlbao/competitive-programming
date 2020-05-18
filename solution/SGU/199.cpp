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
typedef unsigned long long ull;
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

const int MAX_N = 100005;

pair<PI,int> a[MAX_N];
int f[MAX_N], trace[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("199.in", "r", stdin);
   freopen("199.out", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   foru(i,1,n) {
      int x = read(), y = read();
      a[i] = mp(mp(x,-y),i);
   }
   sort(a+1, a+1+n);

   int top = 0;
   fill(trace,0);
   foru(i,1,n) {
      int t = 0, l = 1, r = top;
      while (l <= r) {
         int mid = (l+r)>>1;
         if (-a[f[mid]].fr.sc < -a[i].fr.sc) {
            t = mid;
            l = mid+1;
         }
         else r = mid-1;
      }
      trace[i] = f[t];
      f[++t] = i;
      top = max(top,t);
   }

   printf("%d\n",top);
   int i = f[top];
   while (i > 0) {
      printf("%d ",a[i].sc);
      i = trace[i];
   }
   return 0;
}
