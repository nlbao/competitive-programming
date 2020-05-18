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

const int MAX_N = 100010;

int n;
int a[MAX_N], l[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

void swap(int &x, int &y) {   int t = x;  x = y;   y = t;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("221C.in", "r", stdin);
   freopen("221C.out", "w", stdout);
#endif
   scanf("%d",&n);
   foru(i,1,n) scanf("%d",&a[i]);
   l[1] = 1;
   foru(i,2,n)
      if (a[i] > a[l[i-1]]) l[i] = i;
      else l[i] = l[i-1];
   ford(i,n,2)
      if (a[i] < a[l[i]]) {
         swap(a[i],a[l[i]]);
         break;
      }
   int f = a[1];
   foru(i,2,n)
      if (f > a[i]) {
         printf("NO");
         return 0;
      }
      else f = a[i];
   printf("YES");
   return 0;
}
