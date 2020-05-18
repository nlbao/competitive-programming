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

const int MAX_N = 2007;

struct node {
   int c;
   node *link[30];
   node() {
      c = 0;
      rep(i, 31) link[i] = NULL;
   }
};

string s;
char sBegin[MAX_N], sEnd[MAX_N], t[MAX_N];
int kmp[MAX_N], f[MAX_N], g[MAX_N], Lmax[MAX_N];
bool ok[MAX_N][MAX_N];
node *root = new node();

void kmp_table(char str[]) {
   s = str;
   int j = 0;
   kmp[0] = 0;
   foru(i, 1, size(s)-1) {
      while (j && s[j] != s[i]) j = kmp[j-1];
      if (s[j] == s[i]) ++j;
      kmp[i] = j;
   }
}

void kmp_search(int a[]) {
   int j = 0;
   rep(i, strlen(t)) {
      while (j && s[j] != t[i]) j = kmp[j-1];
      if (s[j] == t[i]) ++j;
      a[i] = j;
      if (j == size(s)) j = kmp[j-1];
   }
}

int main() {
   freopen("113B.in", "r", stdin);
   freopen("113B.out", "w", stdout);
   scanf("%s%s%s", t, sBegin, sEnd);
   int n = strlen(t), m1 = strlen(sBegin), m2 = strlen(sEnd);
   kmp_table(sBegin);
   kmp_search(f);
   kmp_table(sEnd);
   kmp_search(g);

   fill(ok, false);
   fill(Lmax, 0);
   rep(i, n)
      foru(j, i, n-1) {
         int k = i-f[i]+1;
         if (f[i] == m1 && g[j] == m2 && k <= j-g[j]+1) {
            Lmax[k] = max(Lmax[k], j-k+1);
            ok[k][j] = true;
         }
      }
   int res = 0;
   rep(i, n) {
      node *p = root;
      rep(len, Lmax[i]) {
         int j = i+len, x = t[j]-'a';
         if (p->link[x] == NULL) p->link[x] = new node();
         p = p->link[x];
         if (ok[i][j] && !p->c) ++res;
         ++p->c;
      }
   }
   printf("%d", res);
   return 0;
}
