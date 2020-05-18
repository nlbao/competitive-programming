#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std ; 

typedef long long llint;

class MagicDiamonds {
    public:
        
    bool is_prime(llint n) {
        if ( (n == 2) || (n == 3) ) return true;
        if ( (n == 1) || (n%2 == 0) ) return false;
        for ( llint i = 2; i <= round(sqrt(n)); ++i )
            if ( n%i == 0 ) return false;
        return true;
    }
    
    llint minimalTransfer(llint n) {
        if ( (n == 2) || (n == 3) ) return n;
        if ( is_prime(n) ) return 2;
        else return 1;   
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; verify_case(0, Arg1, minimalTransfer(Arg0)); }
	void test_case_1() { long long Arg0 = 4294967297LL; long long Arg1 = 1LL; verify_case(1, Arg1, minimalTransfer(Arg0)); }
	void test_case_2() { long long Arg0 = 2147483647LL; long long Arg1 = 2LL; verify_case(2, Arg1, minimalTransfer(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(3, Arg1, minimalTransfer(Arg0)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        MagicDiamonds ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
        } 
    // END CUT HERE 
