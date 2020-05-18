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

const int MAX_N = 104;
const int MAX_K = MAX_N*MAX_N;
const ll MODUN = 1000000007LL;

ll n,m,k;
ll c[MAX_N][MAX_N], f[MAX_N][MAX_K], r[MAX_N], v[MAX_N][MAX_N];
int g[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x) {   return x%MODUN;   }

ll pow(ll x, ll a) {
   if (a == 0) return 1;
   if (a == 1) return mmod(x);
   ll t = pow(x,a/2);
   t = mmod(t*t);
   if (a%2 == 0) return t;
   else return mmod(t*x);
}

void cal_c() {
   fill(c,0);
   c[0][0] = 1;
   foru(i,1,n) {
      c[i][0] = 1;
      foru(j,1,i) c[i][j] = mmod(c[i-1][j]+c[i-1][j-1]);
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("232B.in", "r", stdin);
   freopen("232B.out", "w", stdout);
#endif
   n = read();
   scanf("%I64d",&m);
   k = read();

   cal_c();
   for(ll i = 1; i <= n; ++i) {
      g[i] = min(n*i,k);
      r[i] = (m-i)/n;
      while (i+r[i]*n <= m) ++r[i];
      foru(j,0,n) v[i][j] = pow(c[n][j],r[i]);
   }

   fill(f,0);
   f[1][0] = 1;
   foru(j,1,g[1]) f[1][j] = pow(c[n][j],r[1]);
   foru(i,2,n)
      foru(j,0,g[i])
         foru(jj, max(int(j-n),0), min(j,g[i-1]))
            f[i][j] = mmod(f[i][j] + mmod(f[i-1][jj]*v[i][j-jj]));

   cout << f[n][k] << endl;
   return 0;
}
