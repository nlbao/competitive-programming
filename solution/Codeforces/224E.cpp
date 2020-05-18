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

const int MAX_N = 2004;
const ll MODUN = 1000000007LL;

ll v[MAX_N], f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x) {
   x %= MODUN;
   return (x+MODUN)%MODUN;
}

ll mpow(ll x, ll a) {
   if (a == 0) return 1;
   if (a == 1) return mmod(x);
   ll t = mpow(x,a/2);
   t = mmod(t*t);
   if (a%2 == 1) return mmod(t*x);
   return t;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("224E.in", "r", stdin);
   freopen("224E.out", "w", stdout);
#endif
   ll n, k;
   cin >> n >> k;
   --k;
   rep(i,n) scanf("%I64d",&v[i]);

   fill(f,0);
   f[0] = 1;
   ll a = 1, b = 1;
   for(ll i = 1; i <= n; ++i) {
      a = mmod(a*i);
      b = mmod(b*(k+i));
      f[i] = mmod(b*mpow(a,MODUN-2));
   }

   rep(i,n) {
      ll s = 0;
      ford(j,i,0)
         s = mmod(s+mmod(f[i-j]*v[j]));
      printf("%I64d ",s);
   }
   return 0;
}
