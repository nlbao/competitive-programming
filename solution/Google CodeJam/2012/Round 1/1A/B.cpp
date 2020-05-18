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

const int MAX_N = 1111;



int n;
int a[MAX_N], b[MAX_N], c[MAX_N], ida[MAX_N], idb[MAX_N];

bool cmp_a(int x, int y)  {   return a[x] < a[y];  }

bool cmp_b(int x, int y)  {   return b[x] < b[y];  }

struct cmp_hmax {
   bool operator() (const int& x, const int& y) {  return b[x] < b[y];  }
};

priority_queue <int , VI, cmp_hmax> h;

int solve() {
   sort(ida, ida+n, cmp_a);
   sort(idb, idb+n, cmp_b);
   while (!h.empty()) h.pop();
   int res = 0, star = 0, pa = 0, pb = 0;
   fill(c,0);

   for (int i = 0; pb < n; ++i) {
      while (pb < n) {
         int j = idb[pb];
         if (b[j] > star) break;
         else {
            ++res;
            star += 2-c[j];
            c[j] = 2;
            ++pb;
         }
      }
      if (pb >= n) break;

      while (pa < n) {
         int j = ida[pa];
         if (a[j] > star) break;
         else {
            if (c[j] < 2) h.push(j);
            ++pa;
         }
      }

      while (!h.empty()) {
         int j = h.top();
         h.pop();
         if (!c[j]) {
            ++res;
            ++star;
            c[j] = 1;
            break;
         }
      }

      if (i > 2*n) return -1;
   }
   return res;
}

int main() {
   freopen("B.in", "r", stdin);
   freopen("B.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) {
      scanf("%d", &n);
      rep(i, n) {
         scanf("%d%d", &a[i], &b[i]);
         ida[i] = idb[i] = i;
      }
      int res = solve();
      if (res == -1) printf("Case #%d: Too Bad\n", testid);
      else printf("Case #%d: %d\n", testid, res);
   }
   return 0;
}
