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
typedef unsigned long long ull;
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

const int MAX_N = 100005;

char s[MAX_N];
pair<ll,int> h[MAX_N];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int read() {   int x;   scanf("%d",&x);   return x;   }

bool is_num(char x) {   return (x >= '0' && x <= '9');   }

int num(char x)   {  return x-'0';  }

bool ok(int pos) {
   foru(i,1,10)
      if (i != 3 && i != 6 && !is_num(s[pos+i-1])) return false;
   int d = num(s[pos])*10 + num(s[pos+1]);
   int m = num(s[pos+3])*10 + num(s[pos+4]);
   int y = 0;
   foru(i,pos+6,pos+9) y = y*10 + num(s[i]);
   if (y < 2013 || y > 2015) return false;
   if (m < 1 || m > 12) return false;
   if (d > month[m]) return false;
   return true;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("260B.in", "r", stdin);
   freopen("260B.out", "w", stdout);
#endif
   scanf("%s",&s);
   int n = strlen(s);
   int m = n-10+1;
   rep(i,m) {
      h[i] = mp(0,i);
      foru(j,i,i+9)
         h[i].fr = h[i].fr*10007LL + ll(s[j]);
   }

   sort(h,h+m);
   int res = -1, pos = -1, i = 0;
   while (i < m) {
      int j = i;
      while (j < m && h[j].fr == h[i].fr) ++j;
      if (j-i > res && ok(h[i].sc)) {
         res = j-i;
         pos = h[i].sc;
      }
      i = j;
   }
   foru(i,pos,pos+9) cout << s[i];
   return 0;
}
