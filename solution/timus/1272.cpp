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

vector<pair<int,PI> > e;
int p[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int get_root(int u) {
   if (p[u] < 0) return u;
   return p[u] = get_root(p[u]);
}

int add(int u, int v, int w) {
   int r1 = get_root(u), r2 = get_root(v);
   if (r1 == r2) return 0;
   p[r1] += p[r2];
   p[r2] = r1;
   return w;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1272.in", "r", stdin);
   freopen("1272.out", "w", stdout);
#endif
   int n, k, m, res = 0;
   scanf("%d%d%d",&n,&k,&m);
   foru(i,1,n) p[i] = -1;
   rep(i,k) {
      int u = read(), v = read();
      res += add(u,v,0);
   }
   rep(i,m) {
      int u = read(), v = read();
      res += add(u,v,1);
   }
   printf("%d",res);
   return 0;
}
