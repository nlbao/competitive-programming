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

int s[MAX_N];
ll f[MAX_N];

int main() {
   freopen("1031.in", "r", stdin);
   freopen("1031.out", "w", stdout);
   int l1,l2,l3,n,p1,p2;
   ll c1,c2,c3;
   scanf("%d%d%d%",&l1,&l2,&l3);
   cin >> c1 >> c2 >> c3;
   scanf("%d",&n);
   scanf("%d%d",&p1,&p2);
   foru(i,2,n) scanf("%d",&s[i]);

   if (p1 > p2) {
      int t = p1;
      p1 = p2;
      p2 = t;
   }

   f[p1] = 0;
   int a1,a2,a3;
   a1 = a2 = a3 = p1;
   foru(i,p1+1,p2) {
      while (s[i]-s[a1] > l1) ++a1;
      while (s[i]-s[a2] > l2) ++a2;
      while (s[i]-s[a3] > l3) ++a3;
      ll t = f[a3]+c3;
      if (a1 < i) t = min(t,f[a1]+c1);
      if (a2 < i) t = min(t,f[a2]+c2);
      f[i] = t;
   }
   cout << f[p2];
   return 0;
}
