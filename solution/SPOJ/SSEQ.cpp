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

const int MAX_N = 200010;

int n;
int a[MAX_N], f[MAX_N];

void init(int k, int l, int r) {
   if (l > r) return;
   if (l == r) {
      f[k] = 1;
      return;
   }
   int mid = (l+r)>>1;
   init(k<<1,l,mid);
   init((k<<1)+1,mid+1,r);
   f[k] = r-l+1;
}

int get(int k, int l, int r, int pos) {
   --f[k];
   if (l >= r) return r;
   int mid = (l+r)>>1;
   if (pos <= f[k<<1]) return get(k<<1,l,mid,pos);
   else return get((k<<1)+1,mid+1,r,pos-f[k<<1]);
}

int main() {
   freopen("SSEQ.in", "r", stdin);
   freopen("SSEQ.out", "w", stdout);
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      init(1,1,n);
      foru(i,1,n) scanf("%d",&a[i]);
      ford(i,n,1) a[i] = get(1,1,n,i-a[i]);
      foru(i,1,n) printf("%d ",a[i]);
      printf("\n");
   }
   return 0;
}
