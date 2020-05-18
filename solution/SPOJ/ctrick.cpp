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

const int MAX_N = 20010;

deque<int> q;
int a[MAX_N];

int main() {
   freopen("ctrick.in", "r", stdin);
   freopen("ctrick.out", "w", stdout);
   int nTest, n;
   scanf("%d",&nTest);
   rep(id,nTest) {
      scanf("%d",&n);
      foru(i,1,n) q.pb(i);
      int m = n;
      foru(i,1,n) {
         foru(j,1,i%m) {
            q.pb(q.front());
            q.pop_front();
         }
         a[q.front()] = i;
         q.pop_front();
         if (q.empty()) break;
         --m;
      }
      foru(i,1,n) printf("%d ",a[i]);
      printf("\n");
   }
   return 0;
}
