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

const int MAX_N = 60010;
const int oo = 1000000000;

int f[MAX_N];

int main() {
   freopen("1073.in", "r", stdin);
   freopen("1073.out", "w", stdout);
   int n;
   scanf("%d",&n);
   foru(i,1,n) f[i] = oo;
   f[0] = 0;
   rep(i,n)
      for(int a = 1, aa = 1; i+aa <= n; ++a, aa = a*a)
         f[i+aa] = min(f[i+aa],f[i]+1);
   printf("%d\n",f[n]);
   return 0;
}
