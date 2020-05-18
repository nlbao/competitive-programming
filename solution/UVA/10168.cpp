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

const int MAX_N = 10000007;

bool ok[MAX_N];

int find(int n) {
   if (ok[n-2]) return 2;
   for(int i = 3; i < n; i += 2)
      if (ok[i] && ok[n-i]) return i;
   return -1;
}

int main() {
   freopen("10168.in", "r", stdin);
   freopen("10168.out", "w", stdout);
   fill(ok,true);
   ok[0] = ok[1] = false;
   for(int i = 2; i*i < MAX_N; ++i)
      if (ok[i])
         for(int j = i*i; j < MAX_N; j += i)
            ok[j] = false;

   int n;
   while (cin >> n) {
      if (n < 8) {
         printf("Impossible.\n");
         continue;
      }
      if (n%2 == 0) {
         int i = find(n-4);
         printf("2 2 %d %d\n",i,n-4-i);
      }
      else {
         int i = find(n-5);
         printf("2 3 %d %d\n",i,n-5-i);
      }
   }
   return 0;
}
