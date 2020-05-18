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

const int MAX_P = 50;

ll n;
int nP = 0;
ll p[MAX_P];
int a[MAX_P], b[MAX_P];

int read() {   int x;   scanf("%d",&x);   return x;   }

void push(ll x) {
   p[nP] = x;
   a[nP] = 0;
   while (n%x == 0) {
      ++a[nP];
      n /= x;
   }
   ++nP;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("QNUMBER.in", "r", stdin);
   freopen("QNUMBER.out", "w", stdout);
#endif
   int q;
   scanf("%I64d%d",&n,&q);

   if (n%2 == 0) push(2);
   for(ll i = 3; i*i <= n; i += 2)
      if (n%i == 0) push(i);
   if (n > 1) push(n);

   int s3 = 1;
   rep(i,nP) s3 *= a[i]+1;

   rep(id,q) {
      int t, res = 0;
      ll k;
      scanf("%d%I64d",&t,&k);

      rep(i,nP) {
         b[i] = 0;
         while (b[i] < a[i] && k%p[i] == 0) {
            ++b[i];
            k /= p[i];
         }
      }

      if (t == 1) {
         res = 1;
         rep(i,nP) res *= b[i]+1;
      }
      else {
         if (k == 1) {
            res = 1;
            rep(i,nP)
               if (a[i] < b[i]) {
                  res = 0;
                  break;
               }
               else res *= a[i]-b[i]+1;
         }
         if (t == 3) res = s3-res;
      }
      printf("%d\n",res);
   }
   return 0;
}
