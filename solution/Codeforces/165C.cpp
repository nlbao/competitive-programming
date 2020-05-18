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

const int MAX_N = 1000010;

char s[MAX_N];
int c[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("165C.in", "r", stdin);
   freopen("165C.out", "w", stdout);
#endif
   int k;
   scanf("%d",&k);
   scanf("%s",&s);
   int n = strlen(s);

   fill(c,0);
   c[0] = 1;
   int f = 0;
   ll res = 0;
   rep(i,n) {
      f += (s[i] == '1');
      if (f >= k) res += ll(c[f-k]);
      ++c[f];
   }
   cout << res;
   return 0;
}
