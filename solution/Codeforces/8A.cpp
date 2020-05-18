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

const int MAX_N = 100007;
const int MAX_A = 28;

int num(char x)   {  return x-'a';  }

int n;
char s[MAX_N], a[111], b[111];
string t;
int next[MAX_N][MAX_A];

int check() {
   int j = 0;
   rep(i, n)
      if (s[i] == t[j]) {
         ++j;
         if (j >= size(t)) return 1;
      }
   if (j >= size(t)) return 1;
   return 0;
}


int main() {
#ifdef DEBUG
   freopen("8A.in", "r", stdin);
   freopen("8A.out", "w", stdout);
#endif
   scanf("%s%s%s", s, a, b);
   n = strlen(s);
   t = a;
   rep(i, strlen(b)) t += b[i];
   int c1 = check();
   reverse(s, s+n);
   int res = c1+check();
   if (res == 2) printf("both");
   else if (!res) printf("fantasy");
   else if (c1) printf("forward");
   else printf("backward");
   return 0;
}
