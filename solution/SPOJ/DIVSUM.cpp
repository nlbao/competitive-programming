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

const int MAX_N = 500002;

ll s[MAX_N];

int main() {
   freopen("DIVSUM.in", "r", stdin);
   freopen("DIVSUM.out", "w", stdout);
   fill(s,0);
   foru(i,1,MAX_N-1)
      for(int j = i+i; j < MAX_N; j += i)
         s[j] += i;

   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      printf("%d\n",s[n]);
   }
   return 0;
}
