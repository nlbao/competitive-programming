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

const ll MODUN = 1000000007;

struct mat {
   ll a[2][2];
} p;


mat mat_mul(mat x, mat y) {
   mat z;
   fill(z.a, 0);
   foru(i, 0, 1)
      foru(j, 0, 1)
         foru(k, 0, 1)
            z.a[i][j] = (z.a[i][j]+(x.a[i][k]*y.a[k][j])%MODUN)%MODUN;
   return z;
}

mat mat_pow(mat p, ll n) {
   if (n < 2) return p;
   mat t = mat_pow(p, n/2);
   t = mat_mul(t, t);
   if (n%2 == 0) return t;
   else return mat_mul(t, p);
}

int main() {
   freopen("186C.in", "r", stdin);
   freopen("186C.out", "w", stdout);
   ll n;
   cin >> n;
   if (n < 1) cout << 1;
   else {
      p.a[0][0] = p.a[1][1] = 3;
      p.a[0][1] = p.a[1][0] = 1;
      p = mat_pow(p, n);
      cout << p.a[0][0];
   }
   return 0;
}
