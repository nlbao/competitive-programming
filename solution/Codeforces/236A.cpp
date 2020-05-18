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

int read() {   int x;   scanf("%d",&x);   return x;   }

int main() {
#ifndef ONLINE_JUDGE
   freopen("236A.in", "r", stdin);
   freopen("236A.out", "w", stdout);
#endif
   char s[200];
   scanf("%s",&s);
   int n = strlen(s);
   bool ok[30];
   fill(ok,false);
   rep(i,n) ok[s[i]-'a'] = true;
   int c = 0;
   rep(i,30) if (ok[i]) ++c;
   if (c%2 == 0) printf("CHAT WITH HER!");
   else printf("IGNORE HIM!");
   return 0;
}
