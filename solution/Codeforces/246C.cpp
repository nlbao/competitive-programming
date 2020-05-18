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
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const int MAX_N = 55;
const int MAX_F = MAX_N*MAX_N;

int m = 0;
int f[MAX_F], t[MAX_F];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool find(int x) {
   foru(i,1,m)
      if (f[i] == x) return true;
   return false;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("246C.in", "r", stdin);
   freopen("246C.out", "w", stdout);
#endif
   int n = read(), k = read();
   f[++m] = 0;
   fill(t,0);
   foru(i,1,n) {
      int a = read();
      //if (m > k+2) continue;
      int tm = m;
      foru(j,1,tm) {
         int x = a+f[j];
         if (!find(x)) {
            f[++m] = x;
            t[m] = j;
         }
      }
   }

   //rep(i,50) cout << 10000000 << " "; cout << endl;

   VI res;
   foru(i,1,k) {
      res.clear();
      int j = m;
      while (f[j] > 0) {
         res.pb(f[j]-f[t[j]]);
         j = t[j];
      }
      --m;
      int n = size(res);
      printf("%d",n);
      rep(j,n) printf(" %d",res[j]);
      printf("\n");
   }
   return 0;
}
