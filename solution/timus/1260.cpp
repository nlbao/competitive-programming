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

const int MAX_N = 60;

ll f[MAX_N];

ll solve(int n) {
   f[1] = f[2] = 1;
   f[3] = 2;
   foru(i,4,n) f[i] = f[i-1]+ f[i-3] + 1;
   return f[n];
}

int main() {
   freopen("1260.in", "r", stdin);
   freopen("1260.out", "w", stdout);
   int n;
   scanf("%d",&n);
   cout << solve(n);
   return 0;
}
