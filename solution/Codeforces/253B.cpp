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

const int MAX_A = 5004;
int c[MAX_A+3], f[MAX_A+3], g[MAX_A+3];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("253B.in", "r", stdin);
   freopen("253B.out", "w", stdout);
#else
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n;
   scanf("%d",&n);
   fill(c,0);
   rep(i,n) ++c[read()];
   f[0] = g[MAX_A+1] = 0;
   foru(i,1,MAX_A) f[i] = f[i-1] + c[i];
   ford(i,MAX_A,1) g[i] = g[i+1] + c[i];

   int res = n;
   foru(i,1,MAX_A)
      foru(j,i,min(MAX_A,2*i))
         res = min(res, f[i-1]+g[j+1]);
   cout << res;
   return 0;
}
