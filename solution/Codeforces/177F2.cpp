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

const int MAX_N = 22;

int n, m, t, sum = 0, top = 0;
vector< PI > e[MAX_N];
bool ok[MAX_N];
int h[222222];

void swap(int &x, int &y) {   int t = x;  x = y;   y = t;   }

void down_heap(int i) {
   int j = i<<1;
   if (j < top && h[j+1] > h[j]) ++j;
   if (j > top || h[j] <= h[i]) return;
   swap(h[i], h[j]);
   down_heap(j);
}

void up_heap(int i) {
   int j = i>>1;
   if (j < 1 || h[j] >= h[i]) return;
   swap(h[i], h[j]);
   up_heap(j);
}

void gen(int i) {
   if (top == t && sum > h[1]) return;
   if (i > n) {
      if (top == t) {
         h[1] = sum;
         down_heap(1);
      }
      else {
         h[++top] = sum;
         up_heap(top);
      }
      return;
   }
   gen(i+1);
   rep(j, e[i].size()) {
      int v = e[i][j].sc;
      if (ok[v]) {
         ok[v] = false;
         sum += e[i][j].fr;
         gen(i+1);
         sum -= e[i][j].fr;
         ok[v] = true;
      }
   }
}

int main() {
   freopen("177F1.in", "r", stdin);
   freopen("177F1.out", "w", stdout);
   cin >> n >> m >> t;
   foru(i, 1, m) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      e[x].pb(mp(w, y));
   }
   fill(ok, true);
   gen(1);
   cout << h[1];
   return 0;
}

