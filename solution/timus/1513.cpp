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

const int MAX_N = 10010;

ll s[MAX_N];

ll get_s(int i, int j) {
   if (i == 0) return s[j];
   return s[j]-s[i-1];
}

ll solve(int n, int k) {
   if (k == 0) return 1;
   s[0] = 1;
   ll f = 0;
   foru(i,1,n) {
      f = get_s(max(0,i-k-1),i-1);
      s[i] = s[i-1]+f;
   }
   return f + get_s(max(0,n-k),n-1);
}

int main() {
   freopen("1513.in", "r", stdin);
   freopen("1513.out", "w", stdout);
   int n,k;
   scanf("%d%d",&n,&k);
   cout << solve(n,k);
   return 0;
}
