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

const int MAX_N = 103;
const int MAX_M = 103;
const int MAX_A = MAX_N+MAX_M;
const ll oo = 1000000000000000099LL;

int n, m, nA;
pair<PI,PI> a[MAX_A];
int b[MAX_A], p[MAX_N][MAX_N], res[MAX_N][MAX_N];
ll k;
ll f[MAX_A][MAX_A];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll solve(int p, int v) {
   b[p] = v;
   fill(f,0);
   f[0][1] = 1;
   foru(i,1,nA) {
      if (b[i] < 1) f[i][0] = f[i-1][1];
      foru(j,1,nA) {
         if (b[i] == 0) f[i][j] += f[i-1][j-1]+f[i-1][j+1];
         else f[i][j] += f[i-1][j-b[i]];
         if (f[i][j] > k) f[i][j] = oo;
      }
   }
   b[p] = 0;
   return f[nA][1];
}

int get_min(int i, int j) {
   if (i < 1 || j < 1 || i > n || j > m) return 1000000000;
   return min(p[i][j],get_min(i+1,j-1));
}

void copy_res(int i, int j, int v) {
   if (i < 1 || j < 1 || i > n || j > m) return;
   res[i][j] = v;
   copy_res(i+1,j-1,v);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("123C.in", "r", stdin);
   freopen("123C.out", "w", stdout);
#endif
   cin >> n >> m >> k;
   foru(i,1,n)
      foru(j,1,m) scanf("%d",&p[i][j]);

   nA = 0;
   int c = 0;
   foru(j,2,m-int(n == 1)) a[nA++] = mp(mp(get_min(1,j),++c), mp(1,j));
   foru(i,2,n-1) a[nA++] = mp(mp(get_min(i,m),++c), mp(i,m));
   sort(a,a+nA);

   fill(b,0);
   fill(res,0);
   rep(i,nA) {
      int j = a[i].fr.sc;
      ll t = solve(j,1);
      if (t > 0 && t >= k) {
         b[j] = res[a[i].sc.fr][a[i].sc.sc] = 1;
      }
      else {
         b[j] = res[a[i].sc.fr][a[i].sc.sc] = -1;
         k -= t;
      }
   }
   res[1][1] = 1;
   res[n][m] = -1;

   foru(j,2,m) copy_res(2,j-1,res[1][j]);
   foru(i,2,n-1) copy_res(i+1,m-1,res[i][m]);

   foru(i,1,n) {
      foru(j,1,m)
         if (res[i][j] == 1) printf("(");
         else printf(")");
      printf("\n");
   }
   return 0;
}
