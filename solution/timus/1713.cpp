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

const int MAX_N = 1007;
const int MAX_LEN = 107;
const ll BASE = 10007;

int n, nQ = 0;
char s[MAX_N][MAX_LEN];
int len[MAX_N];
ll p[MAX_LEN], h[MAX_N][MAX_LEN];
//pair<ll,int> q[MAX_N*MAX_LEN]*MAX_LEN];
vector<pair<ll,int> > q;

ll get_h(int id, int i, int j) {
   if (i == 0) return h[id][j];
   return h[id][j]-h[id][i-1]*p[j-i+1];
}

bool in_q(int id, ll x) {
   int l = 0, r = nQ-1, p = -1;
   while (l <= r) {
      int mid = (l+r)/2;
      if (q[mid].fr == x) {
         p = mid;
         break;
      }
      else if (q[mid].fr < x) l = mid+1;
      else r = mid-1;
   }
   if (p == -1) return false;
   ford(i, p, 0)
      if (q[i].fr != x) break;
      else if (q[i].sc != id) return true;
   foru(i, p+1, nQ-1)
      if (q[i].fr != x) break;
      else if (q[i].sc != id) return true;
   return false;
}

int find_len(int id, int x) {
   rep(i, len[id]-x+1)
      if (!in_q(id,get_h(id,i,i+x-1))) return i;
   return -1;
}

int main() {
   freopen("1713.in", "r", stdin);
   freopen("1713.out", "w", stdout);
   p[0] = 1;
   foru(i, 1, MAX_LEN-1) p[i] = p[i-1]*BASE;
   cin >> n;
   rep(i, n) {
      scanf("%s", s[i]);
      len[i] = strlen(s[i]);
      h[i][0] = s[i][0];
      foru(j, 1, len[i]-1) h[i][j] = h[i][j-1]*BASE+s[i][j];
      rep(j, len[i])
         foru(k, j, len[i]-1) q.pb(mp(get_h(i,j,k),i));
   }

   //sort(q,q+nQ);
   nQ = size(q);
   sort(all(q));

   rep(i, n) {
      int l = 1, r = len[i], res = 0, pos = 0;
      while (l <= r) {
         int mid = (l+r)/2, t = find_len(i,mid);
         if (t > -1) {
            res = mid;
            pos = t;
            r = mid-1;
         }
         else l = mid+1;
      }
      foru(j, pos, pos+res-1) printf("%c", s[i][j]);
      printf("\n");
   }
   return 0;
}
