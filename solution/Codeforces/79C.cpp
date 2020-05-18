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

const int MAX_N = 100004;
const int oo = 1000000000;

char s[MAX_N];
int g[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("79C.in", "r", stdin);
   freopen("79C.out", "w", stdout);
#endif
   scanf("%s",&s);
   int n = strlen(s);
   rep(i,n) g[i] = oo;
   int q = read();
   char a[30];
   rep(i,q) {
      scanf("%s",&a);
      int m = strlen(a);
      rep(i,n-m+1) {
         if (m > g[i]) continue;
         bool ok = true;
         foru(j,i,i+m-1)
            if (s[j] != a[j-i]) {
               ok = false;
               break;
            }
         if (ok) g[i] = m;
      }
   }
   rep(i,n)
      if (g[i] < oo) g[i] += i-1;

   int len = 0, pos = 0, j = oo+10;
   ford(i,n-1,0) {
      if (g[i] <= j) j = g[i]-1;
      if (j > n) {
         len = n-i;
         pos = i;
      }
      else if (j-i+1 >= len) {
         len = j-i+1;
         pos = i;
      }
   }
   cout << len << " " << pos << endl;
   return 0;
}
