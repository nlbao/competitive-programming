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

int res[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("260A.in", "r", stdin);
   freopen("260A.out", "w", stdout);
#endif
   int a, b, n;
   scanf("%d%d%d",&a,&b,&n);
   int r = a%b;
   bool ck = true;
   foru(i,1,n) {
      ck = false;
      rep(x,10)
         if ((r*10+x)%b == 0) {
            ck = true;
            res[i] = x;
            r = (r*10+x)%b;
            break;
         }
      if (!ck) break;
   }
   if (!ck) cout << -1;
   else {
      printf("%d",a);
      foru(i,1,n) printf("%d",res[i]);
   }
   return 0;
}
