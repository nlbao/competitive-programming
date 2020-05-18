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

const int MAX_N = 1000004;
const ll MODUN = 10000009;

char s[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("RRECIPE.in", "r", stdin);
   freopen("RRECIPE.out", "w", stdout);
#endif
   int nTest = read();
   rep(id,nTest) {
      scanf("%s",&s);
      int n = strlen(s), res = 1;
      rep(i,n) {
         int j = n-1-i;
         if (j < i) break;
         if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
            res = 0;
            break;
         }
         if (s[i] == '?' && s[j] == '?') res = (res*26)%MODUN;
      }
      printf("%d\n",res);
   }

   return 0;
}
