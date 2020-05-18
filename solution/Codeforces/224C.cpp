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

const int MAX_N = 100004;

char s[MAX_N];
int a[MAX_N], b[MAX_N], p[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

bool ok(int i, int j) {
   if (s[i] == '(' && s[j] == ')') return true;
   if (s[i] == '[' && s[j] == ']') return true;
   return false;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("224C.in", "r", stdin);
   freopen("224C.out", "w", stdout);
#endif
   scanf("%s",&s);
   int n = strlen(s), top = 0;
   fill(a,0);
   rep(i,n) {
      p[top++] = i;
      if (top > 1 && ok(p[top-2],p[top-1])) {
         a[p[top-2]] = p[top-1];
         top -= 2;
      }
   }
   ford(i,n-1,0)
      if (a[i] > 0 && a[i]+1 < n && a[a[i]+1] > 0) a[i] = a[a[i]+1];

   b[0] = (s[0] == '[');
   foru(i,1,n-1) b[i] = b[i-1]+(s[i] == '[');

   int c = -1, l = 1, r = 0;
   rep(i,n) {
      if (a[i] <= 0) continue;
      int t = b[a[i]];
      if (i > 0) t -= b[i-1];
      if (t > c) {
         c = t;
         l = i;   r = a[i];
      }
   }

   if (c == -1) printf("0");
   else {
      printf("%d\n",c);
      foru(i,l,r) printf("%c",s[i]);
   }
   return 0;
}
