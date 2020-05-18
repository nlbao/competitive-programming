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

const int MAX_N = 107;

int n;
int a[MAX_N], b[MAX_N];

bool is_unlucky() {
   bool un = true;
   fab(i, 0, n-1)
      if (a[i] >= b[i]) un = false;
   if (un) return true;
   un = true;
   fba(i, n-1, 0)
      if (a[i] <= b[i]) un = false;
   return un;
}

int main() {
   freopen("160B.in", "r", stdin);
   freopen("160B.out", "w", stdout);
   cin >> n;
   string s;
   getline(cin, s);
   getline(cin, s);

   fab(i, 0, n-1) a[i] = int(s[i])-int('0');
   fab(i, n, 2*n-1) b[i-n] = int(s[i])-int('0');
   sort(a, a+n);
   sort(b, b+n);

   if (is_unlucky()) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}


