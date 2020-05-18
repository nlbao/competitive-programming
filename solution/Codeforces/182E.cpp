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

const int MAX_N = 102;
const int MAX_L = 3002;
const int MAX_A = 102;
const ll MODUN = 1000000007;

int n, l;
VI h, w, types;
VI e[2*MAX_N];
ll f[MAX_L][2*MAX_N];


ll mmod(int x) {  while (x < 0) x += MODUN;   return x%MODUN;   }

void add(int h0, int w0, int t0) {
   h.pb(h0);
   w.pb(w0);
   types.pb(t0);
}

void upF(int i, int j, ll value) {  if (i <= l) f[i][j] = mmod(f[i][j]+value);   }

int main() {
   freopen("182E.in", "r", stdin);
   freopen("182E.out", "w", stdout);
   cin >> n >> l;
   foru(i, 1, n) {
      int x, y;
      scanf("%d%d", &x, &y);
      add(x, y, i);
      if (x != y) add(y, x, i);
   }

   n = h.size();
   rep(i, n)
      rep(j, n)
         if (types[j] != types[i] && h[j] == w[i]) e[i].pb(j);

   fill(f, 0);
   rep(i, n) ++f[h[i]][i];
   foru(i, 1, l)
      rep(j, n) if (f[i][j])
         rep(k, e[j].size()) {
            int jj = e[j][k];
            upF(i+h[jj],jj,f[i][j]);
         }

   ll res = 0;
   rep(i, n) res = mmod(res+f[l][i]);
   cout << res;
   return 0;
}
