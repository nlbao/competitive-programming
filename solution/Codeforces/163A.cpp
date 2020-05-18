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

const int MAX_N = 5005;
const int MODUN = 1000000007;

char a[MAX_N], b[MAX_N];
int f[2][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("163A.in", "r", stdin);
   freopen("163A.out", "w", stdout);
#endif
   scanf("%s%s",&a,&b);
   int n = strlen(a), m = strlen(b);
   fill(f,0);
   int t = 0, res = 0;
   foru(i,1,n) {
      int tt = t;
      t = (t+1)&1;
      foru(j,1,m) {
         f[t][j] = f[t][j-1];
         if (a[i-1] == b[j-1])
            f[t][j] = (f[t][j] + f[tt][j-1] + 1)%MODUN;
      }
      res = (res + f[t][m])%MODUN;
   }
   cout << res;
   return 0;
}
