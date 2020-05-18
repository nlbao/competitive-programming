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

const int MAX_N = 410;

int n;
double f[MAX_N];

int main() {
   freopen("1776.in", "r", stdin);
   freopen("1776.out", "w", stdout);
   scanf("%d",&n);
   f[0] = 0;
   foru(i,1,n) {
      f[i] = 0;
      foru(j,1,i)
         f[i] += f[max(j-1,i-j)];//max(f[j],f[i-j-1]);
      f[i] = f[i]/(i*1.0)+10.0;
      //printf("%d %.6f\n",i,f[i]);
   }
   printf("%.6f",f[n-2]);
   return 0;
}
