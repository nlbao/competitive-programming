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

const int MAX_N = 1000010;

int n, m;
PI a[2*MAX_N];
int c[2*MAX_N], trace[2*MAX_N];
bool ok[MAX_N];

void add(int i, int j, int ii) {
   if (!ok[i]) return;
   ok[i] = false;
   a[m] = mp(i,j);
   c[m] = c[ii]+1;
   trace[m++] = ii;
}

void print_path(int i) {
   if (trace[i] >= 0) print_path(trace[i]);
   printf("%d",a[i].sc);
}

int main() {
   freopen("1495.in", "r", stdin);
   freopen("1495.out", "w", stdout);
   scanf("%d",&n);
   fill(ok,true);
   m = 0;
   a[m++] = mp(1%n,1);  ok[1%n] = false;
   a[m++] = mp(2%n,2);  ok[2%n] = false;
   c[0] = c[1] = 1;
   trace[0] = trace[1] = -1;
   for(int i = 0; i < m; ++i) {
      if (a[i].fr == 0) {
         print_path(i);
         return 0;
      }
      if (c[i] == 30) continue;
      foru(k,1,2) add((10*a[i].fr+k)%n, k, i);
   }
   printf("Impossible");
   return 0;
}
