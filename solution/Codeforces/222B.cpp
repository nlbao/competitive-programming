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

const int MAX_N = 1003;

int read() {   int x;   scanf("%d",&x);   return x;   }

void swap(int &x, int &y) {   int t = x;  x = y;   y = t;   }

char s[1000];
string t;
int a[MAX_N][MAX_N];
int pr[MAX_N], pc[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
   freopen("222B.in", "r", stdin);
   freopen("222B.out", "w", stdout);
#endif
   int n,m,k;
   scanf("%d%d%d",&n,&m,&k);
   foru(i,1,n)
      foru(j,1,m)
         scanf("%d",&a[i][j]);
   foru(i,1,n) pr[i] = i;
   foru(i,1,m) pc[i] = i;

   foru(i,1,k) {
      char c = getchar();
      c = getchar();
      int x = read(), y = read();
      if (c == 'c') swap(pc[x],pc[y]);
      else if (c == 'r') swap(pr[x],pr[y]);
      else printf("%d\n",a[pr[x]][pc[y]]);
   }
   return 0;
}
