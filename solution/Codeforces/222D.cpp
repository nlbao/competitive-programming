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

const int MAX_N = 100010;

int a[MAX_N], b[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("222D.in", "r", stdin);
   freopen("222D.out", "w", stdout);
#endif
   int n, x;
   scanf("%d%d",&n,&x);
   rep(i,n) scanf("%d",&a[i]);
   rep(i,n) scanf("%d",&b[i]);
   sort(a,a+n);
   sort(b,b+n);
   int res = 0;
   int i = 0, j = n-1;
   while (i < n && j >= 0) {
      if (a[i]+b[j] < x) ++i;
      else {
         ++res;
         ++i;  --j;
      }
   }
   printf("1 %d",res);
   return 0;
}
