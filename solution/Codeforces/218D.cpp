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

const int MAX_N = 1000003;
const int oo = 1000000000;

ll n, r;
int res = oo;
int s[MAX_N], t[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void tryf(ll i, ll a, ll b, int last, int f) {
   if (f >= res) return;
   if (i > n) {
      if ((last == 0 && a == r) || (last == 1 && b == r)) {
         res = f;
         foru(i,1,n) t[i] = s[i];
      }
      return;
   }
   if (min(a+(n-i)*b, b+(n-i)*a) > r) return;
   s[i] = 0;
   tryf(i+1,a+b,b,0,f+(last == 0));
   s[i] = 1;
   tryf(i+1,a,a+b,1,f+(last == 1));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("218D.in", "r", stdin);
   freopen("218D.out", "w", stdout);
#endif
   cin >> n >> r;
   s[1] = 0;
   tryf(2,1,1,0,0);
   if (res >= oo) printf("IMPOSSIBLE");
   else {
      printf("%d\n",res);
      foru(i,1,n)
         if (t[i] == 0) printf("T");
         else printf("B");
   }
   return 0;
}
