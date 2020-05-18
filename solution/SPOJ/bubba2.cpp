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

const int MAX_N = 50010;
const int MAX_Q = 50010;
const ll BASE = 1000003;

int n, nQ, nC, nB, maxk, logn, root = MAX_Q-5;
VI e[MAX_N], e2[MAX_N];
int h[MAX_N], p[MAX_N][20], k[MAX_Q];
ll r[MAX_N], c[MAX_N], b[MAX_N], f[MAX_N];
vector<ll> hQ[MAX_Q];
bool ok[MAX_N], avail[MAX_N];

ll read()   {  int x;   scanf("%d",&x); return x;   }

void enter() {
   rep(i,MAX_N) {
      e[i].clear();
      e2[i].clear();
   }
   scanf("%d%d",&n,&nQ);
   foru(i,1,n) f[i] = read();
   int x, y;
   rep(i,n-1) {
      scanf("%d%d",&x,&y);
      e[x].pb(y);
      e[y].pb(x);
   }
}

void gen_b() {
   nC = maxk = 0;
   rep(i,nQ) {
      ll s = 0;
      hQ[i].clear();
      scanf("%d",&k[i]);
      rep(j,k[i]) b[j] = read();
      ford(j,k[i]-1,0) {
         s = s + b[j]*r[k[i]-1-j];
         c[nC++] = s;
         hQ[i].pb(s);
      }
      maxk = max(maxk,k[i]);
   }
   sort(c,c+nC);
   nB = 0;
   for(int i = 0, j = 0; i < nC; i = j) {
      b[nB++] = c[i];
      while (j < nC && c[j] == c[i]) ++j;
   }
}

void dfs(int u) {
   foru(i,1,logn)
      if (h[u]-(1<<i) < 1) break;
      else p[u][i] = p[p[u][i-1]][i-1];
   int m = size(e[u]);
   ll t = f[u]*BASE;
   rep(i,m) {
      int v = e[u][i];
      if (p[v][0] == 0) {
         p[v][0] = u;
         h[v] = h[u]+1;
         f[v] += t;
         dfs(v);
      }
   }
}

int get_p(int i, int u) {
   if (h[u]-i < 1) return -1;
   if (i == 0) return u;
   int t = h[u]-i;
   ford(j,logn,0)
      if (h[u]-(1<<j) >= t) u = p[u][j];
   return u;
}

ll get_f(int i, int j) {
   if (i == 1) return f[j];
   return f[j]-f[p[i][0]]*r[h[j]-h[i]+1];
}

int find_b(ll x) {
   int l = 0, r = nB-1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (b[mid] == x) return mid;
      else if (b[mid] < x) l = mid+1;
      else r = mid-1;
   }
   return -1;
}

void dfs_2(int u) {
   avail[u] = false;
   int m = size(e2[u]);
   rep(i,m) {
      int v = e2[u][i];
      if (avail[v]) {
         dfs_2(v);
         ok[u] = (ok[u]) || (ok[v]);
      }
   }
}

void cal_ok() {
//cal p[u], f[u]
   logn = 0;
   while (1<<(logn+1) <= n) ++logn;
   fill(p,0);
   h[1] = 1;   p[1][0] = n+100;
   dfs(1);

//cal ok
   fill(ok,false);
   foru(i,1,n) {
      int l = 0, r = min(h[i],maxk)+10, t = -1;
      while (l <= r) {
         int mid = (l+r)/2, j = get_p(mid,i);
         if (j < 1 || j > n) {
            r = mid-1;
            continue;
         }
         ll x = get_f(j,i);
         int pos = find_b(x);
         if (pos > -1) {
            t = pos;
            l = mid+1;
            ok[t] = true;
         }
         else r = mid-1;
      }
      if (t > -1) ok[t] = true;
   }

//create trie-tree from Q list
   rep(i,nQ) {
      int p = root;
      rep(j,k[i]) {
         int pp = find_b(hQ[i][j]);
         e2[p].pb(pp);
         p = pp;
      }
   }
   fill(avail,true);
   dfs_2(root);
}

void solve() {
   rep(i,nQ)
      if (k[i] > 0 && ok[find_b(hQ[i][k[i]-1])]) printf("Y\n");
      else printf("N\n");
}

int main() {
   freopen("bubba2.in", "r", stdin);
   freopen("bubba2.out", "w", stdout);
   r[0] = 1;
   foru(i,1,MAX_N-1) r[i] = r[i-1]*BASE;
   int nTest;
   scanf("%d",&nTest);
   rep(id,nTest) {
      enter();
      gen_b();
      cal_ok();
      solve();
   }
   return 0;
}
