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

const int MAX_N = 100007;

struct node {
   ll v;
   int id;
};

struct cmp_hmin {
   bool operator() (const node& x, const node& y) {  return x.v > y.v;  }
};

struct cmp_hmax {
   bool operator() (const node& x, const node& y) {  return x.v < y.v;  }
};

int n, len, k;
ll a[MAX_N];
bool ok[MAX_N];
ll res;

priority_queue<node, vector<node>, cmp_hmin> hmin;
priority_queue<node, vector<node>, cmp_hmax> hmax;

void solve() {
   ll s = 0;
   fill(ok, false);
   while (!hmin.empty()) hmin.pop();
   while (!hmax.empty()) hmax.pop();
   foru(i, 1, len)
      if (a[i] >= 0) s += a[i];
      else {
         s -= a[i];
         ok[i] = true;
         node x = {-a[i], i};
         hmin.push(x);
         while (size(hmin) > k) {
            x = hmin.top();
            hmin.pop();
            hmax.push(x);
            s -= 2*x.v;
            ok[x.id] = false;
         }
      }
   res = max(res, abs(s));

   int del = 0;
   foru(i, len+1, n) {
      int j = i-len;
      if (a[j] >= 0) s -= a[j];
      else
         if (ok[j]) {
            s += a[j];
            ++del;
         }
         else s -= a[j];

      if (a[i] >= 0) s += a[i];
      else {
         s -= a[i];
         ok[i] = true;
         node x = {-a[i], i};
         hmin.push(x);
         while (size(hmin)-del > k)
             if (hmin.top().id <= i-len) {
               hmin.pop();
               --del;
            }
            else {
               x = hmin.top();
               hmin.pop();
               hmax.push(x);
               s -= 2*x.v;
               ok[x.id] = false;
            }
      }

      while (size(hmin)-del < k && size(hmax)) {
         node x = hmax.top();
         hmax.pop();
         if (x.id <= i-len) continue;
         hmin.push(x);
         s += 2*x.v;
         ok[x.id] = true;
      }

      while (size(hmin)-del == k && size(hmax)) {
         node x = hmin.top();
         node y = hmax.top();
         if (x.id <= i-len) {
            hmin.pop();
            --del;
         }
         else if (y.id <= i-len) hmax.pop();
         else if (x.v < y.v) {
            hmin.pop(); hmin.push(y);  ok[y.id] = true;
            hmax.pop(); hmax.push(x);  ok[x.id] = false;
            s += 2*(y.v-x.v);
         }
         else break;
      }
      res = max(res, abs(s));
   }
}

int main() {
   freopen("182C.in", "r", stdin);
   freopen("182C.out", "w", stdout);
   cin >> n >> len;
   foru(i, 1, n) {
      scanf("%d", &k);
      a[i] = k;
   }
   cin >> k;
   solve();
   foru(i, 1, n) a[i] = -a[i];
   solve();
   cout << res;
   return 0;
}
