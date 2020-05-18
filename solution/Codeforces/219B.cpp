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

ll a[20];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll num(int n) {
   ll x = 0;
   ford(i,n-1,0) x = x*10+a[i];
   return x;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("219B.in", "r", stdin);
   freopen("219B.out", "w", stdout);
#endif
   ll p, d;
   cin >> p >> d;
   ll t = p, res = p, c = 0;
   int n = 0;
   while (t > 0) {
      a[n++] = t%10;
      t /= 10;
   }
   while (c < n && a[c] == 9) ++c;

   a[0] = 9;
   foru(i,1,n-1) {
      ll t = a[i];
      foru(j,0,t-1) {
         a[i] = j;
         if (p-num(n) <= d) {
            ll x = 0;
            while (x < n && a[x] == 9) ++x;
            if (x > c) {
               c = x;
               res = num(n);
            }
            else if (x == c) res = max(res,num(n));
         }
      }
      a[i] = 9;
   }
   cout << res;
   return 0;
}
