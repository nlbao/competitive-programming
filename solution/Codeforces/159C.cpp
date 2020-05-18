#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 20007;
const int MAX_M = 200007;

int n, k, m;
string s = "", t;
int c[30];
bool ok[MAX_M];
int f[MAX_M][30];

int num(char x) { return (int(x)-int('a'));  }

void update(int i, int x, int value) {
   if ((i < 1) || (i > m)) return;
   //cout << i << " " << x << " " << value << endl;
   f[i][x] += value;
   update(i+(i&(-i)), x, value);
}

int get(int i, int x) {
   if ((i < 1) || (i > m)) return 0;
   return (f[i][x]+get(i-(i&(-i)), x));
}

int main() {
   freopen("159C.in", "r", stdin);
   freopen("159C.out", "w", stdout);
   cin >> k;
   getline(cin, t);
   getline(cin, t);
   fab(i, 1, k) s += t;
   m = s.size();

   fill(c, 0);
   fill(f, 0);
   fill(ok, true);
   fab(i, 0, m-1)
      update(i+1, num(s[i]), 1);

   cin >> n;
   fab(i, 1, n) {
      int p;   char c;
      getline(cin, t);
      cin >> p >> c;
      int x = num(c), l = 1, r = m, j = 1;
      while (l <= r) {
         int mid = (l+r)/2, tmp = get(mid, x);
         if (tmp < p) l = mid+1;
         else if (tmp > p) r = mid-1;
         else {
            j = mid;
            r = mid-1;
         }
      }
      ok[j-1] = false;
      update(j, x, -1);
   }

   fab(i, 0, m-1)
      if (ok[i]) cout << s[i];
   cout << endl;
   return 0;
}


