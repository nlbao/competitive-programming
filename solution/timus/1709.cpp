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

const int MAX_N = 110;

int n;
vector<pair<int,PI> > e;
int p[MAX_N];
bool ok[MAX_N];
char f[MAX_N][MAX_N];
char s[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int get_root(int u) {
   if (p[u] < 0) return u;
   return (p[u] = get_root(p[u]));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("1709.in", "r", stdin);
   freopen("1709.out", "w", stdout);
#endif
   ll d, a, res = 0;
   scanf("%d",&n);
   cin >> d >> a;
   foru(i,1,n) {
      scanf("%s",&s);
      foru(j,1,n) {
         if (i < j) e.pb(mp(1-int(s[j-1]-'0'),mp(i,j)));
         f[i][j] = '0';
      }
   }

   sort(all(e));
   foru(i,1,n) p[i] = -1;
   fill(ok,false);
   int sz = size(e);
   rep(i,sz) {
      int u = e[i].sc.fr, v = e[i].sc.sc;
      int r1 = get_root(u), r2 = get_root(v);
      if (r1 != r2) {
         ok[i] = true;
         p[r1] += p[r2];
         p[r2] = r1;
      }
      if (ok[i] && e[i].fr == 1) {
         res += a;
         f[u][v] = f[v][u] = 'a';
      }
      else if (!ok[i] && e[i].fr == 0) {
         res += d;
         f[u][v] = f[v][u] = 'd';
      }
   }

   cout << res << endl;
   foru(i,1,n) {
      foru(j,1,n) printf("%c",f[i][j]);
      printf("\n");
   }
   return 0;
}
