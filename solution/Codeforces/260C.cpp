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

const int MAX_N = 100004;

ll a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("260C.in", "r", stdin);
   freopen("260C.out", "w", stdout);
#endif
   int n, x;
   scanf("%d%d",&n,&x);
   foru(i,1,n) a[i] = read();
   bool found = false;
   ll sum = 0;
   ford(i,x,1)
      if (a[i] == 0) {
         a[i] = sum;
         found = true;
         break;
      }
      else {
         --a[i];
         ++sum;
      }
   if (!found) {
      ll tmp = 1000000000000000000LL;
      foru(i,1,n) tmp = min(tmp,a[i]);
      foru(i,1,n) {
         sum += tmp;
         a[i] -= tmp;
      }
      ford(i,n,1)
         if (a[i]) {
            --a[i];
            ++sum;
         }
         else {
            a[i] = sum;
            found = true;
            break;
         }
   }
   foru(i,1,n) printf("%lld ",a[i]);
      //printf("%I64d ",a[i]);
   return 0;
}
