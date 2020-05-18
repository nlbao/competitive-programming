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

const int MAX_P = 1000000;
const ll MODUN = 1000000007LL;

int p[MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x)  {  while (x < 0) x += MODUN;  return x%MODUN;   }

ll pow2(ll a) {
   if (a == 0) return 1;
   if (a < MAX_P) return p[a];
   ll t = pow2(a/2);
   t = mmod(t*t);
   if (a%2 == 0) return t;
   else return mmod(t*2);
}

ll cal(ll n) {
   if (n == 0) return 1;
   if (n == 1) return 2;
   ll s = cal(n/2);
   ll t = mmod(s*(pow2(n/2)+1));
   if (n%2 == 0) return t;
   else return mmod(t+pow2(n));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("CKISSHUG.in", "r", stdin);
   freopen("CKISSHUG.out", "w", stdout);
#endif
   p[0] = 1;
   foru(i,1,MAX_P-1) p[i] = (p[i-1]*2)%MODUN;
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      ll n = read();
      if (n == 1) printf("2\n");
      else if (n == 2) printf("4\n");
      else
         if (n%2 == 1) printf("%d\n",mmod(mmod(cal(n/2)*2)+2));
         else printf("%d\n",mmod(mmod(cal(n/2-1)*2)+pow2(n/2)+2));
   }
   return 0;
}
