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

const int MAX_N = 33;

int n, u;
ll r, res = -1000000000000000000LL;
ll a[MAX_N], b[MAX_N], k[MAX_N];
int p[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll cal() {
   ll s = 0;
   foru(i,1,n) s += a[i]*k[i];
   return s;
}

void tryf(int c, bool ok) {
   if (c > u) {
      res = max(res,cal());
      return;
   }
   if ((u-c)&1) res = max(res,cal());

   ll temp[MAX_N];
//operator 1
   if (ok) {
      foru(i,1,n) temp[i] = a[i];
      foru(i,1,n) a[i] ^= b[i];
      tryf(c+1,false);
      foru(i,1,n) a[i] = temp[i];
   }
//operator 2
   foru(i,1,n) temp[i] = a[i];
   foru(i,1,n) a[i] = temp[p[i]]+r;
   tryf(c+1,true);
   foru(i,1,n) a[i] = temp[i];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("193B.in", "r", stdin);
   freopen("193B.out", "w", stdout);
#endif
   cin >> n >> u >> r;
   foru(i,1,n) cin >> a[i];
   foru(i,1,n) cin >> b[i];
   foru(i,1,n) cin >> k[i];
   foru(i,1,n) cin >> p[i];
   tryf(1,true);
   cout << res;
   return 0;
}
