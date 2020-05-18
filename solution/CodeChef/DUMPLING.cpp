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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1010;
const int MODUN = 1000000007;

ll f[2][MAX_N], g[MAX_N];

ll gcd(ll a, ll b) {
   if ((a == 0) || (b == 0)) return a+b;
   return gcd(b, a%b);
}

int main() {
   freopen("DUMPLING.in", "r", stdin);
   freopen("DUMPLING.out", "w", stdout);
   int nTest;
   cin >> nTest;
   fab(i, 1, nTest) {
      ll a, b, c, d, k;
      cin >> a >> b >> c >> d >> k;
      ll d1 = gcd(a, b), d2 = gcd(c, d), d3 = gcd(d1, d2);
      double m = double(d1)*double(d2)/double(d3);
      if (m > k) cout << 1 << endl;
      else cout << 2*(k/ll(m))+1 << endl;
   }
   return 0;
}

