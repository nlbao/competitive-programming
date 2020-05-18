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

const int MAX_N = 111;
const int MAX_M = 111;
const ll BASE = 10007;

int n, m;
int g[2][MAX_N], stk[MAX_M][MAX_N];
map<ll,bool> ok[MAX_M];
ll first, last, a[MAX_N];
bool found;

int read() {   int x;   scanf("%d",&x);   return x;   }

ll get_h() {
   ll h = 0;
   foru(i,1,n) h = h*BASE + a[i];
   return h;
}

void push(int top) {
   foru(i,1,n) stk[top][i] = a[i];
}

void dfs(int k) {
   if (k >= m) return;
   if (found) return;
   rep(id,2) {
      foru(i,1,n) a[i] = stk[k][g[id][i]];
      ll h = get_h();
      if (ok[k+1].count(h) <= 0)
         if (h != last) {
            ok[k+1][h] = true;
            push(k+1);
            dfs(k+1);
         }
         else if (k+1 == m) {
            found = true;
            return;
         }
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("251B.in", "r", stdin);
   freopen("251B.out", "w", stdout);
#endif
   scanf("%d%d",&n,&m);
   foru(i,1,n) {
      scanf("%d",&g[0][i]);
      g[1][g[0][i]] = i;
   }
   foru(i,1,n) scanf("%d",&a[i]);
   last = get_h();
   foru(i,1,n) a[i] = i;
   ok[0][first = get_h()] = true;

   if (ok[0].count(last)) {
      cout << "NO";
      return 0;
   }

   found = false;
   push(0);
   dfs(0);
   if (found) cout << "YES";
   else cout << "NO";
   return 0;
}
