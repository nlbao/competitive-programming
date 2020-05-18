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

const int MAX_N = 100007;

int s[MAX_N];

int is_up(char c) { if (int(c) < int('a')) return 1;  return 0;   }

int main() {
   freopen("180C.in", "r", stdin);
   freopen("180C.out", "w", stdout);
   string a;
   getline(cin, a);
   int n = a.size(), res = n;
   s[0] = is_up(a[0]);
   foru(i, 1, n-1) s[i] = s[i-1]+is_up(a[i]);
   res = min(res, min(s[n-1], n-s[n-1]));
   foru(i, 0, n-1)
      res = min(res, (i+1-s[i])+(s[n-1]-s[i]));
   cout << res << endl;
   return 0;
}
