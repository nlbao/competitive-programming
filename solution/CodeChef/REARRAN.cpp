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

const int MAX_N = 10004;
const int MAX_K = 77;

int n, k, nA;
int m;
int a[MAX_N], b[MAX_N];
int c[MAX_N], res[MAX_N], pos[MAX_N];
VI p[MAX_K];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool solve() {
   if (nA > k) return false;
   foru(i,1,k) res[i] = -1;
   int d = n/k, r = n%k;
   foru(i,1,r)
      foru(j,1,nA)
         if (c[j] > d && c[j]%d > 0) {
            res[i] = j;
            c[j] -= d+1;
            break;
         }
   foru(i,r+1,k)
      foru(j,1,nA)
         if (c[j] >= d) {
            //cout << j << " " << c[j] << "   " << d <<    endl;
            res[i] = j;
            c[j] -= d;
            break;
         }

   //foru(i,1,k) cout << res[i] << endl;

   foru(i,1,k) if (res[i] == -1) return false;
   ll s = 0;
   foru(i,1,k) s = (s+a[res[i]])%m;
   if (s != 0) return false;

   rep(i,MAX_K) p[i].clear();
   foru(i,1,n)
      foru(j,1,nA)
         if (b[i]%m == a[j]) {
            p[j].pb(b[i]);
            break;
         }
   foru(i,1,nA) pos[i] = 0;

   foru(i,1,n) {
      if (i > k) res[i] = res[i-k];
      printf("%d ",p[res[i]][pos[res[i]]]);
      ++pos[res[i]];
   }
   printf("\n");
   return true;
}


int main() {
#ifndef ONLINE_JUDGE
   freopen("REARRAN.in", "r", stdin);
   freopen("REARRAN.out", "w", stdout);
#endif
   int nTest = read();
   rep(id,nTest) {
      scanf("%d%d%d",&n,&m,&k);
      foru(i,1,n) {
         b[i] = read();
         a[i] = b[i]%m;
      }
      sort(a+1,a+n+1);
      nA = 0;
      for(int i = 1, j = 1; i <= n; i = j) {
         ++nA;
         while (j <= n && a[j] == a[i]) ++j;
         a[nA] = a[i];
         c[nA] = j-i;
      }
      if (solve() == false) printf("-1\n");
   }
   return 0;
}
