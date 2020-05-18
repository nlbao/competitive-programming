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

const int MAX_N = 100;

char s[MAX_N];
int kmp[MAX_N];

int cal_f(string s) {
   int n = size(s);
   rep(i, n) s += s[i];
   kmp[0] = 0;
   foru(i, 1, 2*n-1) {
      int j = kmp[i-1];
      while (j && s[j] != s[i]) j = kmp[j-1];
      if (s[j] == s[i]) ++j;
      kmp[i] = j;
      if (j >= n)
         if (i > n-1 && n%(i-n+1) == 0) return i-n+1;
         else j = kmp[j-1];
   }
   return 0;
}

int main() {
   freopen("IPS.in", "r", stdin);
   freopen("IPS.out", "w", stdout);
   int nTest;
   cin >> nTest;
   rep(id, nTest) {
      scanf("%s", s);
      int n = strlen(s), res = n;
      rep(bit, 1<<n) {
         string s1 = "", s2 = "";
         rep(i, n)
            if (bit&(1<<i)) s1 += s[i];
            else s2 += s[i];
         res = min(res,cal_f(s1)+cal_f(s2));
      }
      printf("%d\n",res);
   }
   return 0;
}
