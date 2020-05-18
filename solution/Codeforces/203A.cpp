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

int x,t,a,b,da,db;

string solve() {
   //int r = a+b-x;
   rep(i,t)
      rep(j,t)
         if ((a-i*da)+(b-j*db) == x) {
            //cout << i << " " << j << endl;
            return "YES";
         }
   return "NO";
}

int main() {
   freopen("203A.in", "r", stdin);
   freopen("203A.out", "w", stdout);
   cin >> x >> t >> a >> b >> da >> db;
   cout << solve();
   return 0;
}
