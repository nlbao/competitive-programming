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

const int MAX_N = 111111;
const int MAX_C = 1111;

int n, m, c;
int a[MAX_N], s[MAX_N];

int mmod(int x) { while (x < 0) x += c;   return x%c; }

int main() {
   freopen("177D1.in", "r", stdin);
   freopen("177D1.out", "w", stdout);
   cin >> n >> m >> c;
   foru(i, 1, n) scanf("%d", &a[i]);
   s[0] = 0;
   foru(i, 1, m) {
      int b;
      scanf("%d", &b);
      s[i] = mmod(s[i-1]+b);
   }
   if (2*m <= n) {
      foru(i, 1, m) a[i] = mmod(a[i]+s[i]);
      foru(i, m+1, n-m) a[i] = mmod(a[i]+s[m]);
      foru(i, n-m+1, n) a[i] = mmod(a[i]+s[m]-s[i-n+m-1]);
   }
   else {
      int p = n-m+1;
      foru(i, 1, p) a[i] = mmod(a[i]+s[i]);
      foru(i, p+1, m) {
         int j = max(0, i-n+m-1);
         a[i] = mmod(a[i]+s[i]-s[j]);
      }
      foru(i, m+1, n) a[i] = mmod(a[i]+s[m]-s[i-n+m-1]);
   }
   foru(i, 1, n) printf("%d ", a[i]%c);
   cout << endl;
   return 0;
}

