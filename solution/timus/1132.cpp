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

const int MAX_N = 32770;
const int MAX_P = 3520;
const int MAX_F = 54056770;

int nP = 0, nF = 0;
bool ok[MAX_N];
int p[MAX_P], b[MAX_N];
//vector<PI> f[MAX_P];
int f[MAX_F];

int main() {
   freopen("1132.in", "r", stdin);
   freopen("1132.out", "w", stdout);
   fill(ok,true);
   for(ll i = 2; i < MAX_N; ++i)
      if (ok[i]) {
         p[nP++] = i;
         for(ll j = i*i; j < MAX_N; j += i) ok[j] = false;
      }
   cout << nP << endl;

   //fill(turn,0);
   rep(i,MAX_N) b[i] = i*i;
   rep(i,nP) {
      int n = p[i];
      //rep(j,n) c[j].clear();
      //f[i].clear();
      rep(x,n) {
         int r = (b[x])%n;
         ++nF;
         //f[i].pb(mp(r,x));
      }
   }
   cout << nF << endl;
   return 0;
}
