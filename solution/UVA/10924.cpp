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

bool ok[MAX_N];

int main() {
   freopen("10924.in", "r", stdin);
   freopen("10924.out", "w", stdout);
   fill(ok,true);
   ok[0] = false;
   for(int i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         ll j = i;
         for(j *= j; j < MAX_N; j += i)
            ok[j] = false;
      }

   string s;
   while(cin >> s) {
      int n = size(s), sum = 0;
      rep(i,n)
         if (s[i] > 'Z') sum += s[i]-'a'+1;
         else sum += s[i]-'A'+27;
      if (ok[sum]) printf("It is a prime word.\n");
      else printf("It is not a prime word.\n");
   }
   return 0;
}
