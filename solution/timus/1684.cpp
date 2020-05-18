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

const int MAX_N = 75010;

int n, m;
char s[MAX_N], t[MAX_N];
int kmp[MAX_N], f[MAX_N];

void print_res(int i) {
   if (f[i] >= 1) {
      print_res(f[i]-1);
      printf(" ");
   }
   foru(j, f[i], i) printf("%c",t[j]);
}

int main() {
   freopen("1684.in", "r", stdin);
   freopen("1684.out", "w", stdout);
   scanf("%s%s", s, t);
   n = strlen(s);
   m = strlen(t);
   int j = 0;  kmp[0] = 0;
   foru(i, 1, n-1) {
      while (j && s[j] != s[i]) j = kmp[j-1];
      if (s[j] == s[i]) ++j;
      kmp[i] = j;
   }

   j = 0;
   rep(i, m) {
      while (j && s[j] != t[i]) j = kmp[j-1];
      if (j < n && s[j] == t[i]) ++j;
      f[i] = i-j+1;
      if (j == 0) {
         printf("Yes");
         return 0;
      }
      if (j == n) j = kmp[j-1];
   }
   printf("No\n");
   print_res(m-1);
   return 0;
}
