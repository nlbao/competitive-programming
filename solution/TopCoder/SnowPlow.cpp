#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100;

class SnowPlow {
   public:
   int solve(vector <string> roads) {
      int n = roads[0].size(), c = 0, res = 0;
      int d[MAX_N][MAX_N];
      fab(i, 0, n-1)
         fab(j, 0, n-1) {
            d[i][j] = int(roads[i][j])-int('0');
            c += d[i][j];
         }

      VI stack;
      stack.pb(0);
      while (stack.size() > 0) {
         int u = stack[stack.size()];
         int ok = false;
         fab(v, 0, n-1)
            if (d[u][v] > 0) {
               stack.pb(v);
               --d[u][v];
               ++res;
            }
         if (!ok) stack.pop_back();
      }

      if (res < c) return -1;
      else return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"010000",
 "101000",
 "010100",
 "001010",
 "000101",
 "000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {"010000",
 "101000",
 "010100",
 "001020",
 "000201",
 "000010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {"031415",
 "300000",
 "100000",
 "400000",
 "100000",
 "500000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {"0100",
 "1000",
 "0001",
 "0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arr0[] = {"0101",
 "1001",
 "0000",
 "1100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        SnowPlow ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
