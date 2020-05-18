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

char s[MAX_N];

int stack[MAX_N], f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("5C.in", "r", stdin);
   freopen("5C.out", "w", stdout);
#endif
   scanf("%s",&s);
   int n = strlen(s), top = 0;
   fill(f,0);
   rep(i,n)
      if (s[i] == '(') stack[++top] = i;
      else
         if (top > 0 && s[stack[top]] == '(') {
            f[stack[top]] = i;
            --top;
         }
         else stack[++top] = i;

   int len = 0, c = 1;
   ford(i,n-1,0)
      if (f[i] > 0) {
         while (f[i] < n-1 && f[f[i]+1] > 0) f[i] = f[f[i]+1];
         int t = f[i]-i+1;
         if (t > len) {
            len = t;
            c = 1;
         }
         else if (t == len) ++c;
      }
   cout << len << " " << c;
   return 0;
}
