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

VI p;

string solve(string s, string t) {
   if (size(s) < 1 || size(t) < 1 || size(s) != size(t)) return "NO";
   rep(i, size(s))
      if (s[i] != t[i]) p.pb(i);
   if (size(p) != 2) return "NO";
   if (s[p[0]] != t[p[1]] || s[p[1]] != t[p[0]]) return "NO";
   return "YES";
}

int main() {
   freopen("186A.in", "r", stdin);
   freopen("186A.out", "w", stdout);
   string s, t;
   getline(cin, s);
   getline(cin, t);
   cout << solve(s, t) << endl;
   return 0;
}
