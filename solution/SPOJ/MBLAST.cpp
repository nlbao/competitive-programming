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

const int MAX_N = 2004;

int k;
char a[MAX_N], b[MAX_N];
int f[MAX_N][MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("MBLAST.in", "r", stdin);
   freopen("MBLAST.out", "w", stdout);
#endif
   scanf("%s%s%d",&a,&b,&k);
   int n = strlen(a), m = strlen(b);
   rep(i,max(m,n)+1) f[i][0] = f[0][i] = i*k;
   foru(i,1,n)
      foru(j,1,m) {
         f[i][j] = f[i-1][j-1] + min(k+k,abs(a[i-1]-b[j-1]));
         f[i][j] = min(f[i][j], min(f[i][j-1],f[i-1][j])+k);
      }
   printf("%d",f[n][m]);
   return 0;
}
