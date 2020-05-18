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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_B = 2000007;

ll f[MAX_B];
int turn[MAX_B];
int x[20];

int main() {
   freopen("C.in", "r", stdin);
   freopen("C.out", "w", stdout);

   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) {
      int a, b;
      scanf("%d%d", &a, &b);
      ll res = 0;
      fill(turn, 0);
      foru(num, a, b) {
         int n = num;
         turn[n] = n;
         int nDigit = 0;
         while (n > 0) {
            x[++nDigit] = n%10;
            n /= 10;
         }
         n = num;
         foru(i, 1, nDigit-1) {
            int y = 0;
            ford(j, i, 1) y = y*10+x[j];
            ford(j, nDigit, i+1) y = y*10+x[j];
            if ((y > b) || (y <= n)) continue;
            if (turn[y] != n) {
               turn[y] = n;
               ++res;
            }
         }
      }
      cout << "Case #" << testid << ": " << res << endl;
   }
   return 0;
}

