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

const int MAX_N = 1003;

int n;
char s[MAX_N];
int a[MAX_N], b[MAX_N], f[MAX_N][MAX_N];

bool ok(int i, int j) {
   if (i < 1 && j < 1) return true;
   if (i < 1) return abs(2*b[j]-j) < 2;
   if (j < 1) return abs(2*a[i]-i) < 2;
   return abs(2*(a[i]+b[j])-i-j) < 2;
}

void print_path(int i, int j) {
   if (f[i][j] <= 0) return;
   if (f[i][j] == 1) print_path(i-1,j);
   else print_path(i,j-1);
   printf("%d",f[i][j]);
}

int main() {
   freopen("1501.in", "r", stdin);
   freopen("1501.out", "w", stdout);
   scanf("%d",&n);
   scanf("%s",&s);
   a[0] = 0;
   foru(i,1,n) a[i] = a[i-1]+(s[i-1] == '0');
   scanf("%s",&s);
   b[0] = 0;
   foru(i,1,n) b[i] = b[i-1]+(s[i-1] == '0');

   fill(f,0);
   f[0][0] = -1;
   foru(i,0,n)
      foru(j,0,n)
         if (f[i][j] != 0) {
            if (ok(i+1,j)) f[i+1][j] = 1;
            if (ok(i,j+1)) f[i][j+1] = 2;
         }

   if (f[n][n] == 0) printf("Impossible");
   else print_path(n,n);
   return 0;
}
