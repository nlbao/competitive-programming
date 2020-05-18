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

const int MAX_N = 207;

int n;
int a[MAX_N];
vector<double> b;
double s;

double find(double p, double x, double minV) {
   double l = 0, r = p, res = p;
   rep(i, 50) {
      double mid = (l+r)/2;
      if (x+mid*s >= minV) {
         res = mid;
         r = mid;
      }
      else l = mid;
   }
   return res;
}

bool check(double p, double minV) {
   rep(i, n-1) {
      if (b[i]+p*s <= minV) return true;
      p -= find(p, b[i], minV);
   }
   return false;
}

double solve(int id) {
   b.clear();
   rep(i, n) if (i != id) b.pb(a[i]);
   sort(all(b));
   double l = 0, r = 1, res = 1;
   rep(i, 100) {
      double mid = (l+r)/2;
      if (check(1-mid, a[id]+mid*s)) {
         res = mid;
         r = mid;
      }
      else l = mid;
   }
   return res*100;
}

int main() {
   freopen("A1.in", "r", stdin);
   freopen("A.out", "w", stdout);
   int nTest;
   cin >> nTest;
   foru(testid, 1, nTest) {
      scanf("%d", &n);
      s = 0;
      rep(i, n) {
         scanf("%d", &a[i]);
         s += a[i];
      }
      printf("Case #%d:", testid);
      rep(i, n) printf(" %.6f ", solve(i));
      printf("\n");
   }
   return 0;
}
