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
#pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 104;

int n;
int a[MAX_N], f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("1826.in", "r", stdin);
   freopen("1826.out", "w", stdout);
#endif
   scanf("%d",&n);
   rep(i,n) scanf("%d",&a[i]);
   sort(a,a+n);

   f[0] = a[0];
   f[1] = a[1];
   foru(i,2,n-1)
      f[i] = min(f[i-2]+a[0]+2*a[1]+a[i], f[i-1]+a[0]+a[i]);
   printf("%d\n",f[n-1]);
   return 0;
}
