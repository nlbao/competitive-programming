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

const int MAX_N = 1000007;
const ll MODUN = 1073741824LL;

bool ok[MAX_N];
int d[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("236B.in", "r", stdin);
   freopen("236B.out", "w", stdout);
#endif
   int n = 1000004;
   foru(i,1,n) {
      ok[i] = true;
      d[i] = 2;
   }
   d[1] = 1;
   foru(i,2,n)
      if (ok[i]) {
         int j = i+i;
         for(int j = i+i; j < n; j += i) {
            ++d[j];
            ok[j] = false;
         }
      }
      else
         for(int j = i+i; j < n; j += i) ++d[j];

   ll a, b, c, res = 0;
   cin >> a >> b >> c;
   foru(i,1,a)
      foru(j,1,b)
         foru(k,1,c)
            res = (res + d[i*j*k])%MODUN;
   cout << res;
   return 0;
}
