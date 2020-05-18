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

const int MAX_N = 5000004;
const ll MODUN = 1000000007;

bool ok[MAX_N];
ll res[MAX_N];
char s[20];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("PPERM.in", "r", stdin);
   freopen("PPERM.out", "w", stdout);
#endif
   fill(ok,true);
   for(int i = 4; i < MAX_N; i += 2) ok[i] = false;
   for(int i = 3; i*i < MAX_N; i += 2)
      if (ok[i])
         for(int j = i*i; j < MAX_N; j += i) ok[j] = false;

   ll c = 1;
   res[1] = 1;
   foru(i,2,MAX_N-1) {
      if (ok[i]) ++c;
      res[i] = (res[i-1]*c)%MODUN;
   }

   int nTest = read();
   rep(id,nTest) {
      int n;
      scanf("%d",&n);
      printf("%d\n",int(res[n]));
   }
   return 0;
}
