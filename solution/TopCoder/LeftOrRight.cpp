#include <sstream>
#include <iostream>
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

const int MAX_N = 100;
const int oo = 1000000000;

int mmax(int x, int y) {
   if (abs(x) > abs(y)) return x;
   return y;
}

class LeftOrRight {
   public:
   int maxDistance(string s) {
      int n = s.size(), res = 1;
      int f[MAX_N][2];
      f[0][0] = -1;   f[0][1] = 1;
      if (s[0] == 'L') f[0][1] = oo;
      else if (s[0] == 'R') f[0][0] = oo;
      fab(i, 1, n-1) {
         //f[i][0] = mmax(f[i-1][0]-1, f[i-1][1]-1);
         //f[i][1] = mmax(f[i-1][1]+1, f[i-1][0]+1);
         f[i][0] = f[i][1] = 0;
         if (s[i] != 'L') {
            if (s[i] =

         }
         if (s[i] != 'R') {

         }
         if (f[i][0] < oo) res = max(res, abs(f[i][0]));
         if (f[i][1] < oo) res = max(res, abs(f[i][1]));
      }
      cout << f[3][1] << endl;
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLLRLRRR"; int Arg1 = 3; verify_case(0, Arg1, maxDistance(Arg0)); }
	void test_case_1() { string Arg0 = "R???L"; int Arg1 = 4; verify_case(1, Arg1, maxDistance(Arg0)); }
	void test_case_2() { string Arg0 = "??????"; int Arg1 = 6; verify_case(2, Arg1, maxDistance(Arg0)); }
	void test_case_3() { string Arg0 = "LL???RRRRRRR???"; int Arg1 = 11; verify_case(3, Arg1, maxDistance(Arg0)); }
	void test_case_4() { string Arg0 = "L?L?"; int Arg1 = 4; verify_case(4, Arg1, maxDistance(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        LeftOrRight ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
