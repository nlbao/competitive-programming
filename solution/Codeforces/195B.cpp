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

const int MAX_M = 100007;

int n, m;
int c[MAX_M];
double f[MAX_M];

class cmp_min {
public:
   bool operator() (const int &a, const int &b) {
      if (c[a] < c[b] || (c[a] == c[b] && f[a] < f[b])
|| (c[a] == c[b] && f[a] == f[b] && a < b)) return false;
      return true;
   }
};

priority_queue<int,vector<int>,cmp_min> h;

int main() {
   freopen("195B.in", "r", stdin);
   freopen("195B.out", "w", stdout);
   cin >> n >> m;
   foru(i,1,m) {
      f[i] = double(m+1)/2-i;
      if (f[i] < 0) f[i] = -f[i];
      c[i] = 0;
   }
   foru(i,1,m) h.push(i);
   rep(id,n) {
      int i = h.top();  h.pop();
      printf("%d\n",i);
      ++c[i];
      h.push(i);
   }
   return 0;
}
