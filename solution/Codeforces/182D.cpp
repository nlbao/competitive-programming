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

string s, t;
bool f[MAX_N], g[MAX_N];
char c1[MAX_N], c2[2*MAX_N];
int p[MAX_N];
VI a;

void pre(string s) {
   a.clear();
   int n = s.size();
   rep(i, n) c1[i+1] = c2[i+1] = s[i];
   foru(i, n+1, 2*n) c2[i] = c1[i-n];
   int j = 0;
   p[1] = 0;
   foru(i, 2, n) {
      while (j > 0 && c1[j+1] != c1[i]) j = p[j];
      if (c1[j+1] == c1[i]) ++j;
      p[i] = j;
   }
   j = 0;
   foru(i, 1, 2*n) {
      while (j > 0 && c1[j+1] != c2[i]) j = p[j];
      if (c1[j+1] == c2[i]) ++j;
      if (j == n) {
         if (i > n && n%(i-n) == 0) a.pb(i-n);
         j = p[j];
      }
   }
}

int main() {
   freopen("182D.in", "r", stdin);
   freopen("182D.out", "w", stdout);
   getline(cin, s);
   getline(cin, t);
   pre(s);
   fill(f, false);
   rep(i, a.size()) f[a[i]] = true;
   pre(t);
   fill(g, false);
   rep(i, a.size()) g[a[i]] = true;
   int res = 0;
   rep(i, min(s.size(), t.size()))
      if (s[i] != t[i]) break;
      else res += int(f[i+1] && g[i+1]);
   cout << res;
   return 0;
}
