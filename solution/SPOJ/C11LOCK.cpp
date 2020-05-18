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

const int MAX_N = 505;
const int MAX_A = MAX_N*MAX_N;

int nA, nB;
int v[7][MAX_N];
int a[MAX_A], b[MAX_A], c[MAX_N];
int cA[MAX_A], cB[MAX_A];

int read() {   int x;   scanf("%d",&x);   return x;   }

ll find(ll x, int r) {
   int l = 0;
   while (l <= r) {
      int mid = (l+r)>>1;
      if (b[mid] == x) return mid;
      else if (b[mid] < x) l = mid+1;
      else r = mid-1;
   }
   return -1;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("C11LOCK.in", "r", stdin);
   freopen("C11LOCK.out", "w", stdout);
#endif
   int n = read();
   ll m = read();
   foru(i,1,5)
      foru(j,1,n) v[i][j] = read();

   nA = nB = 0;
   foru(i,1,n) {
      foru(j,1,n) {
         a[nA++] = v[1][i]+v[2][j];
         b[nB++] = v[3][i]+v[4][j];
      }
      c[i-1] = v[5][i];
   }
   sort(a,a+nA);
   sort(b,b+nB);
   sort(c,c+n);   
   
   for(int i = 0, j = 1, p = 0; i < nA; i = j) {
      while (j < nA && a[j] == a[i]) ++j;
      a[i-p] = a[i];
      cA[i-p] = j-i;
      p += j-i-1;
      if (j == nA) nA -= p;
   }
   
   for(int i = 0, j = 1, p = 0; i < nB; i = j) {
      while (j < nB && b[j] == b[i]) ++j;
      b[i-p] = b[i];
      cB[i-p] = j-i;
      p += j-i-1;
      if (j == nB) nB -= p;
   }   
   
   ll res = 0;
   foru(i,1,n) {
       ll x = m-v[5][i];
       int l = 0, r = nB-1;
       while (l < nA && r >= 0) {
             ll sum = a[l]+b[r];
             if (sum < x) ++l;
             else if (sum > x) --r;
             else {
                  res += ll(cA[l])*ll(cB[r]);
                  ++l;
             }
       }                    
   }
   cout << res;
   return 0;
}
