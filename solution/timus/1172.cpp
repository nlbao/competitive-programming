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

const int MAX_N = 33;

int n;
ll f[MAX_N][MAX_N][MAX_N][4];

int read() {   int x;   scanf("%d",&x);   return x;   }

void up(int i, int j, int k, int p, ll v) {
   f[i][j][k][p] += v;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1172.in", "r", stdin);
   freopen("1172.out", "w", stdout);
#endif
   scanf("%d",&n);
   fill(f,0);
   f[1][0][0][1] = 1;
   foru(s,1,3*n)
      foru(i,1,n)
         foru(j,0,min(n,s-i)) {
            int k = s-i-j;
            foru(p,1,3) {
               if (f[i][j][k][p] == 0) continue;
               if (p != 1 && i < n) up(i+1,j,k,1,f[i][j][k][p]*(n-i));
               if (p != 2 && j < n) up(i,j+1,k,2,f[i][j][k][p]*(n-j));
               if (p != 3 && k < n) up(i,j,k+1,3,f[i][j][k][p]*(n-k));
            }
         }
   //cout << (f[n][n][n][2]+f[n][n][n][3])/2  << endl;
   cout << f[n][n][n][2] << endl;
   return 0;
}
