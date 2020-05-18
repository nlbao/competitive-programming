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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int> > vii;

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

const int MAX_N = 10004;

int n, k;
int a[MAX_N];
ll f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll mmod(ll x) {   return x%1000000007; }

ll mpow(ll a, ll x) {
   if (x == 0) return 1;
   if (x == 1) return a;
   ll t = mpow(a,x>>1);
   t = mmod(t*t);
   if (x&1) return mmod(t*a);
   return t;
}

ll inv(ll x) { return mpow(x,1000000005); }

int solve() {
   f[0] = 1;
   foru(i,1,n) f[i] = mmod(f[i-1]*ll(i));
   ll tmp = 1;
   foru(i,1,k-1) tmp = mmod(tmp*ll(i));
   tmp = inv(tmp);

   sort(a+1,a+n+1);
   ll res = 0;
   foru(i,k,n) res = mmod(res + mmod(mmod(f[i-1]*inv(f[i-k])) * mmod(tmp*ll(a[i]))) );
   return res;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1_.in", "r", stdin);
   freopen("1.out", "w", stdout);
#endif
   int nTest = read();
   foru(test_id, 1, nTest) {
      scanf("%d%d",&n,&k);
      foru(i,1,n) a[i] = read();
      printf("Case #%d: %d\n",test_id,solve());
   }
   return 0;
}
