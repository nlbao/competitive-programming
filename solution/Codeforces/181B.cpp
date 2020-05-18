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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int limit = 1001;
const int MAX_N = 3007;

int x[MAX_N], y[MAX_N];
int f[2222][2222], g[2222][2222], turn[2222][2222];

int id(int a, int b) {  return (a+b)/2+limit;   }

int main() {
   freopen("181B.in", "r", stdin);
   freopen("181B.out", "w", stdout);
   int n, res = 0;
   cin >> n;
   foru(i, 1, n)
      scanf("%d%d", &x[i], &y[i]);
   fill(f, 0);
   fill(turn, 0);
   foru(i, 1, n)
      foru(j, i, n)
         if ((x[i]+x[j])%2 == 0 && (y[i]+y[j])%2 == 0)
            ++f[id(x[i],x[j])][id(y[i],y[j])];
   foru(i, 1, n) {
      foru(j, 1, n)
         if ((x[i]+x[j])%2 == 0 && (y[i]+y[j])%2 == 0) {
            int a = id(x[i],x[j]), b = id(y[i],y[j]);
            if (turn[a][b] == i) ++g[a][b];
            else {
               turn[a][b] = i;
               g[a][b] = 1;
            }
         }
      int a = id(x[i], x[i]), b = id(y[i], y[i]);
      res += f[a][b]-g[a][b];
   }

   cout << res << endl;
   return 0;
}

