#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100010;

int n, m;
string names[MAX_N];
int p[MAX_N];

int find(string s) {
   int i = 1;
   while ((i <= n) && (names[i] != s)) ++i;
   if (i > n) {
      names[++n] = s;
      p[n] = -1;
   }
   return i;
}

int get_root(int u) {
   if (p[u] < 0) return u;
   return (p[u] = get_root(p[u]));
}

void solve() {
   n = 0;
   cin >> m;
   string s;
   getline(cin, s);
   fab(i, 1, m) {
      getline (cin, s);
      int j = 0;
      while (s[j] != ' ') ++j;
      int u = find(string (s.begin(), s.begin()+j));
      int v = find(string (s.begin()+j+1, s.end()));
      int r1 = get_root(u), r2 = get_root(v);
      if (r1 != r2) {
         p[r1] += p[r2];
         p[r2] = r1;
      }
      cout << -p[r1] << endl;
   }
}

int main() {
   freopen("100008A.in", "r", stdin);
   freopen("100008A.out", "w", stdout);
   int nTest;
   cin >> nTest;
   fab(i, 1, nTest) solve();
   return 0;
}
