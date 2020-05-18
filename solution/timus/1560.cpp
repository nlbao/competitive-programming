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

const int MAX_N = 80010;
const int MAX_K = 5;

int n,m,u,v;
ll modun;
int a[MAX_N];
ll f[4*MAX_N][MAX_K], g[4*MAX_N][MAX_K];

ll mmod(int x) {  while (x < 0) x += modun;  return x%modun;   }

void updateIT(int k, int l, int r) {
   if (l > r || u > r || v < l) return;

   if (l == r) {
      f[k][1] = a[l];
      return;
   }

   int left = k<<1, right = (k<<1)+1, mid = (l+r)/2;
   updateIT(left,l,mid);
   updateIT(right,mid+1,r);

   foru(i,1,MAX_K-1) {
      f[k][i] = (f[left][i]+f[right][i])%modun;
      foru(j,1,i-1)
         f[k][i] = (f[k][i] + f[left][j]*f[right][i-j])%modun;
   }
}

void getIT(int k, int l, int r) {
   if (l > r || u > r || v < l) {
      rep(i,MAX_K) g[k][i] = 0;
      return;
   }

   if (u <= l && r <= v) {
      rep(i,MAX_K) g[k][i] = f[k][i];
      return;
   }

   int left = k<<1, right = (k<<1)+1, mid = (l+r)/2;
   getIT(left,l,mid);
   getIT(right,mid+1,r);

   foru(i,1,MAX_K-1) {
      g[k][i] = (g[left][i]+g[right][i])%modun;
      foru(j,1,i-1)
         g[k][i] = (g[k][i] + g[left][j]*g[right][i-j])%modun;
   }
}

int main() {
   freopen("1560.in", "r", stdin);
   freopen("1560.out", "w", stdout);
   cin >> n >> m >> modun;
   foru(i,1,n) {
      scanf("%d",&a[i]);
      a[i] = mmod(a[i]);
   }
   fill(f,0);
   u = 1;   v = n;
   updateIT(1,1,n);

   rep(id,m) {
      char ch = '\n';
      while (ch == '\n') scanf("%c",&ch);
      if (ch == 'I') {
         int i,x;
         scanf("%d%d",&i,&x);
         a[i] = mmod(a[i]+x);
         u = v = i;
         updateIT(1,1,n);
      }
      else {
         int k;
         scanf("%d%d%d%d",&u,&v,&k);
         getIT(1,1,n);
         printf("1");
         foru(i,1,k)
            printf(" %I64d",g[1][i]);
         printf("\n");
      }
   }
   return 0;
}
