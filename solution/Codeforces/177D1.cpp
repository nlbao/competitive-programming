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
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 1111;
const int MAX_C = 1111;

int n, m, c;
int a[MAX_N], b[MAX_N];

int main() {
   freopen("177D1.in", "r", stdin);
   freopen("177D1.out", "w", stdout);

   cin >> n >> m >> c;
   foru(i, 1, n) scanf("%d", &a[i]);
   foru(i, 1, m) scanf("%d", &b[i]);
   foru(i, 1, n-m+1)
      foru(j, 1, m) a[i+j-1] = (a[i+j-1]+b[j])%c;
   foru(i, 1, n) printf("%d ", a[i]);
   return 0;
}

