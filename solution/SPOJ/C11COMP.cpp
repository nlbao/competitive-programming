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

const int MAX_N = 100005;

int n, m, limit, top;
int pos[MAX_N], nChild[MAX_N], color[MAX_N];
int first[MAX_N], last[MAX_N], f[MAX_N], res[MAX_N];
VI e[MAX_N];
PI a[MAX_N];
pair<PI,int> id[MAX_N], q[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void dfs(int u) {
   pos[u] = ++top;
   nChild[u] = 0;
   int sz = size(e[u]);
   rep(i,sz) {
      int v = e[u][i];
      dfs(v);
      nChild[u] += nChild[v]+1;
   }
}

void update(int i, int value) {
   if (i < 1 || i > n) return;
   f[i] += value;
   update(i+(i&(-i)), value);
}

int get(int i) {
   if (i < 1 || i > n) return 0;
   return f[i] + get(i-(i&(-i)));
}

void up(int l, int r, int value) {
   l = max(l,1);
   r = min(r,n);
   if (l > r) return;
   update(l,value);
   update(r+1,-value);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("C11COMP.in", "r", stdin);
   freopen("C11COMP.out", "w", stdout);
#endif
   scanf("%d%d%d",&n,&m,&limit);
//init tree
   foru(i,2,n) e[read()].pb(i);
   top = 0;
   dfs(1);
//init color
   foru(i,1,n) scanf("%d",&color[pos[i]]);
   foru(i,1,n) a[i-1] = mp(color[i],i);
   sort(a,a+n);
   for(int i = 0, j = 0; i < n; i = j) {
      while (j < n && a[j].fr == a[i].fr) ++j;
      first[a[i].sc] = -1;
      foru(k,i+1,j-1) first[a[k].sc] = a[k-1].sc;
      foru(k,i,j-1) {
         if (j-k > limit) last[a[k].sc] = a[k+limit].sc;
         else last[a[k].sc] = n+1;
      }
   }
   foru(i,1,n) id[i-1] = mp(mp(first[i],last[i]),i);
   sort(id,id+n);
//init q
   int nQ = read();
   rep(i,nQ) {
      int u = read();
      q[i] = mp(mp(pos[u],pos[u]+nChild[u]),i+1);
   }
   sort(q,q+nQ);
//solve
   fill(f,0);
   fill(ok,false);
   int l = 0, p = 1;

   for(int i = 0, j = 0; i < nQ; i = j) {
      int left = q[i].fr.fr;
      while (j < nQ && q[j].fr.fr == left) ++j;
      while (l < n)
         if (id[l].sc < left) ++l;
         else if (id[l].fr.fr < left) {
            ok[id[l].sc] = true;
            up(id[l].sc, id[l].fr.sc-1, 1);
            ++l;
         }
         else break;
      int tmp = get(q[i].fr.sc) - get(left-1);
      foru(k,i,j-1) res[q[k].sc] = tmp;
      if (i < nQ-1)
         while (p < q[i+1].fr.fr) {
            if (ok[p]) up(first[p], last[p]-1, -1);
            ++p;
         }
   }
   foru(i,1,nQ) printf("%d\n",res[i]);
   return 0;
}
