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

double sqr(double x) {  return x*x; }

double solve() {
   double x1, y1, r1, x2, y2, r2;
   cin >> x1 >> y1 >> r1;
   cin >> x2 >> y2 >> r2;
   double d = sqrt(sqr(x1-x2)+sqr(y1-y2));
   if (d >= r1+r2) return (d-r1-r2)/2;
   return (r1+r2-d)/2;
}

int main() {
   freopen("190B.in", "r", stdin);
   freopen("190B.out", "w", stdout);
   printf("%.7f", solve());
   return 0;
}
