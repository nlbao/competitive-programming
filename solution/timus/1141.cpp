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

int e, n, c;

int mpow(int x, int a) {
   if (a == 0) return 1;
   if (a == 1) return x%n;
   int t = mpow(x,a/2);
   t = (t*t)%n;
   if (a%2 == 0) return t;
   else return (t*x)%n;
}

int main() {
   freopen("1141.in", "r", stdin);
   freopen("1141.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d%d%d",&e,&n,&c);
      c %= n;
      cout << "   " << n << endl;
      rep(i,30*n)
         if (mpow(i,e) == c) {
            printf("%d\n",i);
            break;
         }
   }
   return 0;
}
