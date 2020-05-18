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

const int MAX_N = 22;
const int MAX_M = 22;
const ll BASE = 10007;

int n, m;
char a[MAX_N][MAX_M];
ll b[MAX_N][MAX_M], c[MAX_N][MAX_M];
map <ll, bool> q;

void to_b(int x1, int y1, int x2, int y2) {
   int x = 0;
   foru(i, x1, x2) {
      ++x;
      int y = 0;
      foru(j, y1, y2) {
         b[x][++y] = a[i][j];
      }
   }
}

void print_b(int x, int y) {
   cout << "Print B!!!"<< endl;
   foru(i, 1, x) {
      foru(j, 1, y) cout << b[i][j] << " ";
      cout << endl;
   }
   cout << endl;
}

void rotate_b_90(int x) {
   foru(i, 1, x) {
      int ii = x+1;
      foru(j, 1, x) c[--ii][i] = b[i][j];
   }
   foru(i, 1, x)
      foru(j, 1, x) b[i][j] = c[i][j];
}

void rotate_b_180(int x, int y) {
   int ii = x+1;
   foru(i, 1, x) {
      --ii;
      int jj = y+1;
      foru(j, 1, y) c[ii][--jj] = b[i][j];
   }
   foru(i, 1, x)
      foru(j, 1, y) b[i][j] = c[i][j];
}

ll get_h(int x, int y) {
   ll h = 0;
   foru(i, 1, x)
      foru(j, 1, y)
         h = h*BASE+b[i][j];
   return h;
}

bool check(int x, int y) {
   if (n%x || m%y) return false;
   //if (x != 2 || y != 3) return false;
   q.clear();
   ll v[5];
   rep(i, n/x)
      rep(j, m/y) {
         to_b(i*x+1, j*y+1, (i+1)*x, (j+1)*y);
         //printf("    %d %d %d %d\n", i*x+1, j*y+1, (i+1)*x, (j+1)*y);
         if (x == y) {
            rep(k, 4) {
               rotate_b_90(x);
               //print_b(x, y);
               v[k] = get_h(x, y);
               if (q.find(v[k]) != q.end()) return false;
            }
            rep(k, 4) q[v[k]] = true;
         }
         else {
            rep(k, 2) {
               rotate_b_180(x, y);
               //print_b(x, y);
               v[k] = get_h(x, y);
               if (q.find(v[k]) != q.end()) return false;
            }
            rep(k, 2) q[v[k]] = true;
         }
      }
   return true;
}

int main() {
   freopen("54B.in", "r", stdin);
   freopen("54B.out", "w", stdout);
   cin >> n >> m;
   foru(i, 1, n)
      foru(j, 1, m) cin >> a[i][j];

   int res = 0, x = n, y = m;
   foru(i, 1, n) {
      foru(j, 1, m)
         if (check(i, j)) {
            //cout << "OK " << i << " " << j << endl;
            ++res;
            if (i*j < x*y) {
               x = i;
               y = j;
            }
         }
   }
   printf("%d\n%d %d", res, x, y);
   return 0;
}
