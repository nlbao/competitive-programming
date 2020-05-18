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

const ll oo = 1000000000000000000LL;

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("251C.in", "r", stdin);
   freopen("251C.out", "w", stdout);
#endif
   cin >> a >> b >> k;
   ll res = oo;
   fill(ok,false);
   foru(i,1,k)
      foru(j,0,k) f[i][j] = g[i][j] = oo;
   foru(i,1,k) {
      ok[i][a%i] = true;
      g[i][a%i] = a;
      f[i][a%i] = 0;
   }






   return 0;
}
