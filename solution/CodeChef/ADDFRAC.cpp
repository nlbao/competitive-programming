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

const int MAX_N = 100007;

ll a[MAX_N], b[MAX_N], ra[MAX_N], rb[MAX_N];

ll gcd(ll a, ll b) {
   if ((a == 0) || (b == 0)) return (a+b);
   return gcd(b, a%b);
}

int main() {
   freopen("ADDFRAC.in", "r", stdin);
   freopen("ADDFRAC.out", "w", stdout);
   int nTest, n;
   string s;
   cin >> nTest;
   rep(idtest, nTest) {
      scanf("%d", &n);
      getline(cin,s);
      foru(j, 1, n) {
         getline(cin,s);
         a[j] = b[j] = 0;
         int k = 0;
         while (k < s.size()) {
            if (s[k] == '/') break;
            else a[j] = a[j]*10+int(s[k])-int('0');
            ++k;
         }
         ++k;
         while (k < s.size()) {
            b[j] = b[j]*10+int(s[k])-int('0');
            ++k;
         }
      }
      ll c = a[n], d = b[n];
      ford(i, n, 1) {
         if (a[i]*d < b[i]*c) {
            c += a[i];
            d += b[i];
         }
         else {
            c = a[i];
            d = b[i];
         }
         ll p = gcd(c, d);
         ra[i] = c/p;  rb[i] = d/p;
      }
      foru(i, 1, n) printf("%d/%d\n", int(ra[i]), int(rb[i]));
      if (idtest != nTest) cout << endl;
   }
   return 0;
}

