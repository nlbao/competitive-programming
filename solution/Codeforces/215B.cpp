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

const int MAX_N = 5003;

double y[MAX_N], z[MAX_N];

int read() {
   int x;
   scanf("%d",&x);
   return x;
}

int main() {
   freopen("215B.in", "r", stdin);
   freopen("215B.out", "w", stdout);
   int n,m,k;
   double r1 = 0;
   n = read();
   rep(i,n) r1 = max(r1,double(read()));
   m = read();
   rep(i,m) y[i] = read();
   k = read();
   rep(i,k) z[i] = read();
   double a = read(), b = read(), r2 = 0;
   rep(i,m)
      rep(j,k)
         r2 = max(r2,sqrt(b*y[i]*r1*r1/(a*z[j]+b*y[i])));
   printf("%.7f",r2);
   return 0;
}
