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

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100;

class CarolsSinging {
   public:
   int choose(vector <string> lyrics) {
      int n = lyrics.size();
      int m = lyrics[0].size();
      vector<int> e[MAX_N];
      fab(i, 0, n-1)
         fab(j, 0, m-1)
            if (lyrics[i][j] == 'Y')
               e[j].pb(i);
      int res = m;
      fab(i, 1, (1<<m)-1) {
         bool ok[MAX_N] = {false};
         int c = 0, d = 0;
         fab(j, 0, m-1)
            if ((i>>j)&1 == 1) {
               ++d;
               fab(k, 0, int(e[j].size())-1)
                  if (!ok[e[j][k]]) {
                     ok[e[j][k]] = true;
                     ++c;
                  }
            }
         if (c == n) res = min(res, d);
      }
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, choose(Arg0)); }
	void test_case_1() { string Arr0[] = {"YN","YY","YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, choose(Arg0)); }
	void test_case_2() { string Arr0[] = {"YNN","YNY","YNY","NYY","NYY","NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, choose(Arg0)); }
	void test_case_3() { string Arr0[] = {"YNNYYY","YYNYYY","YNNYYN","NYYNNN","YYYNNN","YYYNNY","NYYYYY","NYNYYY","NNNNYY",
 "YYYYYY","YNNNNN","YYYYNY","YYNNNN","NNYYYN","NNNNYY","YYYNNN","NYNNYN","YNNYYN",
 "YYNNNY","NYYNNY","NNYYYN","YNYYYN","NNNYNY","YYYYNN","YYNYNN","NYYNYY","YYNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, choose(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        CarolsSinging ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
