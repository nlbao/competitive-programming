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

const int MAX_N = 22;
const int oo = 2000000000;

int n, res;
int a[MAX_N], r[MAX_N];
bool ok[MAX_N];

void tryf(int s) {
   int c = 0;
   rep(i,n)
      if (ok[i]) {
         s += a[i];
         ++c;
      }
   if (c == 0) res = min(res,s);
   if (s >= res) return;
   rep(i,n)
      if (ok[i]) {
         bool x = ok[r[i]], y = ok[r[r[i]]];
         ok[i] = false;
         ok[r[i]] = false;
         ok[r[r[i]]] = false;
         tryf(s);
         ok[r[r[i]]] = y;
         ok[r[i]] = x;
         ok[i] = true;
      }
}

int main() {
   freopen("1152.in", "r", stdin);
   freopen("1152.out", "w", stdout);
   scanf("%d",&n);
   int s = 0;
   rep(i,n) {
      scanf("%d",&a[i]);
      r[i] = i+1;
      s -= a[i];
   }
   r[n-1] = 0;

   res = oo;
   fill(ok,true);
   tryf(s);
   printf("%d",res);
   return 0;
}
