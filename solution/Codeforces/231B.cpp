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

const int MAX_N = 104;
const int MAX_D = 10004;

int n, d, l;
bool f[MAX_N][2*MAX_D];
int trace[MAX_N][2*MAX_D];

int read() {   int x;   scanf("%d",&x);   return x;   }

void up(int i, int j, int t) {
   if (i < 1 || j < 0 || j >= 2*MAX_D) return;
   f[i][j] = true;
   trace[i][j] = t;
}

void print_path(int i, int j) {
   printf("%d ",j+trace[i][j+MAX_D]);
   if (i < n) print_path(i+1,trace[i][j+MAX_D]);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("231B.in", "r", stdin);
   freopen("231B.out", "w", stdout);
#endif
   scanf("%d%d%d",&n,&d,&l);
   fill(f,false);
   fill(trace,0);
   foru(i,1,l) f[n][i+MAX_D] = true;
   ford(i,n,2)
      foru(j,-MAX_D,MAX_D)
         if (f[i][j+MAX_D])
            foru(k,1,l) up(i-1,k-j+MAX_D,j);

   if (!f[1][d+MAX_D]) {
      printf("-1");
      return 0;
   }
   print_path(1,d);
   return 0;
}
