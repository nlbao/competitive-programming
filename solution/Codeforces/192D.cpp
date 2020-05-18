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

const int MAX_N = 100007;

int n, k;
ll b;
int a[MAX_N], p[MAX_N];
vector<pair<ll,int> > v;
ll s[MAX_N];

ll get_s(int i, int j) {
   if (i > j) return 0;
   if (i == 0) return s[j];
   return s[j]-s[i-1];
}

int main() {
   freopen("192D.in", "r", stdin);
   freopen("192D.out", "w", stdout);
   cin >> n >> k >> b;
   foru(i, 1, n) {
      scanf("%d", &a[i]);
      if (i < n) v.pb(mp(a[i],i));
   }
   sort(all(v));
   s[0] = v[0].fr;
   rep(i, n-1) {
      p[v[i].sc] = i;
      if (i) s[i] = s[i-1]+v[i].fr;
   }

   --k;
   int m = n-2, res = n;
   foru(i, 1, n-1) {
      ll sum = 0;
      if (m-p[i] >= k) sum = get_s(m-k+1,m);
      else {
         sum = get_s(p[i]+1,m);
         sum += get_s(m-k,p[i]-1);
      }

      if (b-sum < a[i]) {
         res = i;
         break;
      }
   }
   cout << res;
   return 0;
}
