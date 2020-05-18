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

const int MAX_M = 55;
const ll MODUN = 1000000007LL;

struct mat {
   ll x[MAX_M][MAX_M];
};

int m;
mat base, b;

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x)  {  return ((x%MODUN)+MODUN)%MODUN;  }

int num(char x) {
   if (x > 'Z') return x-'a'+1;
   return x-'A'+27;
}

mat mat_mul(mat a, mat b) {
   mat c;
   fill(c.x,0);
   foru(i,1,m)
      foru(j,1,m)
         foru(k,1,m)
            c.x[i][j] = mmod(c.x[i][j] + mmod(a.x[i][k]*b.x[k][j]));
   return c;
}

mat mat_pow(ll n) {
   if (n == 1) return base;
   mat c = mat_pow(n/2);
   c = mat_mul(c,c);
   if (n%2 == 0) return c;
   else return mat_mul(c,base);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("222E.in", "r", stdin);
   freopen("222E.out", "w", stdout);
#endif
   ll n;
   int k;
   cin >> n >> m >> k;
   foru(i,1,m)
      foru(j,1,m) base.x[i][j] = 1;
   rep(i,k) {
      getchar();
      int a = num(getchar()), b = num(getchar());
      base.x[a][b] = 0;
   }

   if (n == 1) {
      printf("%d",m);
      return 0;
   }

   mat b = mat_pow(n-1);
   ll res = 0;
   foru(i,1,m)
      foru(j,1,m) res = mmod(res+b.x[i][j]);
   cout << res;
   return 0;
}
