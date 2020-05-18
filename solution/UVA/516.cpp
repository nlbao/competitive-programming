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

const int MAX_N = 32767;
const int MAX_P = MAX_N;

int nP = 0;
bool ok[MAX_N];
int p[MAX_N];
string s;
int a[MAX_P];

int main() {
   freopen("516.in", "r", stdin);
   freopen("516.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j < MAX_N; j += i)
            ok[j] = false;
      }

   for(;;) {
      getline(cin,s);
      if (s[0] == '0') break;
      int m = size(s), nA = 0, i = 0;
      while (i < m) {
         while (i < m && s[i] == ' ') ++i;
         if (i < m) {
            a[nA] = 0;
            while (i < m && s[i] != ' ')
               a[nA] = a[nA]*10+(s[i++]-'0');
            ++nA;
         }
      }

      int n = 1;
      for(int i = 0; i < nA; i += 2)
         rep(j,a[i+1]) n *= a[i];

      --n;
      nA = 0;
      rep(i,nP) {
         int x = p[i];
         if (x*x > n) break;
         if (n%x == 0) {
            a[nA++] = x;
            a[nA] = 0;
            while (n%x == 0) {
               ++a[nA];
               n /= x;
            }
            ++nA;
         }
      }
      if (n > 1) {
         a[nA++] = n;
         a[nA++] = 1;
      }

      for(i = nA-2; i > 0; i -= 2) printf("%d %d ",a[i],a[i+1]);
      printf("%d %d",a[0],a[1]);
      printf("\n");
   }
   return 0;
}
