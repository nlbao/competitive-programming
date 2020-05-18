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

const int MAX_N = 1000007;
const int MAX_P = 1007;

int nP, nC;
bool is_prime[MAX_N];
int p[MAX_P];
PI c[MAX_N];

void to_prime(int n, int v) {
   for(int i = 0; i < nP && p[i]*p[i] <= n; ++i)
      if (n%p[i] == 0) {
         int s = 0;
         while (n%p[i] == 0) {
            n /= p[i];
            s += v;
         }
         c[nC].fr = p[i];
         c[nC++].sc = s;
      }
   if (n > 1) {
      c[nC].fr = n;
      c[nC++].sc = v;
   }
}

int main() {
   freopen("ANARC09C.in", "r", stdin);
   freopen("ANARC09C.out", "w", stdout);
   nP = 0;
   fill(is_prime,true);
   for(int i = 2; i*i < MAX_N; ++i)
      if (is_prime[i]) {
         p[nP++] = i;
         for(int j = i*i; j < MAX_N; j += i)
            is_prime[j] = false;
      }

   for(int id = 1; ; ++id) {
      int a, b;
      scanf("%d%d",&a,&b);
      if (a == 0) break;
      nC = 0;
      to_prime(a,1);
      to_prime(b,-1);

      //cout << a << " " << b << endl;
      //rep(i, nC) cout << c[i].fr << " " << c[i].sc << endl;


      sort(c,c+nC);
      int r1 = 0, r2 = 0;
      for(int i = 0, j = 0; i < nC; i = j) {
         int s = 0;
         while (j < nC && c[j].fr == c[i].fr) s += c[j++].sc;
         ++r1;
         r2 += abs(s);
      }
      printf("%d. %d:%d\n",id,r1,r2);
   }
   return 0;
}
