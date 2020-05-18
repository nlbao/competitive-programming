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

const int MAX_N = 1000003;
const int MAX_P = 80000;

int a,b,k;
bool ok[MAX_N];
int s[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool check(int len) {
   foru(i,a,b-len+1)
      if (s[i+len-1]-s[i-1] < k) return false;
   return true;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("237C.in", "r", stdin);
   freopen("237C.out", "w", stdout);
#endif
   scanf("%d%d%d",&a,&b,&k);
   fill(ok,true);
   s[1] = 0;
   for(ll i = 2; i <= b; ++i) {
      s[i] = s[i-1];
      if (ok[i]) {
         ++s[i];
         for(ll j = i*i; j <= b; j += i)
            ok[j] = false;
      }
   }
   int res = -1;
   int l = k, r = b-a+1;
   while (l <= r) {
      int mid = (l+r) >> 1;
      if (check(mid)) {
         res = mid;
         r = mid-1;
      }
      else l = mid+1;
   }
   cout << res;
   return 0;
}
