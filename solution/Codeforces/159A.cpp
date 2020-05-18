#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int oo = 1000000000;
const int MAX_N = 2007;

int nNames = 0;
string names[MAX_N];
bool ok[MAX_N][MAX_N];
int f[MAX_N][MAX_N];

int find(string s) {
   int i = 1;
   while ((i <= nNames) && (names[i] != s)) ++i;
   names[i] = s;
   nNames = max(nNames, i);
   return i;
}

int main() {
   freopen("159A.in", "r", stdin);
   freopen("159A.out", "w", stdout);
   int n, d;
   string s, t;
   cin >> n >> d;
   fill(ok, false);
   fab(i, 1, 2*n) {
      names[i] = "";
      fab(j, 1, 2*n) f[i][j] = oo;
   }

   getline(cin, s);
   fab(i, 1, n) {
      getline(cin, s);
      t.clear();  int p = 0;
      while ((p < s.size()) && (s[p] != ' ')) {
         t += s[p];
         ++p;
      }
      int j = find(t);

      t.clear();  ++p;
      while ((p < s.size()) && (s[p] != ' ')) {
         t += s[p];
         ++p;
      }
      int k = find(t);

      f[j][k] = 0;   ++p;
      while ((p < s.size()) && (s[p] != ' ')) {
         f[j][k] = f[j][k]*10+int(s[p])-int('0');
         ++p;
      }

      int x = f[j][k]-f[k][j];
      if ((x > 0) && (x <= d)) {
         ok[j][k] = true;
         ok[k][j] = true;
      }
   }

   int c = 0;
   fab(i, 1, 2*n)
      fab(j, i+1, 2*n)
         c += int(ok[i][j]);
   cout << c << endl;
   fab(i, 1, 2*n)
      fab(j, i+1, 2*n)
         if (ok[i][j])
            cout << names[i] << " " << names[j] << endl;
   return 0;
}


