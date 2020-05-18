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

const int MAX_N = 100004;

vector<PI> a;

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("237A.in", "r", stdin);
   freopen("237A.out", "w", stdout);
#endif
   int n = read();
   rep(i,n) a.pb(mp(read(),read()));
   sort(all(a));
   int res = 1;
   for(int i = 0, j = 0; i < n; i = j) {
      while (j < n && a[j].fr == a[i].fr && a[j].sc == a[i].sc) ++j;
      res = max(res,j-i);
   }
   cout << res;
   return 0;
}
