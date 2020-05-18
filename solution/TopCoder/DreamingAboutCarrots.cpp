#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std ; 

class DreamingAboutCarrots {
    public:
    int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
        if ((x1 == x2) && (y1 == y2)) return 0;
        if ((x1 == x2) || (y1 == y2)) return (abs(x1-x2)+abs(y1-y2)-1);
        int res = 0;
        for (int i=min(x1,x2)+1; i < max(x1,x2); ++i)
            if (abs((y1-y2)*(i-x1))%abs(x1-x2) == 0) ++res;
        return res;   
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 5; int Arg3 = 5; int Arg4 = 3; verify_case(0, Arg4, carrotsBetweenCarrots(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; verify_case(1, Arg4, carrotsBetweenCarrots(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 48; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; verify_case(2, Arg4, carrotsBetweenCarrots(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 42; int Arg3 = 36; int Arg4 = 5; verify_case(3, Arg4, carrotsBetweenCarrots(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        DreamingAboutCarrots ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
        } 
    // END CUT HERE 
