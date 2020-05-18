#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 30010;
const int MAX_M = 200010;

int n, m;
vector < PI > a;
vector < pair < PI, PI > > b;
int f[MAX_N], res[MAX_M];

void update(int i) {
   if ((i < 1) || (i > n)) return;
   ++f[i];
   update(i+(i&(-i)));
}

int get(int i) {
   if ((i < 1) || (i > n)) return 0;
   return f[i]+get(i-(i&(-i)));
}

int main() {
   freopen("KQuery.in", "r", stdin);
   freopen("KQuery.out", "w", stdout);
   cin >> n;
   fab(i, 1, n) {
      int x;
      scanf("%d", &x);
      a.pb(mp(x, i));
   }
   cin >> m;
   fab(i, 1, m) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      b.pb(mp(mp(z, i), mp(x, y)));
   }
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());

   fill(f, 0);
   int j = n-1;
   fba(i, m-1, 0) {
      while ((j >= 0) && (a[j].fr > b[i].fr.fr)) {
         update(a[j].sc);
         --j;
      }
      res[b[i].fr.sc] = get(b[i].sc.sc)-get(b[i].sc.fr-1);
   }
   fab(i, 1, m) printf("%d\n", res[i]);
   return 0;
}


