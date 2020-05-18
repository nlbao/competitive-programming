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

void up(int x1, int y1, int x2, int y2, int x3, int y3) {
   if ((x1 == x2) && (y1 == y3)) cout << x3 << " " << y2 << endl;
   else cout << x2 << " " << y3 << endl;
}

int main() {
   freopen("181A.in", "r", stdin);
   freopen("181A.out", "w", stdout);
   int n, m, x1, x2, x3, y1, y2, y3;
   string s;
   scanf("%d%d", &n, &m);
   getline(cin, s);
   x1 = x2 = x3 = y1 = y2 = y3 = 0;
   foru(i, 1, n) {
      getline(cin, s);
      foru(j, 0, m-1)
         if (s[j] == '*')
            if (x1 == 0) { x1 = i;  y1 = j+1;   }
            else if (x2 == 0) {  x2 = i;  y2 = j+1;   }
            else {  x3 = i;  y3 = j+1;  }
   }
   if (((x1 == x2) && (y1 == y3)) || ((x1 == x3) && (y1 == y2))) up(x1, y1, x2, y2, x3, y3);
   else if (((x2 == x1) && (y2 == y3)) || ((x2 == x3) && (y2 == y1))) up(x2, y2, x1, y1, x3, y3);
   else up(x3, y3, x1, y1, x2, y2);
   return 0;
}

