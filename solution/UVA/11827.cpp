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

const int MAX_N = 110;

int a[MAX_N];
string s;

int gcd(int x, int y) {
   if (x == 0 || y == 0) return x+y;
   return gcd(y,x%y);
}

int main() {
   freopen("11827.in", "r", stdin);
   freopen("11827.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   getline(cin,s);
   rep(id,nTest) {
      getline(cin,s);
      int n = 0, d = 0, m = size(s), i = 0;
      while(i < m) {
         a[n] = 0;
         while(i < m && s[i] != ' ')
            a[n] = a[n]*10+(s[i++]-'0');
         ++n;
         while (i < m && s[i] == ' ') ++i;
      }

      rep(i,n)
         foru(j,i+1,n-1) d = max(d,gcd(a[i],a[j]));
      printf("%d\n",d);
   }
   return 0;
}
