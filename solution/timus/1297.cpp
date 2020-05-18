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

const int MAX_N = 1007;
const ll BASE = 10007;
const ll MODUN = 1000000009LL;

int n, nA, pos, len;
char s[MAX_N];
ll p[MAX_N], l[MAX_N], r[MAX_N];
int a[MAX_N];

ll mmod(ll x) {   while (x < 0) x += MODUN;  return x%MODUN;   }

ll get_l(int i, int j) {
   if (i == 0) return l[j];
   return mmod(l[j]-mmod(l[i-1]*p[j-i+1]));
}

ll get_r(int i, int j) {
   if (j == n-1) return r[i];
   return mmod(r[i]-mmod(r[j+1]*p[j-i+1]));
}

int find(int len) {
   rep(i,n-len+1) {
      int j = i+len-1;
      if (get_l(i,j) == get_r(i,j)) return i;
   }
   return -1;
}

void up() {
   int left = 1, right = nA;
   while (left <= right) {
      int mid = (left+right)/2, t = find(a[mid]);
      if (t > -1) {
         if (a[mid] > len) {
            len = a[mid];
            pos = t;
         }
         left = mid+1;
      }
      else right = mid-1;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1297.in", "r", stdin);
   freopen("1297.out", "w", stdout);
#endif
   scanf("%s", s);
   n = strlen(s);

   if (n == 1) {
      cout << s << endl;
      return 0;
   }

   p[0] = 1;
   foru(i,1,n+1) p[i] = (p[i-1]*BASE)%MODUN;
   l[0] = s[0];
   foru(i,1,n-1) l[i] = (l[i-1]*BASE + ll(s[i]))%MODUN;
   r[n-1] = s[n-1];
   ford(i,n-2,0) r[i] = (r[i+1]*BASE + ll(s[i]))%MODUN;

   pos = 0, len = 1;
   nA = 0;
   foru(i,2,n) if (i%2 == 0) a[++nA] = i;
   up();
   nA = 0;
   foru(i,2,n) if (i%2 == 1) a[++nA] = i;
   up();
   foru(i,pos,pos+len-1) printf("%c",s[i]);
   return 0;
}
