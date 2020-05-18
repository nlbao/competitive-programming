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

#define foru(i,a,b) for(int i = (a); i <= (b); ++i)
#define ford(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second



class RandomColoringDiv2 {
   public:
   int getCount(int maxR, int maxG, int maxB, int R, int G, int B, int d1, int d2) {
      ll res = 0;
      foru(i, 0, maxR-1)
         if (abs(i-R) <= d2)
            foru(j, 0, maxG-1)
               if (abs(j-G) <= d2)
                  foru(k, 0, maxB-1)
                     if (abs(k-B) <= d2)
                        if ((abs(i-R) >= d1) || (abs(j-G) >= d1) || (abs(k-B) >= d1))
                           ++res;
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 3; verify_case(0, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 3; int Arg7 = 3; int Arg8 = 4; verify_case(1, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 2; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 5; int Arg7 = 5; int Arg8 = 0; verify_case(2, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; int Arg4 = 2; int Arg5 = 3; int Arg6 = 0; int Arg7 = 10; int Arg8 = 540; verify_case(3, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 9; int Arg2 = 10; int Arg3 = 1; int Arg4 = 2; int Arg5 = 3; int Arg6 = 4; int Arg7 = 10; int Arg8 = 330; verify_case(4, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 49; int Arg1 = 59; int Arg2 = 53; int Arg3 = 12; int Arg4 = 23; int Arg5 = 13; int Arg6 = 11; int Arg7 = 22; int Arg8 = 47439; verify_case(5, Arg8, getCount(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        RandomColoringDiv2 ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
