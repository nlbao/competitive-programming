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

const int MAX_N = 1000000;

int n;
char s[MAX_N];

int main() {
   freopen("NHAY.in", "r", stdin);
   freopen("NHAY.out", "w", stdout);
   for(int id = 0 ; id < 3; ++id) {
      scanf("%d",&n);
      scanf("%s",s);
      char t;
      while (scanf("%c",&t)) {
         printf("%c",t);
      }
      printf("\n");
   }
   return 0;
}
