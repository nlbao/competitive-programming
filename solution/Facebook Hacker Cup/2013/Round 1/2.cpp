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
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int> > vii;
typedef vector<string> vs;

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

const int MAX_N = 111;

int n, len;
vs a, b;
vi e[MAX_N];
int d[MAX_N], q[MAX_N], matchX[MAX_N], matchY[MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }

void enter(vs &a) {
   a.clear();
   a.pb("");
   char s[MAX_N];
   scanf("%s",&s);
   len = strlen(s);
   int d = len/n;
   string t = "";
   foru(i,1,len) {
      t += s[i-1];
      if (i%d == 0) {
         a.pb(t);
         t = "";
      }
   }
   len = d;
}

bool check(string s, string t) {
   int n = size(s);
   rep(i,len)
      if (s[i] != t[i] && s[i] != '?' && t[i] != '?') return false;
   return true;
}

int cmp(string s1, string s2, string t) {
   rep(i,len)
      if (t[i] != '?') continue;
      else if (s1[i] != s2[i])
         if (s1[i] == '?') return -1;
         else if (s2[i] == '?') return 1;
         else if (s1[i] < s2[i]) return -1;
         else return 1;
   return 0;
}

bool bfs() {
   int l = 1, r = 0;
   fill(d,0);
   foru(i,1,n)
      if (!matchX[i]) {
         d[i] = 1;
         q[++r] = i;
      }

   while (l <= r) {
      int u = q[l++];
      for(int sz = size(e[u]), i = 0; i < sz; ++i) {
         int v = matchY[e[u][i]];
         if (!d[v]) {
            d[v] = d[u]+1;
            if (v == 0) return true;
            q[++r] = v;
         }
      }
   }
   return false;
}

bool dfs(int u) {
   if (!u) return true;
   for(int sz = size(e[u]), i = 0; i < sz; ++i) {
      int y = e[u][i], v = matchY[y];
      if (d[v] == d[u]+1 && dfs(v)) {
         matchX[u] = y;
         matchY[y] = u;
         return true;
      }
   }
   return false;
}

string solve() {
   foru(i,1,n) {
      e[i].clear();
      foru(j,1,n)
         if (check(a[i],b[j])) e[i].pb(j);
      int sz = size(e[i]);
      rep(x,sz)
         foru(y,x+1,sz-1)
            if (cmp(b[e[i][x]],b[e[i][y]],a[i]) < 0)
               swap(e[i][x],e[i][y]);
   }

   int res = 0;
   fill(matchX,0);
   fill(matchY,0);
   while (bfs())
      foru(i,1,n)
         if (!matchX[i] && dfs(i)) ++res;

   if (res < n) return "IMPOSSIBLE";
   string s = "";
   foru(i,1,n) {
      int j = matchX[i];
      rep(k,len)
         if(a[i][k] != '?') s += a[i][k];
         else if (b[j][k] != '?') s += b[j][k];
         else s += 'a';
   }
   return s;
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("2_.in", "r", stdin);
   freopen("2.out", "w", stdout);
#endif
   int nTest;
   scanf("%d",&nTest);
   foru(test_id, 1, nTest) {
      scanf("%d",&n);
      enter(a);
      enter(b);
      cout << "Case #" << test_id << ": " << solve() << endl;
   }
   return 0;
}
