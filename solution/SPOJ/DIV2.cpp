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

const int N = 1000007;

int d[N], c[N];

int main() {
   freopen("DIV2.out", "w", stdout);
   fill(d,0);
   foru(i,1,N-1)
      for(int j = i; j < N; j += i)
         ++d[j];

   fill(c,0);
   foru(i,1,N-1)
      for(int j = i; j < N; j += i)
         if (d[j]%d[i] == 0) ++c[j];

   int cnt = 0;
   foru(i,3,1000000)
      if (d[i] > 3 && c[i] == d[i])
         if (++cnt == 108) {
            cout << i << endl;
            cnt = 0;
         }
   return 0;
}
