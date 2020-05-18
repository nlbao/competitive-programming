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

const int MAX_N = 6111;

int f[MAX_N][3];

int solve(string s) {
   int n = size(s), t0 = 3, t1 = 0, t2 = 1;
   rep(i, n) f[i][0] = 0;
   rep(i, n-1) f[i][1] = 1-int(s[i] == s[i+1]);
   foru(len, 3, n) {
      int t = t1;
      t0 = t1; t1 = t2; t2 = t;
      rep(i, n) {
         int j = i+len-1;
         f[i][t2] = min(f[i+1][t1], f[i][t1])+1;
         if (s[i] == s[j]) f[i][t2] = min(f[i][t2], f[i+1][t0]);
      }
   }
   return f[0][t2];
}

int main() {
   freopen("AIBOHP.in", "r", stdin);
   freopen("AIBOHP.out", "w", stdout);
   int nTest;
   string s;
   cin >> nTest;
   getline(cin, s);
   rep(testid, nTest) {
      getline(cin, s);
      printf("%d\n", solve(s));
   }
   return 0;
}
