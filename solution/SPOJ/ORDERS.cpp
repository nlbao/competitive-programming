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

const int MAX_N = 200010;

int n;
int a[MAX_N], f[MAX_N];

void update(int i) {
   if (i < 1 || i > n) return;
   ++f[i];
   update(i+(i&(-i)));
}

int get(int i) {
   if (i < 1 || i > n) return 0;
   return f[i]+get(i-(i&(-i)));
}

int main() {
   freopen("ORDERS.in", "r", stdin);
   freopen("ORDERS.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      foru(i,1,n) scanf("%d",&a[i]);
      fill(f,0);
      int c = 0;
      ford(i,n,1) {
         ++c;
         int j = i-a[i], k = get(j), t = 0;
         while (k > 0) {
            j += k;
            t += k;
            k = get(j)-t;
         }
         a[i] = j;
         update(a[i]);
      }
      foru(i,1,n) printf("%d ",a[i]);
      printf("\n");
   }
   return 0;
}
