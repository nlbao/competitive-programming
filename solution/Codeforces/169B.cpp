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

int num(char x)   {  return x-'0';  }

int main() {
   freopen("169B.in", "r", stdin);
   freopen("169B.out", "w", stdout);
   string s, t;
   cin >> s >> t;
   int c[10];
   fill(c, 0);
   rep(i, size(t)) ++c[num(t[i])];
   rep(i, size(s)) {
      ford(j, 9, num(s[i])+1)
         if (c[j]) {
            s[i] = char(j+int('0'));
            --c[j];
            break;
         }

   }
   cout << s << endl;
   return 0;
}
