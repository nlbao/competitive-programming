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

const int MAX_N = 100003;
const int MAX_A = 10000003;

int a[2][MAX_N];
int p[MAX_A], c[MAX_A];
VI x, y;

int read() {   int x;   scanf("%d",&x);   return x;   }

void f(int x, int d) {
   while (x > 1) {
      c[p[x]] += d;
      x /= p[x];
   }
}

void enter(int id, int n, int d) {
   rep(i,n) {
      scanf("%d",&a[id][i]);
      f(a[id][i],d);
   }
}

void print_res(int id, int n, int d) {
   rep(i,n) {
      int k = a[id][i], v = 1;
      while (k > 1) {
         if (c[p[k]]*d > 0) {
            v *= p[k];
            c[p[k]] -= d;
         }
         k /= p[k];
      }
      printf("%d ",v);
   }
   printf("\n");
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("222C.in", "r", stdin);
   freopen("222C.out", "w", stdout);
#endif
   rep(i,MAX_A) p[i] = i;
   for(ll i = 2; i < MAX_A; ++i)
      if (p[i] == i)
         for(ll j = i*i; j < MAX_A; j += i)
            p[j] = i;

   int n, m;
   scanf("%d%d",&n,&m);
   fill(c,0);
   enter(0,n,1);
   enter(1,m,-1);

   printf("%d %d\n",n,m);
   print_res(0,n,1);
   print_res(1,m,-1);
   return 0;
}
