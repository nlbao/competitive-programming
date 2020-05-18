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

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("245A.in", "r", stdin);
   freopen("245A.out", "w", stdout);
#endif
   int n = read(), sa = 0, ca = 0, sb = 0, cb = 0;
   rep(i,n) {
      int t,x,y;
      scanf("%d%d%d",&t,&x,&y);
      if (t == 1) {
         sa += x;
         ca += y;
      }
      else {
         sb += x;
         cb += y;
      }
   }

   if (sa >= ca) cout << "LIVE";
   else cout << "DEAD";
   cout << endl;
   if (sb >= cb) cout << "LIVE";
   else cout << "DEAD";
   return 0;
}
