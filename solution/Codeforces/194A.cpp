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

const int MAX_K = 255;

int n, k;
bool ok[MAX_K];

int main() {
   freopen("194A.in", "r", stdin);
   freopen("194A.out", "w", stdout);
   int n, k, res = 0;
   cin >> n >> k;
   foru(x,0,n)
      foru(y,0,n-x)
         foru(z,0,n-x-y) {
            int t = n-x-y-z;
            if (t < 0) continue;
            if (2*x+3*y+4*z+5*t == k) {
               cout << x;
               return 0;
            }
         }
   cout << 0;
   return 0;
}
