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

int n;
double t1, t2, k;
vector<pair<double, int> > res;

double f(double a, double b) {  return a*t1*(100-k)/100+b*t2; }

int main() {
   freopen("186B.in", "r", stdin);
   freopen("186B.out", "w", stdout);
   cin >> n >> t1 >> t2 >> k;
   foru(i, 1, n) {
      int a, b;
      scanf("%d%d", &a, &b);
      res.pb(mp(-max(f(a,b), f(b,a)), i));
   }
   sort(all(res));
   rep(i, n) printf("%d %.2f\n", res[i].sc, -res[i].fr);
   return 0;
}
