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

const int MAX_N = 260;

struct can {
   int a, b, c;
   can(int aa, int bb, int cc) {  a = aa;  b = bb;  c = cc;  }
};

int x, y, z;
bool ok[3*MAX_N], f[MAX_N][MAX_N][MAX_N];
queue<can> q;


void up(int i, int j, int k) {
   if (i > x || j > y || k > z) return;
   if (f[i][j][k]) return;
   f[i][j][k] = true;
   q.push(can(i,j,k));
   ok[i] = ok[j] = ok[k] = true;
   ok[i+j] = ok[i+k] = ok[j+k] = true;
   ok[i+j+k] = true;
}

int main() {
   freopen("1437.in", "r", stdin);
   freopen("1437.out", "w", stdout);
   while (cin >> x >> y >> z) {
      q.empty();
      fill(ok,false);
      fill(f,false);
      f[0][0][0] = true;
      q.push(can(0,0,0));
      while (!q.empty()) {
         can u = q.front();   q.pop();
         int i = u.a, j = u.b, k = u.c;
         up(i-min(y-j,i),j+min(y-j,i),k);    up(i-min(z-k,i),j,k+min(z-k,i));
         up(i+min(x-i,j),j-min(x-i,j),k);    up(i,j-min(z-k,j),k+min(z-k,j));
         up(i+min(x-i,k),j,k-min(x-i,k));    up(i,j+min(y-j,k),k-min(y-j,k));
         up(x,j,k);
         up(i,y,k);
         up(i,j,z);
      }
      int res = 0;
      foru(i,1,x+y+z) res += ok[i];
      printf("%d\n",res);
   }
   return 0;
}
