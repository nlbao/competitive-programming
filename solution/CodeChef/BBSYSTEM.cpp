#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 2229290;
const ll MODUN = 500009;
const int limit = 2229282;

bool is_prime[MAX_N];
int p[MAX_N], g[MAX_N], f[MAX_N], c[111222];

void init() {
   fill(is_prime, true);
   fill(c, 0);
   g[1] = c[1] = f[1] = 1;
   fab(i, 2, MAX_N) {
      if (is_prime[i]) {
         g[i] = 2;
         if (i*i <= MAX_N)
            for (int j = i+i; j <= MAX_N; j += i) {
               is_prime[j] = false;
               p[j] = i;
            }
      }
      else {
         int a = i, d = 0;
         while (a%p[i] == 0) {
            a /= p[i];
            ++d;
         }
         if (a == 1) g[i] = ++d;
         else g[i] = g[a]*g[i/a];
      }
      f[i] = ll(f[i-1])*ll(++c[g[i]])%MODUN;
   }
}

int main() {
   freopen("BBSYSTEM.in", "r", stdin);
   freopen("BBSYSTEM.out", "w", stdout);
   init();
   int t, n;
   scanf("%d", &t);
   fab(i, 1, t) {
      scanf("%d", &n);
      if (n > limit) printf("%d\n", MODUN-1);
      else printf("%d\n", f[n]-1);
   }
   return 0;
}

