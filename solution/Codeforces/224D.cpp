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

const int MAX_N = 200004;

char s[MAX_N], t[MAX_N];
int l[MAX_N], r[MAX_N];
VI p[40];

int read() {   int x;   scanf("%d",&x);   return x;   }

int num(char x) { return x-'a';  }

bool find(int x, int left, int right) {
   if (left > right) return false;
   int sz = size(p[x]);
   int l = 0, r = sz-1;
   while (l <= r) {
      int mid = (l+r)/2, t = p[x][mid];
      if (t < left) l = mid+1;
      else if (t > right) r = mid-1;
      else return true;
   }
   return false;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("224D.in", "r", stdin);
   freopen("224D.out", "w", stdout);
#endif
   scanf("%s%s",&s,&t);
   int n = strlen(s), m = strlen(t);
   if (n < m) {
      printf("No");
      return 0;
   }

   rep(i,m) p[num(t[i])].pb(i);

   if (s[0] == t[0]) l[0] = 0;
   else l[0] = -1;
   foru(i,1,n-1) {
      l[i] = l[i-1];
      if (l[i] < m-1 && s[i] == t[l[i]+1]) ++l[i];
   }

   if (s[n-1] == t[m-1]) r[n-1] = m-1;
   else  r[n-1] = m;
   ford(i,n-2,0) {
      r[i] = r[i+1];
      if (r[i] > 0 && s[i] == t[r[i]-1]) --r[i];
   }

   rep(i,n) {
      if (find(num(s[i]),r[i],l[i]) == false) {
         printf("No");
         return 0;
      }
   }
   printf("Yes");
   return 0;
}
