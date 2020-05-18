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

const int MAX_N = 100;

ll a[MAX_N], b[MAX_N], c[MAX_N];

void read(ll &x) {
   int n;
   scanf("%d",&n);
   x = n;
}

int main() {
   freopen("208D.in", "r", stdin);
   freopen("208D.out", "w", stdout);
   int n;
   scanf("%d",&n);
   foru(i,1,n) read(a[i]);
   foru(i,1,5) read(b[i]);

   ll s = 0;
   fill(c,0);
   foru(i,1,n) {
      s += a[i];
      ford(j,5,1) {
         c[j] += s/b[j];
         s %= b[j];
      }
   }
   foru(i,1,5) cout << c[i] << " ";
   cout << endl << s;
   return 0;
}
