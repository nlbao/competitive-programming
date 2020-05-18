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

const ll MODUN = 1000000007LL;
const int MAX_P = 1000000;

struct mat {
   ll x[4][4];
};

mat base;
int p[MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x) {   while (x < 0) x += MODUN;  return x%MODUN;   }

mat mul_mat(mat a, mat b) {
   mat c;
   rep(i,3)
      rep(j,3) {
         c.x[i][j] = 0;
         rep(k,3)
            c.x[i][j] = (c.x[i][j]+a.x[i][k]*b.x[k][j])%MODUN;
      }
   return c;
}

mat pow_mat(ll n) {
   if (n == 1) return base;
   mat t = pow_mat(n/2);
   t = mul_mat(t,t);
   if (n%2 == 0) return t;
   else return mul_mat(t,base);
}

ll pow2(ll a) {
   if (a == 0) return 1;
   if (a < MAX_P) return p[a];
   ll t = pow2(a/2);
   t = (t*t)%MODUN;
   if (a%2 == 0) return t;
   else return (t*2)%MODUN;
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("CROWD.in", "r", stdin);
   freopen("CROWD.out", "w", stdout);
#endif
   fill(base.x,0);
   rep(i,3) base.x[i][0] = 1;
   base.x[0][1] = base.x[1][2] = 1;
   p[0] = 1;
   foru(i,1,MAX_P-1) p[i] = (p[i-1]*2)%MODUN;

   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      ll n;
      scanf("%I64d",&n);
      if (n < 3) printf("0\n");
      else {
         mat a = pow_mat(n-1);
         ll t = (a.x[0][1]+a.x[1][1])%MODUN;
         rep(i,3) t = (t+a.x[i][0])%MODUN;
         printf("%d\n",mmod(pow2(n)-t));
      }   }
   return 0;
}
