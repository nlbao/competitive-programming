#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 110;
const int MAX_M = 9;
const int MAX_P = 20000;
const ll MODUN = 1000000007;

int p3[MAX_M];
ll f[MAX_N][MAX_P];
VI a[MAX_P];
int e[1<<MAX_M][MAX_P];
bool chk[MAX_P][1<<8];

int encode(int j, int k, int m) {
   int r = 0;
   fab(i, 0, m-1)
      if ((j>>i)&1 != 0) {
         int x = 0;
         if (i > 0) x += (j>>(i-1))&1;
         if (i < m-1) x += (j>>(i+1))&1;
         if (a[k][i] != 0) ++x;
         if (x%2 == 0) x = 2;
         else x = 1;
         r += x*p3[i];
      }
   return r;
}

bool check(int x, int y, int m) {
   fab(i, 0, m-1)
      if (a[x][i] > 0)
         if ((a[x][i]+((y>>i)&1))%2 == 1) return false;
   return true;
}

void init(int m) {
   p3[0] = 1;
   fab(i, 1, MAX_M) p3[i] = p3[i-1]*3;
   fab(i, 0, MAX_P) a[i].clear();
   fab(i, 0, p3[m]-1) {
      int x = i;
      while (x > 0) {
         a[i].pb(x%3);
         x /= 3;
      }
      while (a[i].size() < m) a[i].pb(0);
   }
   fab(j, 0, (1<<m)-1)
      fab(k, 0, p3[m]-1) {
         e[j][k] = encode(j, k, m);
         chk[k][j] = check(k, j, m);
      }
}

class DengklekPaintingSquares {
   public:
   int numSolutions(int n, int m) {
      init(m);
      fill(f, 0);
      fab(j, 0, (1<<m)-1)
         f[1][e[j][0]] = 1;
      fab(i, 2, n) {
         fab(j, 0, (1<<m)-1) {
            fab(k, 0, p3[m]-1) {
               int kk = e[j][k];
               bool c1, c2 = true;
               c1 = chk[k][j];
               if (i == n) c2 = chk[kk][0];
               if (c1 && c2)
                  f[i][kk] = (f[i][kk]+f[i-1][k])%MODUN;
            }
         }
      }
      ll res = 0;
      fab(i, 0, p3[m]-1)
         if ((n > 1) || (chk[i][0]))
            res = (res+f[n][i])%MODUN;
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = 8; int Arg2 = 778391605; verify_case(3, Arg2, numSolutions(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        DengklekPaintingSquares ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
